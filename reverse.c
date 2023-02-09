#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wav.h"

#define true 1
#define false 0

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }
    char *input = argv[1];

    // Open input file for reading
    FILE *in = fopen(input, "r");
    if (in == NULL)
    {
        printf("Error: please input valid WAV file\n");
        return 1;
    }

    WAVHEADER header;
    fread(&header, 44, 1, in);

    // Use check_format to ensure WAV format
    check_format(header);

    // Open output file for writing
    FILE *out = fopen(argv[2], "w");

    // Write header to file
    fwrite(&header, 44, 1, out);

    // Use get_block_size to calculate size of block
    int blocksize = get_block_size(header);

    // Write reversed audio to file
    const int length = sizeof(in);
    BYTE* c;
    c = (BYTE*)malloc(length+1);
    fseek(in, 0, SEEK_END);
    int i = 0;
    while (fseek(in, -blocksize, SEEK_CUR) == 0)
    {
        fread(&c[i], blocksize, 1, in);
        fseek(in, -blocksize, SEEK_CUR);
        fwrite(&c[i], blocksize, 1, out);
    }

    fclose(in);
    fclose(out);
}

int check_format(WAVHEADER header)
{
    char *format = malloc(5);
    sprintf(format, "%u", header.audioFormat);
    if (strcmp(format, "WAVE") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    free(format);
}

int get_block_size(WAVHEADER header)
{
    char *bpso = malloc(5);
    int bps = sprintf(bpso, "%u", header.byteRate);

    char *cho = malloc(3);
    int ch = sprintf(cho, "%u", header.numChannels);

    int blocksize = bps * ch;
    return blocksize;
    free(bpso);
    free(cho);
}