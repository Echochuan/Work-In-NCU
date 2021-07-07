# coding=UTF-8
#!/usr/bin/env python3

import math

num_max = 0
n = int(input("please enter n :"))

for i in range (0, n+1):
    if (i % 17 == 0):
        num_max = i

print("the biggest is ", num_max)