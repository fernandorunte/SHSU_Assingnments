#chap7_2

import random
index = 0;
int1 = random.randint(0,9)
int2 = random.randint(0,9)
int3 = random.randint(0,9)
int4 = random.randint(0,9)
int5 = random.randint(0,9)
int6 = random.randint(0,9)
int7 = random.randint(0,9)

randomlist = [0] * 7

randomlist[0] = int1
randomlist[1] = int2
randomlist[2] = int3
randomlist[3] = int4
randomlist[4] = int5 
randomlist[5] = int6
randomlist[6] = int7

while index < len(randomlist):
    print(randomlist[index])
    index += 1
