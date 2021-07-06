//假设二叉树采用链式存储方式，编写一个程序，判断任意给定的二叉树是否为满二叉树。
//一个满二叉树总结点树等于2的最大深度次方-1。
//最大深度是通过层次遍历求出

#include <iostream>
using namespace std;

//声明二叉树结构
struct BiTree {
    int data;   //数值域
    BiTree *Lchild;
    BiTree *Rchild;     //指针域
};

//设定创建二叉树的函数
void CreateBiTree(BiTree * &T) {
    int d;
    cin >> d;  //输入数据

    //当输入-1时为空结点
    if(d == -1) {
        T = NULL;
    }
    else {
        T = (BiTree *)malloc(sizeof(BiTree));   //使用sizeof计算字节数，使用malloc动态分配内存空间
        T->data = d;             //该节点的数据域为输入的内容
        CreateBiTree(T->Lchild);    //递归创建左子树
        CreateBiTree(T->Rchild);    //递归创建右子树
    }
}


//判断是否为满二叉树
bool isFull(BiTree T){
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
    BiTree T;
    {
    cout << "创建一个树" << endl;
    CreateBiTree(T);
    }

    if(isFull(T)) {
        cout << "满二叉树" << endl;
    }
    else 
        cout << "不是满二叉树" << endl;
        return 0;
}

