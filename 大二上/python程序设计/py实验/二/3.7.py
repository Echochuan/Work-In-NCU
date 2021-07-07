# coding=UTF-8
#!/usr/bin/env python3

def sum():
    S = 1.000000
    n = int(input("enter n:"))
    a = 1

    if n==1:
        print("S = 1")

    else:
        N = int((n+1)/2)

        for i in range(1,N):
            j = 2.0*i+1
            if a%2!=0:
                S = S + (1.0/j)
            else:
                S = S - (1.0/j)
            a+=1
        print("The result is:S = %.6f"%S)

sum()
