# coding=UTF-8
#!/usr/bin/env python3


import random

words = ["apple", "banana", "orange", "pitaya", "lychee", "cherry", "watermallon"]
word = list(words[random.randint(0, len(words) - 1)])
ranList = random.sample(range(0, len(word)), len(word))
tips = list()

for i in range(len(word)):
    tips.append("_")
# 提示两个字母
tips[ranList[0]] = word[ranList[0]]
tips[ranList[1]] = word[ranList[1]]

def showtips():
    for i in tips:
        print(i, end=" "),
    print("\n")

def Menu():
    print("------------------------------")
    print("输入quit退出游戏")

    while True:
        print("prompt：guess the word")
        showtips()
        guessWord = input("guess: ")
        if guessWord == ''.join(word):
            print("You guess right!")
            break
        
        elif guessWord == "quit":
            break

        else:
            print("You guess wrong!")
            continue

Menu()


if __name__=='__menu__':
    Menu()
