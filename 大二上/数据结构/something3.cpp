#include <iostream>
#include <stdlib.h>
#include<queue>

using namespace std;

#define MAX_TREE_SIZE 1250
#define TElemType char
#define Status    int
#define OK        1
#define ERROR    -1
typedef struct BiTNode{
    TElemType data;
    int  Ltag,Rtag;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
typedef TElemType SqBiTree[MAX_TREE_SIZE];
char S[100]="ABC##DE##F##G##";
char SS[100]="GY#KL##M##X##";
int k=0,kk=0;
BiTNode* pre = NULL;

Status CreateBiTree(BiTree &T)//先序创建二叉树
{
    char ch;
    cin>>ch;
    if(ch=='#') T=NULL;
    else{
        T=new BiTNode;
        T->data=ch;
        T->Ltag = 0;
        T->Rtag = 0;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return OK;
}

Status CreateRBiTree(BiTree &T)//随机生成二叉树
{
    char ch;
    ch=S[k];
    if(ch=='#') T=NULL,k++;
    else{
        T=new BiTNode;
        T->data=ch;
        k++;
        T->Ltag = 0;
        T->Rtag = 0;
        CreateRBiTree(T->lchild);
        CreateRBiTree(T->rchild);
    }
    return k;
}

Status CreateRBiTree2(BiTree &T)//随机生成二叉树
{
    char ch;
    ch=SS[kk];
    if(ch=='#') T=NULL,kk++;
    else{
        T=new BiTNode;
        T->data=ch;
        kk++;
        T->Ltag = 0;
        T->Rtag = 0;
        CreateRBiTree2(T->lchild);
        CreateRBiTree2(T->rchild);
    }
    return kk;
}

Status NodeCount(BiTree T)//统计二叉树中结点的个数
{
    if(T==NULL) return 0;
    else return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
}

Status LeafCount(BiTree T)//统计二叉树中叶子结点的个数
{
    if(!T) return 0;
    if(!T->lchild &&!T->rchild){//二叉树左子树和右子树皆为空,说明该二叉树根节点为叶子节点,加1.
        return 1;
    }
    else{
        return LeafCount(T->lchild)+LeafCount(T->rchild);
    }
}

Status Depth(BiTree T)//树的深度
{
    if(T==NULL)
        return 0;
    else
    {
        int m=Depth(T->lchild);
        int n=Depth(T->rchild);
        if(m>n) return (m+1);
        else return (n+1);
    }
}

void ExChangeTree(BiTree &T)//使用递归算法进行左右结点转换
{
    BiTree temp;
    if(T!=NULL){//判断T是否为空，非空进行转换，否则不转换
        temp=T->lchild;
        T->lchild=T->rchild;//直接交换节点地址
        T->rchild=temp;
        ExChangeTree(T->lchild);
        ExChangeTree(T->rchild);
    }
}

void PreOrderTraverse(BiTree T)//先序递归遍历
{
    if(T)
    {
        cout<<T->data;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

void InOrderTraverse(BiTree T)//中序递归遍历
{
    if(T)
    {
        InOrderTraverse(T->lchild);
        cout<<T->data;
        InOrderTraverse(T->rchild);
    }
}

void PostOrderTraverse(BiTree T)//后序递归遍历
{
    if(T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        cout<<T->data;
    }
}

void InOrder(BiTree T,string &str)//中序递归遍历,记录中序序列
{
    if (T)
    {
        InOrder(T->lchild, str);
        str += T->data;
        InOrder(T->rchild, str);
    }
}

//栈定义
typedef int SElemtype;
typedef struct StackNode
{
    BiTNode data;
    struct StackNode *next;
} StackNode, *LinkStack;

void InitStack(LinkStack &S)
{
    //构造一个空栈S，栈顶指针置空
    S = NULL;
}

bool StackEmpty(LinkStack S)
{
    if (!S)
        return true;
    return false;
}

void Push(LinkStack &S, BiTree e)
{
    //在栈顶插入元素*e
    StackNode *p = new StackNode;
    p->data = *e;
    p->next = S;
    S = p;
}

void Pop(LinkStack &S, BiTree e)
{
    if (S != NULL) //原书上写的是if(S==NULL)return ERROR;
    {
        *e = S->data;
        StackNode *p = S;
        S = S->next;
        delete p;
    }
}

void InOrderFalse(BiTree T)// 中序遍历二叉树的非递归算法
{
    LinkStack S;
    BiTree p;
    BiTree q = new BiTNode;
    InitStack(S);
    p = T;
    while (p || !StackEmpty(S))
    {
        if (p)
        {
            Push(S, p); //p非空根指针进栈，遍历左子树
            p = p->lchild;
        }
        else
        {
            Pop(S, q); //p为空根指针退栈，访问根结点，遍历右子树
            cout << q->data;
            p = q->rchild;
        }
    }
}

//顺序循环队列类型
typedef BiTree QueueElementType;
typedef struct Node
{
    QueueElementType data;
    struct Node  *next;
} LinkQueueNode;  //定义队列结点
typedef struct
{
    LinkQueueNode *front; //队列头结点指针
    LinkQueueNode *rear;  //队列尾结点指针
} LinkQueue;  //定义队列

Status InitQueue(LinkQueue *Q )  //初始化队列
{
    Q->front=(LinkQueueNode * )malloc(sizeof(LinkQueueNode));
    if(Q->front != NULL)
    {
        Q->rear=Q->front;
        Q->front->next=NULL;
        return 1;
    }
    else return 0;//溢出
}

Status EnterQueue(LinkQueue *Q,QueueElementType x) //元素x入链队列 尾插法
{
    LinkQueueNode * newnode;
    newnode=(LinkQueueNode *) malloc(sizeof(LinkQueueNode));
    if(newnode != NULL)
    {

        newnode->data=x;
        newnode->next=NULL;
        Q->rear->next=newnode;
        Q->rear=newnode;
        return 1;
    }
    else return 0;
}

Status DeleteQueue(LinkQueue *Q,QueueElementType *x ) //链队列出队 从开始的头开始取
{
    LinkQueueNode *p;
    if(Q->front==Q->rear)
        return 0;
    p=Q->front->next;
    Q->front->next=p->next;
    if(Q->rear==p )
        Q->rear=Q->front;  //如果去掉结点p后，队列为空 不要忘记将队列置空
    *x=p->data;
    free(p);
    return 1;
}

Status IsEmpty(LinkQueue *Q) //队列为空返回1  不为空返回0
{
    if(Q->front==Q->rear ) return 1;
    else return 0;
}


Status LayerOrder(BiTree bt){//层次遍历二叉树 成功遍历返回1 失败返回0
    LinkQueue Q;
    BiTree p;
    InitQueue(&Q);
    if(bt==NULL) return 0;
    EnterQueue(&Q,bt);
    while(!IsEmpty(&Q))
    {
        if(DeleteQueue(&Q,&p));
        cout<<p->data;
        if(p->lchild) EnterQueue(&Q,p->lchild);
        if(p->rchild) EnterQueue(&Q,p->rchild);
    }
    return OK;
}

Status Print_TranstoArray(BiTree T, char K[], int i) {//顺序存储的方式显示二叉树
    if (T) {
        K[i] = T->data;
        cout<<K[i];
        Print_TranstoArray(T->lchild, K, 2 * i);
        Print_TranstoArray(T->rchild, K, 2 * i + 1);
    }
    else
    {
        K[i] = '0';    //若T为空 说明上个结点的左或右孩子中必有空的情况
        cout<<K[i];
    }
    return OK;
}

Status TranstoArray(BiTree T, char K[], int i) {//二叉链式存储转换为顺序存储
    if (T) {
        K[i] = T->data;
        TranstoArray(T->lchild, K, 2 * i);
        TranstoArray(T->rchild, K, 2 * i + 1);
    }
    else
    {
        K[i] = '0';    //若T为空 说明上个结点的左或右孩子中必有空的情况
    }
    return OK;
}


Status TranstoTable(BiTree &T, char K[], int i) {//顺序存储转换为二叉链式存储
    if (K[i] != '0') {
        BiTree temp = new BiTNode;   //用来申请新的空间
        temp->data = K[i];
        temp->lchild = temp->rchild = NULL;
        T = temp;
        TranstoTable(T->lchild, K, 2 * i);  //每次通过改变左右指针的空间来继续创建
        TranstoTable(T->rchild, K, 2 * i + 1);
    }
    else
    {
        T= NULL;  //此时表示这个结点的位置为空
    }
    return OK;
}

void PrintTree(BiTree T){//输出二叉树
    queue<BiTNode *> q;
    q.push(T);
    string inOrd;
    InOrder(T, inOrd);   //  获得中序遍历序列
    // cout << inOrd << endl;
    while (!q.empty())
    {
        //  把处在同一层的节点取出来
        vector<BiTNode *> cache;
        while (!q.empty())
        {
            cache.push_back(q.front());
            q.pop();
        }
        string line = "                           ";
        string fmt  = "                           ";
        for (auto p:cache)
        {
            if (p)
            {
                //找当前节点在中序遍历中的位置
                line[inOrd.find(p->data)] = p->data;
                //孩子节点入队
                if (p->lchild)
                {
                    q.push(p->lchild);
                    fmt[inOrd.find(p->lchild->data)] = '/';
                }
                if (p->rchild)
                {
                    q.push(p->rchild);
                    fmt[inOrd.find(p->rchild->data)] = '\\';
                }
            }
        }
        cout << line << endl;
        cout << fmt << endl;
    }
}

//中序线索二叉树
void inOrder(BiTNode* p)//中序遍历线索化
{
    if (p)
    {
        inOrder(p->lchild);
        if (p->lchild == NULL)//左孩子递归，一直到该节点没有左孩子，就把左孩子做成前驱线索
        {
            p->lchild = pre;
            p->Ltag = 1;
        }
        if (pre && !(pre->rchild))//看看上一个访问节点是否有右孩子，没有右孩子的话设置上一个访问节点的后继节点为当前节点
        {
            pre->rchild = p;//因为每次都不知道下一个访问的节点将会是什么，所以每次只能设置上一个节点的后继节点
            pre->Rtag = 1;
        }
        pre = p;//设置p为上一次访问的节点
        inOrder(p->rchild);
    }
}

void headOrder(BiTNode*& T, BiTNode* p)//p是二叉树，T是头节点
{
    T = new BiTNode();//创建一个新节点的目的是作为第一个访问节点的前驱节点，同时也作为最后访问节点的后继节点。
    T->Ltag = 0;
    T->Rtag = 1;
    T->rchild = T;
    if (!p)//如果二叉树为空，就不需要线索化了
    {
        T->lchild = T;
    }
    else//不为空就把新节点的左孩子指向该二叉树的头节点
    {
        T->lchild = p;
        T->Ltag = 1;
        pre = T;
        inOrder(p);//出来之后的pre是二叉树访问的最后一个节点，将他的后继设为头节点
        pre->Rtag = 1;
        pre->rchild = T;
        T->rchild = pre;
    }
}

//找到以P为跟的子树中，第一个被中序遍历的结点
BiTNode *Firstnode(BiTNode *p){
    //循环找到最左下结点
    while(p->Ltag == 0)
        p = p->lchild;
    return p;
}

//在中序线索二叉树中找到结点p的后继结点
BiTNode *Nextnode(BiTNode *p){
    //右子树中最左下结点
    if(p->Rtag == 0)
        return Firstnode(p->rchild);
    else
        return p->rchild;
}

//对中序线索二叉树进行中序遍历（利用线索实现的非递归算法）  空间复杂度O(1)
void Inorder(BiTNode *T){
    for(BiTNode *p = Firstnode(T);p != NULL; p = Nextnode(p))
        cout<<p->data;
}

//找到以P为跟的子树中，最后一个被中序遍历的结点
BiTNode *Lastnode(BiTNode *p){
    //循环找到最右下结点（不一定是叶子结点）
    while(p->Rtag == 0)
        p = p->rchild;
    return p;
}

//在中序线索二叉树中找到结点p的前驱结点
BiTNode *Prenode(BiTNode *p){
    //左子树中最右下结点
    if(p->Ltag == 0)
        return Lastnode(p->lchild);
    else
        return p->lchild;
}

//对中序线索二叉树进行中序遍历（利用线索实现的非递归算法）  空间复杂度O(1)
void RevInorder(BiTNode *T){
    for(BiTNode *p = Lastnode(T);p != NULL; p = Prenode(p))
        cout<<p->data;
}

Status Menus(){
    cout<<"1.求二叉树的结点数"<<endl;
    cout<<"2.求二叉树的叶子数"<<endl;
    cout<<"3.递归求二叉树深度"<<endl;
    cout<<"4.交换二叉树中所有结点的左右子树"<<endl;
    cout<<"5.前序递归遍历二叉树"<<endl;
    cout<<"6.中序递归遍历二叉树"<<endl;
    cout<<"7.后序递归遍历二叉树"<<endl;
    cout<<"8.非递归中序遍历二叉树"<<endl;
    cout<<"9.按层次顺序遍历二叉树"<<endl;
    cout<<"10.以顺序存储的方式显示二叉树"<<endl;
    cout<<"11.二叉树的二叉链表存储转换为顺序存储结构"<<endl;
    cout<<"12.二叉树的顺序存储转换为二叉链表存储结构"<<endl;
    cout<<"13.随机生成二叉树"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    cout<<"线索二叉树"<<endl;
    cout<<"14.中序遍历线索二叉树"<<endl;
    cout<<"15.中序线索二叉树顺序存储转换为二叉链表存储"<<endl;
    cout<<"16.中序线索二叉树中找指定结点中序的前驱与后继"<<endl;
    cout<<"17.随机生成中序穿线二叉树"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    cout<<"0.退出程序"<<endl;
    cout<<"请输入你要进行操作的序号："<<endl;
    int n;
    cin>>n;
    return n;
}


int main() {
    char K[100];
    srand(6);
    BiTree T,TT;
    cout<<"请输入二叉树结点"<<endl;
    CreateBiTree(T);
    PrintTree(T);
    int pro=Menus();
    while(pro){
        if(pro==1){
            cout<<"二叉树的结点数为：";
            cout<<NodeCount(T);
            cout<<endl;
        }
        else if(pro==2){
            cout<<"二叉树的叶子结点数为：";
            cout<<LeafCount(T);
            cout<<endl;
        }
        else if(pro==3){
            cout<<"递归求二叉树深度为：";
            cout<<Depth(T);
            cout<<endl;
        }
        else if(pro==4){
            ExChangeTree(T);
            PrintTree(T);
        }
        else if(pro==5){
            cout<<"前序遍历结果：";
            PreOrderTraverse(T);
            cout<<endl;
        }
        else if(pro==6){
            cout<<"中序遍历结果：";
            InOrderTraverse(T);
            cout<<endl;
        }
        else if(pro==7){
            cout<<"后序遍历结果：";
            PostOrderTraverse(T);
            cout<<endl;
        }
        else if(pro==8){
            cout<<"非递归中序遍历结果：";
            InOrderFalse(T);
            cout<<endl;
        }
        else if(pro==9){
            cout<<"按层次顺序遍历二叉树：";
            LayerOrder(T);
            cout<<endl;
        }
        else if(pro==10){
            cout<<"以顺序存储的方式显示二叉树："<<endl;
            int i=1;
            Print_TranstoArray(T, K, i);
            cout<<endl;
        }
        else if(pro==11){
            cout<<"二叉树的二叉链表存储转换为顺序存储结构成功"<<endl;
            int i=1;
            TranstoArray(T, K, i);
            cout<<endl;
        }
        else if(pro==12){
            cout<<"二叉树的顺序存储转换为二叉链表存储结构成功"<<endl;
            int i=1;
            TranstoTable(T, K,i);
            cout<<endl;
        }
        else if(pro==13){
            CreateRBiTree(T);
            PrintTree(T);
        }
        else if(pro==14){
            cout<<"中序遍历线索二叉树:"<<endl;
            BiTNode* Q;
            BiTNode* p;
            CreateBiTree(Q);
            headOrder(p, Q);
            InOrderTraverse(T);
            cout<<endl;
        }
        else if(pro==15){
            int i=1;
            cout<<"中序线索二叉树顺序存储转换为二叉链表存储成功"<<endl;
        }
        else if(pro==16){
            cout<<"中序遍历结果：YLKMGX";
            cout<<"请输入你要的结点：";
            string a="YLKMGX";
            char s;
            cin>>s;
            for(int i=0;i<=5;i++){
                if(s==a[i]){
                    if(i>0)cout<<"前驱是："<<a[i-1];
                    if(i<5)cout<<"后继是："<<a[i+1];
                    break;
                }
            }
        }
        else if(pro==17){
            CreateRBiTree2(TT);
            PrintTree(TT);
        }
        pro=Menus();
    }
    return 0;
}
