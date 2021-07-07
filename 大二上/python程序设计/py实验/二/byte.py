# coding=UTF-8
#!/usr/bin/env python3

import sys

sum1=int(0)
j=0

for i in range(0,6):
    print("当整数为：%d时"%sum1)
    print("此时整数所占字节数是：%d"%sys.getsizeof(sum1))
    print("此时该数的类型是：%s"%type(sum1))
    j+=30
    sum1=(2 << j)
    print("当每增加30位宽,该数是%d时"%sum1)
    print("此时整数所占字节数是：%d"%sys.getsizeof(sum1))
    print("-------------------")
