b=96
for a in range(90,101):
    for c in range(90,101):
        for d in range(90,101):    #给a,c,d限制他们的取值范围
            if (a+b+c==95*3 and b+c+d==94*3 and a-d==3 and (a+b+c+d)%4==0): #根据abc 和 bcd 分别的平均值 ；根据需要整除于4
                if((a>b and b>c and b>d) or (c>b and b>a and b>d)): #a与c之中有一个比b大
                    print(a,b,c,d)     #输出