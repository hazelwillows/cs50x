import re
import sys
import math

card = str(input("Card number: "))
for i in card:
    if i not in ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']:
        print("INVALID")
        sys.exit(1)

if len(card) not in [13, 15, 16]:
    print("INVALID")
    sys.exit(1)

x = []
later = []
for i in card:
    i = int(i)
    x.append(i)
    later.append(i)

count = []

for i in range(1, math.floor(len(x)/2)+1):
    i = -i*2
    count.append(2*x[i]) # WHAT ON EARTH IS WRONG WITH THIS LINE OF CODE?!?!?!?!?
    later.remove(x[i])

sum = 0
split = []

for i in count:
    length = str(i)
    for j in length:
        j = int(j)
        split.append(j)

for i in split:
    sum += i

for i in later:
    sum += i

ans = sum%10

if ans == 0:
    if x[0] == 4:
        print("VISA")
    elif x[0] == 5:
        if x[1] in [1, 2, 3, 4, 5]:
            print("MAST")
    elif x[0] == 3:
        if x[1] in [4, 7]:
            print("AMEX")
    else:
        print("Unidentified")
else:
    print("INVALID")