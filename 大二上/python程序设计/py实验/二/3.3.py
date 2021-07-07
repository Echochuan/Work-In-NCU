# coding=UTF-8
#!/usr/bin/env python3

j=0
for i in range(2000,3001):
    if (i%4==0 and i%100!=0) or (i%100==0 and i%400==0):
        j+=1
        if j%6==0:
            print("%d"%i)
        else:
            print("%d"%i)
