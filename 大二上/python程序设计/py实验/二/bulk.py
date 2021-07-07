# coding=UTF-8
#!/usr/bin/env python3

print("让我们开始计算一个长方体的体积和面积")
length = float(input("它的长是"))
width = float(input("它的宽是"))
height = float(input("它的高是"))

volume = length * width * height
square = 2 * (length * width + length * height + width * height)

print('the volume is : ', volume)
print('the square is : ', square)