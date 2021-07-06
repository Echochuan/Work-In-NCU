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
bool isFull(BiTree * T){
    struct Node {
        BiTree *tree;
        int deep;           //深度
    };

    Node q[100];            //使用数组实现简单的队列

    if (T == NULL) return true;
    int rear = 0, front = 0;
    q[rear].tree = T;
    q[rear].deep = 0;

    int dMax = 0;           //表示最大深度
    int num = 0;            //表示结点个数

    while (rear >= front) {
        if (q[front].tree != NULL) {
            num++;
            q[++rear].tree = q[front].tree->Lchild;     //入队
            q[rear].deep = q[front].deep + 1;
            q[++rear].tree = q[front].tree -> Rchild;   //入队
            q[rear].deep = q[front].deep + 1;
            if (dMax < q[rear].deep)
                dMax = q[rear].deep;
        }
        front++;
    }
    cout << "最大深度为 = " << dMax << "  结点个数为 = " << num << endl;
    return 1 << dMax == deep + 1;
}

//主函数
int main() {

}

