# coding=UTF-8
#!/usr/bin/env python3

import math

n = int(input("Please input the n :"))

for X in range(1, n+1):
    Y = X*1.0
    m = X
    noun = 5

    for i in range(0, 6):
        noun = (noun + X*1.0/noun)*1.0/2
    print(m, "%.6f" % noun)

    Y = math.sqrt(Y)
    print("if you use sqrt()", m, "%.6f" % Y)
