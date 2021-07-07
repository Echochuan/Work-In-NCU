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

//------非循环单链表操作的实现------
Status InitList_L(LinkList &L);
//初始化链表(带头结点)
//结果：创建两个结点，一个为头节点，另一个为存放数据的结点
Status DestoryList_L(LinkList &L);
//摧毁链表
//条件：链表存在
//结果：链表被摧毁
Status ClearList_L(LinkList &L);
//清空链表
//条件：链表存在
//结果：链表被清空
Status ListEmpty_L(LinkList L);
//判断链表是否为空
//条件：链表存在
//结果：链表为空则返回TRUE,链表不为空则返回FALSE
int ListLenght_L(LinkList L);
//显示链表长度
//条件：链表存在
//结果：返回链表的长度
Status GetData_L(LinkList L,int i,ElemType &D);
//取出数据
//条件：链表存在，i介于0~链表长度ListLenght 之间
//结果：元素存在则返回元素数据内容，不存在则返回FALSE
int LocateData(LinkList L,ElemType D,Status (*compare)(ElemType ,ElemType));
//定位数据
//条件：链表存在 compare()为数据元素判断函数
//结果：若D为链表中元素，则返回其位序,反之返回0
Status LinkPrior(LinkList L,ElemType D,ElemType &pre_D);
//返回元素前驱
//条件：链表存在，
//结果：若D为链表中元素，且不为第一位则返回其前驱，反之pre_D没有定义
Status LinkNext(LinkList L,ElemType D,ElemType &net_D);
//返回元素后继
//条件：链表存在
//结果：若D为链表中元素，且不为最后一位则返回其后继，反之net_D没有定义
Status ListInsert_L(LinkList &L,int i,ElemType D);
//插入元素
//条件：链表存在，且i在0~链表长度LinkLenght之间
//结果：在链表第i个元素之前插入一个新元素
Status ListDelete_L(LinkList &L,int i,ElemType &D);
//删除元素
//条件：链表存在，且i在0~链表长度LinkLenght之间
//结果：链表中第i个元素被删除，且用D返回
void TraverLink(LinkList L);
//遍历链表
//条件：链表存在
//结果：输出链表中所有元素，若为空返回空集

//------非循环单链表操作的实现------
Status InitList_L(LinkList &L)
{
    if(!(L=(LinkList)malloc(sizeof(LNode)))) return OVERLOW;
    L->data=0;//使用头结点的数据域记录链表长度
    L->next=NULL;
    return OK;
}//InitList_L

Status DestoryList_L(LinkList &L)
{
    LNode *p;
    p=L->next;
    while(p->next)
    {
        L->next=p->next;
        free(p);p=L->next;
    }
    free(p);
    free(L);
    L->data=0;L->next=NULL;
    return OK;
}//DestoryList_L

Status ClearList_L(LinkList &L)
{
    L->next=NULL;
    L->data=0;
    return OK;
}//ClearList_L

Status ListEmpty_L(LinkList L)
{
    if(L->next) return FALSE;
    else return TRUE;
}//ListEmpty_L

int ListLenght_L(LinkList L)
{
    return L->data;
}//ListLenght_L

Status GetData_L(LinkList L,int i,ElemType &D)
{
    LNode *p;
    int j=1;
    p=L->next;
    while(p&&j<i)
    {
        p=p->next;
        ++j;
    }
    if(!p||j>i) return ERROR;
    D=p->data;
    return OK;
}//GetData_L

int LocateData(LinkList L,ElemType D,Status (*compare)(ElemType,ElemType))
{
    LNode *p;
    int j;
    p=L->next;
    for(j=1;j <= L->data;j++)
    {
        if(compare(p->data,D)==TRUE) return j;
        else p=p->next;
    }
    if((!p)||(j > L->data)) return 0;
}//LocateData

Status LinkPrior(LinkList L,ElemType D,ElemType &pre_D)
{
    int j;
    LNode *p,*q;
    q=L->next;p=q->next;
    if(D==q->data) return ERROR;//第一个
    for(j=1;j < L->data;j++)
    {
        if(D==p->data)
        {
            pre_D=q->data;
            return OK;//在链表中找到元素D
        }
        else
        {   
            q=p;
            p=p->next;
        }
    }
    if((p->next==NULL)&&(j>L->data)) return FALSE;//链表中没有元素D
}//LinkPrior

Status LinkNext(LinkList L,ElemType D,ElemType &net_D)
{
    int j;
    LNode *p,*q;
    p=L->next;q=p->next;
    for(j=1;j < L->data;j++)
    {
        if(D==p->data)
        {
            net_D=q->data;
            return OK;//在链表中找到元素D
        }
        else
        {
            p=q;
            q=q->next;
        }
    }
    if(D==p->data) return ERROR;//最后一个
    else if((q==NULL)&&(j>L->data)) return FALSE;//链表中没有元素D
}//LinkNext

Status ListInsert_L(LinkList &L,int i,ElemType D)
{
    LNode *p;
    int j=0;
    p=L;
    while(p&&j<i-1)
    {
        p=p->next;
        j++;
    }
    if(!p||j>i-1) return ERROR;
    LinkList S;
    S=(LinkList)malloc(sizeof(LNode));
    S->data=D;S->next=p->next;
    p->next=S;L->data++;
    return OK;
}//ListInsert_L

Status ListDelete_L(LinkList &L,int i,ElemType &D)
{
    LNode *p;
    int j=0;
    p=L;
    while(p->next&&j<i-1)
    {
        p=p->next;
        j++;
    }
    if(!(p->next)||j>i-1) return ERROR;
    p->next=p->next->next;
    p=p->next;D=p->data;
    free(p);
    L->data--;
    return OK;
}//ListDelete_L

void TraverLink(LinkList L)
{
    LNode *p;
    int j=1;
    p=L->next;
    if(L->data==0) cout<<"该链表为空表！"<<endl;
    else
    {
        for(j;j <= L->data;j++)
            {
                if(j!=L->data) 
                {
                    cout<<p->data<<"->   ";
                    p=p->next;
                }
                else cout<<p->data<<"∧"<<endl;
            }
    }
    cout<<endl;
}//TraverLink

Status comp(ElemType a,ElemType b)
{
    if(a==b) return TRUE;
    else return FALSE;
}


void GetNode(LinkList L)
{
    int i;
    ElemType D;
    Status st;
    loop:
    cout<<"请输入需要取出的结点位序：";
    cin>>i;
    st=GetData_L(L,i,D);
    if(st==ERROR)
    {
        cout<<"范围错误！请重新输入！"<<endl;
        cout<<"范围介于1~"<<L->data+1<<"之间。"<<endl;
        goto loop;
    }
    cout<<"第"<<i<<"个结点为:"<<D<<endl;
    cout<<"查找完成！"<<endl;
}//GetNode

void InsertData(LinkList &L)
{
    int i;
    ElemType D;
    Status st;
    loop:
    cout<<"请输入需要插入数据域的位序：";
    cin>>i;
    cout<<"请输入需要插入的数据：";
    cin>>D;
    st=ListInsert_L(L,i,D);
    if(st==ERROR)
    {
        cout<<"范围错误！请重新输入！"<<endl;
        cout<<"范围介于1~"<<L->data+1<<"之间。"<<endl;
        goto loop;
    }
    cout<<"插入成功！"<<endl;
}//InsertData

void EmptyList(LinkList L)
{
    Status st;
    st=ListEmpty_L(L);
    if(st==TRUE) cout<<"链表为空！"<<endl;
    else if(st==FALSE) cout<<"链表不为空！"<<endl;
}//EmptyList

void NodeNumber(LinkList L)
{
    int i;
    i=ListLenght_L(L);
    cout<<"链表中有"<<i<<"个结点。"<<endl;
}//NodeNumber

void CompareData(LinkList L)
{
    ElemType D;
    int i;
    cout<<"请输入需要查找的数据：";
    cin>>D;
    i=LocateData(L,D,comp);
    if(i==0) cout<<"链表中没有该数据！"<<endl;
    else cout<<"数据位于链表中的第"<<i<<"位。"<<endl;
}//CompareData

void ReturnPrior(LinkList L)
{
    Status st;
    ElemType D,pre_D;
    cout<<"请输入需要查找前驱的数据：";
    cin>>D;
    st=LinkPrior(L,D,pre_D);
    if(st==ERROR) cout<<"该数据位于链表的第一位，没有前驱！"<<endl;
    else if(st==FALSE) cout<<"链表中不存在该数据！"<<endl;
    else if(st==OK) cout<<"数据"<<D<<"的前驱为："<<pre_D<<endl;
    cout<<"前驱查找完成！"<<endl;
}//ReturnPrior

void ReturnNext(LinkList L)
{
    Status st;
    ElemType D,net_D;
    cout<<"请输入需要查找后继的数据：";
    cin>>D;
    st=LinkNext(L,D,net_D);
    if(st==ERROR) cout<<"该数据位于链表的最后一位，没有后继！"<<endl;
    else if(st==FALSE) cout<<"链表中不存在该数据！"<<endl;
    else if(st==OK) cout<<"数据"<<D<<"的后继为："<<net_D<<endl;
    cout<<"后继查找完成！"<<endl;
}//ReturnNext

void DeleteOne(LinkList &L)
{
    ElemType D,outD;
    int i;
    Status st;
    cout<<"请输入需要删除的数据：";
    cin>>D;
    i=LocateData(L,D,comp);
    if(i==0) cout<<"链表中不存在该元素！"<<endl;
    else
    {
        st=ListDelete_L(L,i,outD);
        cout<<"数据 "<<outD<<" 已删除！"<<endl;
    }
}//DeleteOne

void DeleteRepetition(LinkList &L)
{
    LNode *p,*q,*r;
    p=L->next;q=p->next;r=p;
    while(p->next->next)
    {
        while(q->next)
        {
            if(q->data==p->data)
            {
                r->next=q->next;
                free(q);
                q=r->next;
                L->data--;
            }
            else
            {
                r=q;
                q=q->next;
            }
        }
        p=p->next;q=p->next;r=p;
    }
    if(q->data==p->data)
    {
        p->next=NULL;
        free(q);
        L->data--;
    }
    cout<<"删除成功！"<<endl;
}//DeleteRepetition

void ListInversion_L(LinkList &L)
{
    LNode *p,*q,*r;
    p=L->next;q=p->next;r=q->next;
    p->next=NULL;
    while(r->next)
    {
        q->next=p;
        p=q;q=r;
        r=r->next;
    }
    q->next=p;
    p=q;q=r;
    q->next=p;
    L->next=q;
    TraverLink(L);
    cout<<"逆置完成!"<<endl;
}//ListInversion_L

void OneListToOther_L(LinkList L,LinkList &K)
{
    InitList_L(K);
    ElemType D;
    for(int j=1;j<=L->data;j++)
    {
        GetData_L(L,j,D);
        ListInsert_L(K,j,D);
    }
    K->data=L->data;
    TraverLink(K);
    cout<<"赋值完成！"<<endl;
}//OneListToOther_L

Status Random(LinkList &L,int i)
{
    ElemType D;
    srand(unsigned(time(NULL)));
    for(int j=1;j<=i;j++)
    {
        D=rand()%100+1;
        ListInsert_L(L,j,D);
    }
    return OK;
}//Random

void RandomList_L(LinkList &L)
{
    int i;
    cout<<"请输入需要随机的数据数目：";
    cin>>i;
    Random(L,i);
    cout<<"随机生成完成！"<<endl;
}//RandomList_L

void OneListInitOther_L(LinkList L,LinkList &K)
{
    LNode *p,*q;
    ElemType D;
    p=L->next;
    K=(LinkList)malloc(sizeof(LNode));
    K->data=0;
    for(int i=1;i<=L->data;i++)
    {
        cout<<"请输入数据：";
        cin>>D;
        ListInsert_L(K,i,D);
    }
    TraverLink(K);
    cout<<"初始化完成！"<<endl;
}//OneListInitOther_L

void InputList_L(LinkList &L)
{
    int i;
    ElemType D;
    cout<<"请输入需要输入数据的个数：";
    cin>>i;
    for(int j=1;j<=i;j++)
    {
        cout<<"第"<<j<<"个数据:";
        cin>>D;
        ListInsert_L(L,j,D);
    }
    cout<<"输入完成！"<<endl;
}//Input_L

void menu()
{
        cout << "    ******* 测 试 链 表 的 操 作 ******    " << endl
			 << endl
			 << "    1、取非循环单链表的第i个结点" << endl
			 << "    2、在第i个结点之前插入一个数据域为e的结点" << endl
			 << "    3、判断非循环单链表是否为空" << endl
			 << "    4、求非循环单链表中结点个数" << endl
			 << "    5、查找第1个与e满足compare()关系的结点" << endl
			 << "    6、返回某结点的前驱数据域" << endl
			 << "    7、返回某结点的后继数据域" << endl
			 << "    8、删除非循环单链表中数据域为e的第一个结点" << endl
			 << "    9、删除非循环单链表中的重复值" << endl
			 << "    10、非循环单链表的逆置" << endl
			 << "    11、把一个非循环单链表赋值给另一个非循环单链表" << endl
			 << "    12、把非循环单链表置空" << endl
			 << "    ☆13、随机生成非循环单链表" << endl
			 << "    ☆14、使用已有非循环单链表初始化另一个非循环单链表" << endl
			 << "    ☆15、输入非循环单链表" << endl
			 << endl;
}//menu

void outLink(LinkList L)
{
    int i=1;
    LNode *p;
    p=L->next;
    cout<<"//////////////////////////////////////////////"<<endl<<endl;
    cout<<"当前非循环单链表有"<<L->data<<"个数据域，为："<<endl;
    while(i<=L->data)
    {
        cout<<"["<<i<<"]    ";
        i++;
    }
    cout<<endl;
    TraverLink(L);
    cout<<endl
        <<"//////////////////////////////////////////////"<<endl
        <<"请输入你需要的操作(代码为1~16，其他则退出程序)：";
}

int main()
{
    int i;
    LinkList L,K;
    Status st;
    st=InitList_L(L);
    if(st==OVERLOW)
    {
        cout<<"初始化链表失败！"<<endl;
        goto exit;
    }
    Random(L,5);
    loop:
    menu();
    outLink(L);
    cin>>i;
    switch (i)
    {
    case 1://取结点
        GetNode(L);
        break;
    case 2://插入
        InsertData(L);
        break;
    case 3://判断空
        EmptyList(L);
        break;
    case 4://个数
        NodeNumber(L);
        break;
    case 5://查结点
        CompareData(L);
        break;
    case 6://前驱
        ReturnPrior(L);
        break;
    case 7://后继
        ReturnNext(L);
        break;
    case 8://删除i
        DeleteOne(L);
        break;
    case 9://删除重复
        DeleteRepetition(L);
        break;
    case 10://逆置
        ListInversion_L(L);
        break;
    case 11://赋值
        OneListToOther_L(L,K);
        DestoryList_L(K);
        break;
    case 12://清空
        ClearList_L(L);
        cout<<"清空链表完成！"<<endl;
        break;
    case 13://随机
        RandomList_L(L);
        break;
    case 14://初始化
        OneListInitOther_L(L,K);
        DestoryList_L(K);
        break;
    case 15://输入
        InputList_L(L);
        break;
    }
    goto loop;

    exit:
    cout<<"谢谢使用！"<<endl;
    return 0;
}
