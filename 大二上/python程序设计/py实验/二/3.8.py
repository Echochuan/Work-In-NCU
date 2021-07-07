# coding=UTF-8
#!/usr/bin/env python3

import random


def calcu():
    max = 1
    min = 1
    a = random.randint(1, 100)
    b = random.randint(1, 100)
    c = random.randint(1, 100)
    print("a = ", a, "b = ", b, "c = ", c)

    for i in range(1, a*b*c+1):
        min = i
        if min % a == 0 and min % b == 0 and min % c == 0:
            print("The min_multiple is:", min)
            break

    max = a*b*c

    for i in range(0, a*b*c):
        if a % max == 0 and b % max == 0 and c % max == 0:
            print("The max_divisor is:", max)
            break
        max -= 1


calcu()
