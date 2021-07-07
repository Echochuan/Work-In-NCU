#include <time.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

//函数结果状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERLOW -2
//Status
typedef int Status;
//ElemType
typedef int ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;


typedef struct 
{
    float coef;
    int expn;
}DataType;
typedef struct LPNode{
    DataType data;
    struct LPNode *next;
}LPNode,*Poly;

Status InitPoly(Poly &F)
{
    if(!(F=(Poly)malloc(sizeof(LPNode)))) return OVERLOW;
    F->data.coef=0;F->data.expn=-1;// 以头结点的 coef 数据作为储存多项式长度的向标
    F->next=NULL;
    return OK;
}//InitPoly

Status DestoryPoly(Poly &F)
{
    LPNode *p;
    p=F->next;
    while(p->next)
    {
        F->next=p->next;
        free(p);p=F->next;
    }
    free(p);free(F);
    F->next=NULL;
    return OK;
}//DestroyPoly

void TraverPoly(Poly F)
{
    LPNode *p;
    int j=1;
    p=F->next;
    if(F->data.coef==0) cout<<0<<endl;
    else
    {
        for(j;j<=F->data.coef;j++)
        {
            if(j!=F->data.coef)
            {
                cout<<p->data.coef<<"x^"<<p->data.expn<<"+";
                p=p->next; 
            }
            else cout<<p->data.coef<<"x^"<<p->data.expn<<endl;
        }
    }
    cout<<endl;
}//TraverPoly

Status DeletePoly0(Poly &F)
{
    LPNode *p,*q;
    p=F->next;q=F;
    while(p->next)
    {
        if(p->data.coef==0)
        {
            q->next=p->next;
            free(p);
            p=q->next;
            F->data.coef--;
        }
        else
        {
            q=p;
            p=p->next;
        }
    }
    if(p->data.coef==0)
    {
        q->next=NULL;free(p);F->data.coef--;
    }
    return OK;
}//DeletePoly0

Status CombinPolySame(Poly &F)
{
    LPNode *p,*q,*r;
    p=F->next;q=p->next;r=p;
    while(p->next)
    {
        while(q->next)
        {
            if(q->data.expn==p->data.expn)
            {
                p->data.coef+=q->data.coef;
                r->next=q->next;free(q);
                q=r->next;F->data.coef--;
            }
            else
            {
                r=q;
                q=q->next;
            }
        }
        if(q->data.expn==p->data.expn)
        {
            p->data.coef+=q->data.coef;
            r->next=NULL;free(q);
            F->data.coef--;
        }
        p=p->next;q=p->next;r=p;
    }
    return OK;
}//CombinPolySame

Status PolyInsert(Poly &F,int i,DataType D)
{
    LPNode *p;
    int j=0;
    p=F;
    while(p&&j<i-1)
    {
        p=p->next;
        j++;
    }
    if(!p||j>i-1) return ERROR;
    Poly G;
    G=(Poly)malloc(sizeof(LPNode));
    G->data=D;G->next=p->next;
    p->next=G;F->data.coef++;
    return OK;
}//PolyInsert

void PolyEmpty(Poly F)
{
    if(F->data.coef==0) cout<<"多项式为空！"<<endl;
    else cout<<"多项式不为空！"<<endl;
}//PolyEmpty

void OnePolyToOther(Poly F,Poly &G)
{
    LPNode *p;
    p=F->next;
    InitPoly(G);
    for(int j=1;j<=F->data.coef;j++)
    {
        PolyInsert(G,j,p->data);
        p=p->next;
    }
    G->data.coef=F->data.coef;
    TraverPoly(G);
    cout<<"赋值完成！"<<endl;
}//OnePolyToOther

void PlusPolys(Poly &F,Poly G)
{
    LPNode *p,*q,*r;
    int i,j;
    p=F->next;q=G->next;r=G;
    for(i=1;i<=F->data.coef;i++)
    {
        for(j=1;j<=G->data.coef;j++)
        {
            if(q->data.expn==p->data.expn)
            {
                p->data.coef+=q->data.coef;
                r->next=q->next;free(q);
                q=r->next;--G->data.coef;
                break;
            }
            else 
            {
                r=q;
                q=q->next;
            }
        }
        q=G->next;p=p->next;r=G;
    }
    DeletePoly0(F);

    if(G->next)
    {
        q=G->next;
        while(q->next)
        {
            PolyInsert(F,F->data.coef,q->data);
            q=q->next;
        }
        PolyInsert(F,F->data.coef,q->data);
    }
    
    TraverPoly(F);
    cout<<"多项式加法完成！"<<endl;
}//PlusPolys

void SubPolys(Poly &F,Poly G)
{
    LPNode *p,*q,*r;
    int i,j;
    p=F->next;q=G->next;r=G;
    for(i=1;i<=F->data.coef;i++)
    {
        for(j=1;j<=G->data.coef;j++)
        {
            if(q->data.expn==p->data.expn)
            {
                p->data.coef-=q->data.coef;
                r->next=q->next;free(q);
                q=r->next;--G->data.coef;
                break;
            }
            else 
            {
                q->data.coef=-q->data.coef;
                r=q;
                q=q->next;
            }
        }
        q=G->next;p=p->next;r=G;
    }
    DeletePoly0(F);

    if(G->next)
    {
        q=G->next;
        while(q->next)
        {
            PolyInsert(F,F->data.coef,q->data);
            q=q->next;
        }
        PolyInsert(F,F->data.coef,q->data);
    }
    
    TraverPoly(F);
    cout<<"多项式减法完成！"<<endl;
}//SubPolys

void ClearPoly(Poly &F)
{
    F->data.coef=0;
    F->next=NULL;
    cout<<"多项式已清零！"<<endl;
}//ClearPoly

Status RandomP(Poly &F,int i)
{
    DataType D;
    srand(unsigned(time(NULL)));
    loop:
    while(F->data.coef!=i)
    {
        D.coef=rand()%100+1;
        D.expn=rand()%10+1;
        PolyInsert(F,1,D);
    }
    CombinPolySame(F);
    if(F->data.coef!=i) goto loop;
    return OK;
}

void RandomPoly(Poly &F)
{
    int i;
    
    cout<<"请输入多项式的项的个数：";
    cin>>i;
    RandomP(F,i);
    cout<<"随机多项式生成完成！"<<endl;
}//RandomPoly

void OnePolyInitOther(Poly F,Poly &G)
{
    LPNode *p,*q;
    DataType D;
    p=F->next;
    G=(Poly)malloc(sizeof(LPNode));
    G->data.coef=0;
    for(int i=1;i<=F->data.coef;i++)
    {
        cout<<"输入多项式："<<endl;
        cout<<"系数：";
        cin>>D.coef;
        cout<<"指数：";
        cin>>D.expn;
        PolyInsert(G,i,D);
    }
    // CombinPolySame(G);
    TraverPoly(G);
    cout<<"多项式初始化完成！"<<endl;
}

void InputPoly(Poly &F)
{
    int i;
    DataType D;
    cout<<"请输入需要输入多项式的项数：";
    cin>>i;
    for(int j=1;j<=i;j++)
    {
        cout<<"第"<<j<<"个数据："<<endl;
        cout<<"系数：";
        cin>>D.coef;
        cout<<"指数：";
        cin>>D.expn;
        PolyInsert(F,j,D);
    }
    CombinPolySame(F);
    cout<<"输入完成！"<<endl;
}

void menu()
{
        cout << "    ******* 多项式的运算(非循环单链表的应用) ******    " << endl
			 << endl
			 << "    16.1、判断多项式是否为空" << endl
			 << "    16.2、把一个多项式赋值各另一个多项式" << endl
			 << "    16.3、两个多项式的加法" << endl
			 << "    16.4、两个多项式的减法" << endl
			 << "    16.5、设置多项式为空多项式" << endl
			 << "    ☆16.6、随机生成多项式" << endl
			 << "    ☆16.7、使用已有多项式初始化另一个多项式" << endl
			 << "    ☆16.8、输入多项式" << endl
			 << endl;
}//menu


void outPoly(Poly F)
{
    cout<<"//////////////////////////////////////////////"<<endl<<endl;
    cout<<"当前多项式有"<<F->data.coef<<"项，多项式(采用非循环单链表储存)为："<<endl;
    TraverPoly(F);
    cout<<endl
        <<"//////////////////////////////////////////////"<<endl
        <<"请输入你需要的操作(代码为1~8，其他则退出程序)：";
}

int main() 
{
    Poly F,G;
    Status St;
    int j;
    St=InitPoly(F);
    if(St==OVERLOW)
    {
        cout<<"初始化多项式失败！"<<endl;
        goto exit;
    }
    RandomP(F,5);

    loop:
    menu();
    outPoly(F);
    cin>>j;
    switch (j)
    {
    case 1://判断空
        PolyEmpty(F);
        break;
    case 2://赋值
        OnePolyToOther(F,G);
        break;
    case 3://加法
        PlusPolys(F,G);
        break;
    case 4://减法
        SubPolys(F,G);
        break;
    case 5://清空
        ClearPoly(F);
        break;
    case 6://随机
        RandomPoly(F);
        break;
    case 7://初始化
        OnePolyInitOther(F,G);
        break;
    case 8://输入
        InputPoly(F);
        break;
    }
    goto loop;
    exit:
    cout<<"谢谢使用！"<<endl;
    return 0;
}
