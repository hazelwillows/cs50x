#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int r = image[i][j].rgbtRed;
            int g = image[i][j].rgbtGreen;
            int b = image[i][j].rgbtBlue;
            int new = (r+g+b)/3;
            image[i][j].rgbtRed = new;
            image[i][j].rgbtGreen = new;
            image[i][j].rgbtBlue = new;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < floor(height/2); i++)
    {
        for (int j = 0; j < width; j++)
        {

            RGBTRIPLE top = image[i][j];
            RGBTRIPLE bottom = image[height-i][j];
            image[i][j] = bottom;
            image[height-i][j] = top;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i != 0 && i != height-1 && j != 0 && j != width-1)
            {
                int newr = 0;
                int newb = 0;
                int newg = 0;
                for (int count = -1; count <=1; count++)
                {
                    int widthc = j+count;
                    for (int heightc = -1; heightc <=1; heightc++)
                    {
                        newr += image[i+heightc][widthc].rgbtRed;
                        newg += image[i+heightc][widthc].rgbtGreen;
                        newb += image[i+heightc][widthc].rgbtBlue;
                    }
                }
                image[i][j].rgbtRed = newr/9;
                image[i][j].rgbtGreen = newg/9;
                image[i][j].rgbtBlue = newb/9;
            }
            else if (i == 0 && j != 0)
            {
                int newr = 0;
                int newb = 0;
                int newg = 0;
                for (int count = -1; count <=1; count++)
                {
                    int widthc = j+count;
                    for (int heightc = 0; heightc <=1; heightc++)
                    {
                        newr += image[i+heightc][widthc].rgbtRed;
                        newg += image[i+heightc][widthc].rgbtGreen;
                        newb += image[i+heightc][widthc].rgbtBlue;
                    }
                }
                image[i][j].rgbtRed = newr/6;
                image[i][j].rgbtGreen = newg/6;
                image[i][j].rgbtBlue = newb/6;
            }
            else if (i == height-1 && j != 0)
            {
                int newr = 0;
                int newb = 0;
                int newg = 0;
                for (int count = -1; count <=1; count++)
                {
                    int widthc = j+count;
                    for (int heightc = -1; heightc <=0; heightc++)
                    {
                        newr += image[i+heightc][widthc].rgbtRed;
                        newg += image[i+heightc][widthc].rgbtGreen;
                        newb += image[i+heightc][widthc].rgbtBlue;
                    }
                }
                image[i][j].rgbtRed = newr/6;
                image[i][j].rgbtGreen = newg/6;
                image[i][j].rgbtBlue = newb/6;
            }
            else if (i != 0 && j == 0)
            {
                int newr = 0;
                int newb = 0;
                int newg = 0;
                for (int count = 0; count <=1; count++)
                {
                    int widthc = j+count;
                    for (int heightc = -1; heightc <=1; heightc++)
                    {
                        newr += image[i+heightc][widthc].rgbtRed;
                        newg += image[i+heightc][widthc].rgbtGreen;
                        newb += image[i+heightc][widthc].rgbtBlue;
                    }
                }
                image[i][j].rgbtRed = newr/6;
                image[i][j].rgbtGreen = newg/6;
                image[i][j].rgbtBlue = newb/6;
            }
            else if (i != 0 && j == width-1)
            {
                int newr = 0;
                int newb = 0;
                int newg = 0;
                for (int count = -1; count <=0; count++)
                {
                    int widthc = j+count;
                    for (int heightc = -1; heightc <=1; heightc++)
                    {
                        newr += image[i+heightc][widthc].rgbtRed;
                        newg += image[i+heightc][widthc].rgbtGreen;
                        newb += image[i+heightc][widthc].rgbtBlue;
                    }
                }
                image[i][j].rgbtRed = newr/6;
                image[i][j].rgbtGreen = newg/6;
                image[i][j].rgbtBlue = newb/6;
            }
            else if (i == 0 && j == 0)
            {
                int newr = 0;
                int newb = 0;
                int newg = 0;
                for (int count = 0; count <=1; count++)
                {
                    int widthc = j+count;
                    for (int heightc = 0; heightc <=1; heightc++)
                    {
                        newr += image[i+heightc][widthc].rgbtRed;
                        newg += image[i+heightc][widthc].rgbtGreen;
                        newb += image[i+heightc][widthc].rgbtBlue;
                    }
                }
                image[i][j].rgbtRed = newr/4;
                image[i][j].rgbtGreen = newg/4;
                image[i][j].rgbtBlue = newb/4;
            }
            else if (i == height-1 && j == 0)
            {
                int newr = 0;
                int newb = 0;
                int newg = 0;
                for (int count = 0; count <=1; count++)
                {
                    int widthc = j+count;
                    for (int heightc = -1; heightc <=0; heightc++)
                    {
                        newr += image[i+heightc][widthc].rgbtRed;
                        newg += image[i+heightc][widthc].rgbtGreen;
                        newb += image[i+heightc][widthc].rgbtBlue;
                    }
                }
                image[i][j].rgbtRed = newr/4;
                image[i][j].rgbtGreen = newg/4;
                image[i][j].rgbtBlue = newb/4;
            }
            else if (i == 0 && j == height-1)
            {
                int newr = 0;
                int newb = 0;
                int newg = 0;
                for (int count = -1; count <=0; count++)
                {
                    int widthc = j+count;
                    for (int heightc = 0; heightc <=1; heightc++)
                    {
                        newr += image[i+heightc][widthc].rgbtRed;
                        newg += image[i+heightc][widthc].rgbtGreen;
                        newb += image[i+heightc][widthc].rgbtBlue;
                    }
                }
                image[i][j].rgbtRed = newr/4;
                image[i][j].rgbtGreen = newg/4;
                image[i][j].rgbtBlue = newb/4;
            }
            else if (i == height-1 && j == height-1)
            {
                int newr = 0;
                int newb = 0;
                int newg = 0;
                for (int count = -1; count <=0; count++)
                {
                    int widthc = j+count;
                    for (int heightc = -1; heightc <=0; heightc++)
                    {
                        newr += image[i+heightc][widthc].rgbtRed;
                        newg += image[i+heightc][widthc].rgbtGreen;
                        newb += image[i+heightc][widthc].rgbtBlue;
                    }
                }
                image[i][j].rgbtRed = newr/4;
                image[i][j].rgbtGreen = newg/4;
                image[i][j].rgbtBlue = newb/4;
            }
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i != 0 && i != height-1 && j != 0 && j != width-1)
            {
                double newrx = 0;
                double newgx = 0;
                double newbx = 0;
                double newry = 0;
                double newgy = 0;
                double newby = 0;
                double newr = 0;
                double newg = 0;
                double newb = 0;

                newrx = image[i-1][j-1].rgbtRed*-1 + image[i][j-1].rgbtRed*-2 + image[i+1][j-1].rgbtRed*-1 + image[i-1][j+1].rgbtRed*1 + image[i][j+1].rgbtRed*2 + image[i+1][j+1].rgbtRed*1;
                newgx = image[i-1][j-1].rgbtGreen*-1 + image[i][j-1].rgbtGreen*-2 + image[i+1][j-1].rgbtGreen*-1 + image[i-1][j+1].rgbtGreen*1 + image[i][j+1].rgbtGreen*2 + image[i+1][j+1].rgbtGreen*1;
                newbx = image[i-1][j-1].rgbtBlue*-1 + image[i][j-1].rgbtBlue*-2 + image[i+1][j-1].rgbtBlue*-1 + image[i-1][j+1].rgbtBlue*1 + image[i][j+1].rgbtBlue*2 + image[i+1][j+1].rgbtBlue*1;

                newry = image[i-1][j-1].rgbtRed*-1 + image[i+1][j-1].rgbtRed*1;
                newry = image[i-1][j].rgbtRed*-2 + image[i+1][j].rgbtRed*2;
                newry = image[i-1][j+1].rgbtRed*-1 + image[i+1][j+1].rgbtRed*1;
                newgy = image[i-1][j-1].rgbtGreen*-1 + image[i+1][j-1].rgbtGreen*1;
                newgy = image[i-1][j].rgbtGreen*-2 + image[i+1][j].rgbtGreen*2;
                newgy = image[i-1][j+1].rgbtGreen*-1 + image[i+1][j+1].rgbtGreen*1;
                newby = image[i-1][j-1].rgbtBlue*-1 + image[i+1][j-1].rgbtBlue*1;
                newby = image[i-1][j].rgbtBlue*-2 + image[i+1][j].rgbtBlue*2;
                newby = image[i-1][j+1].rgbtBlue*-1 + image[i+1][j+1].rgbtBlue*1;

                newr = sqrt(newry*newry + newrx*newrx);
                newg = sqrt(newgy*newgy + newgx*newgx);
                newb = sqrt(newby*newby + newbx*newbx);

                if (newr > 255)
                {
                    newr = 255;
                }
                if (newb > 255)
                {
                    newb = 255;
                }
                if (newg > 255)
                {
                    newg = 255;
                }

                image[i][j].rgbtRed = round(newr);
                image[i][j].rgbtGreen = round(newg);
                image[i][j].rgbtBlue = round(newb);
            }
            else
            {
                image[i][j].rgbtRed = 0;
                image[i][j].rgbtGreen = 0;
                image[i][j].rgbtBlue = 0;
            }
        }
    }
    return;
}