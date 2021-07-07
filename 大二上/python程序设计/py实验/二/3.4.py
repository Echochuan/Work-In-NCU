# coding=UTF-8
#!/usr/bin/env python3

import math

j=0
a=0
for i in range(0,19):

    print("a=%d度"%a)
    print("sin:%.6f"%math.sin(math.pi*a*1.0/180))
    print("cos:%.6f"%math.cos(math.pi*a*1.0/180))
    print("\n")
    a+=5
