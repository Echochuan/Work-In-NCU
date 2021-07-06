//假设二叉树采用链式存储方式，编写一个程序，判断任意给定的二叉树是否为满二叉树。

#include<stdio.h>
#include<stdlib.h>


//声明二叉树结构
typedef struct BiTnode {
    int data;   //数值域
    struct BiTnode *Lchild,*Rchild;     //指针域
}BiTnode,*BiTree;