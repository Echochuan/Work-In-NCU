//假设二叉树采用链式存储方式，编写一个程序，判断任意给定的二叉树是否为满二叉树。

#include <iostream>
using namespace std;

//声明二叉树结构
typedef struct BiTnode {
    int data;   //数值域
    struct BiTnode *Lchild,*Rchild;     //指针域
}BiTnode,*BiTree;

//设定创建二叉树的函数
void CreateBiTree(BiTree &T) {
    char ch;
    char temp;
    cin >> ch;  //输入数据
    temp = getchar();
    if(ch == '#') {
        T = NULL;
    }
    else {
        T = new BiTnode;            //新建一个节点
        T->data = ch;             //该节点的数据域为输入的内容
        CreateBiTree(T->Lchild);    //递归创建左子树
        CreateBiTree(T->Rchild);    //递归创建右子树
    }
}


//判断是否为满二叉树
int isFull(BiTree T){
    //如果左孩子与右孩子同时为空，则该树为满二叉树
    if(T->Lchild == NULL && T->Rchild == NULL ) {
        return 1;
    }
    //如果左孩子与右孩子中有一个为空，而另一个不为空，则不是满二叉树
    else if (T->Lchild == NULL || T->Rchild == NULL) {
        return 0;
    }
    else return 0;
}

//主函数
int main() {
    
}

