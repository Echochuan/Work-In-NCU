#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define LIST_INIT_SIZE 5
#define LISTINCREMENT 1
#define random(x) (rand()%x)
using namespace std;
typedef  int  Status;
typedef  int  ElemType; //表内元素类型为 int, 可更改

typedef struct
{
    ElemType *elem;
    int length;
}SqList;

int n, i, j, e, *p;     //全局变量
ElemType maxelem, x;

Status InitList(SqList &L) 
{
    L.elem = new ElemType[MAXSIZE]; // new 是申请空间
    if(!L.elem)  
        exit(OVERFLOW);
    L.length = 0;
    return OK;
}

Status Create(SqList &L, int n, int i) //创建一个随机的顺序表
{
    n = random(10);
    cout << n << endl;  //随机顺序表中元素的个数
    for(i = 0; i < n ; i++)
    {
        L.elem[i] = rand() % 100;
        cout << L.elem[i] << ' ';
        ++L.length;
    }
    return 0;
}

Status ListInsert(SqList &L, int i, ElemType x)  //在线性表的第i个元素前插入一个正整数x
{
    printf("Please enter the insertion position and value:\n");
    cin >> i >> x;
    if((i < 1) || (i > L.length+1))
    {
        printf("Transboundary\n");
        return ERROR;
    }
    if(L.length == MAXSIZE)
        return ERROR;
    for(int j = L.length-1; j >= i-1; --j)
        L.elem[j+1] = L.elem[j];
    L.elem[i-1] = x;
    ++L.length;
    printf("The linear table after inserting is as follow:\n");
    for(int i = 0; i < L.length; ++i)
        cout << L.elem[i] << ' ';
    cout << endl;
    return OK;
}
Status Itis_none(SqList L)  //判断顺序表是否为空
{
    if(!L.length)
    {
        printf("empty\n");
    }
    else 
    {
        printf("not empty\n");
    }
    return OK;
}

Status Howmany(SqList &L)   //求顺序表中元素的个数
{
    printf("the length is %d\n",L.length);
    return OK;
}

Status Search(SqList L,int i)   //取第i个元素
{
    printf("what you want to find?\n");
    scanf("%d",&i);
    i=i-1;
    if((i <= 0) || (i>L.length))
    {
        printf("Transboundary\n");
        return ERROR;
    }
    else
    {
    cout << L.elem[i] <<endl;
    }
    return OK;
}

Status ElemCompare(ElemType a,ElemType b){
	//两元素是否相等 
	
	if(a==b) return 1;
	return 0;
}

Status LocateElem_Sq(SqList L, ElemType e, Status(* compare)(ElemType, ElemType))
{
 //在顺序线性表L中查找第1个值与e满足compare()的元素的位序
 //若找到，则返回其在L中的位序，否则返回0；
    int i = 1;                                      //i的初值为第1个元素的位序
    ElemType *p = L.elem;  
    printf("请输入你想要检测的数：");
    scanf("%d",&e);                      //p的初值为的1个元素的储存位置
    while(i <= L.length && !(*compare)(*p++, e))
    {
        i++;
    }
    if(i <= L.length)
        {
            printf("%d\n",i);
            return OK;
        }
    else return 0;
}  


Status Listback(SqList L, int i)   //返回某元素的前驱
{
    printf("你想返回哪个元素的前驱？请输入它的序号：\n");
    scanf("%d",&i);
    i = i-2;
    if(i <= 1 && i>L.length)
    {
        printf("请输入正确的元素序号");
        return ERROR;
    }
    else 
    {
    cout << L.elem[i] <<endl;
    }
    return OK;
}

Status Listadd(SqList L,int i)  //返回某元素的后继
{
    printf("你想返回哪个元素的后继？请输入它的序号：\n");
    scanf("%d",&i);
    if( i > L.length && i < 1)
    {
        printf("请输入正确的元素序号");
        return ERROR;
    }
    else
    {
    cout << L.elem[i] <<endl;
    }
    return OK;
}
Status ListDelete(SqList &L, int j)  //删除线性表中的第j个元素
{
    printf("Enter the position of the element to delete:\n");
    scanf("%d", &j);
    if((j < 1) || (j > L.length))
    {
        printf("Transboundary\n");
        return ERROR;
    }
    for(int i = j; i <= L.length; ++i)
        L.elem[i-1] = L.elem[i];
    --L.length;
    printf("The linear table after deleting is as follow:\n");
    for(int i = 0; i < L.length; ++i)
        cout << L.elem[i] << ' ';
    cout << endl;
    return OK;
}

Status Clear(SqList &L)
{
    L.length = 0;
    return OK;
}


int main()
{
    int num;

    SqList L;
    printf("What do you want to do?\n");
    printf("0.输入我创建一个随机的顺序表\n");
    printf("1.在线性表的第i个元素前插入一个正整数x\n");
    printf("2.判断顺序表是否为空\n");
    printf("3.求顺序表中元素的个数\n");
    printf("4.取第i个元素\n");
    printf("5.查找第1个与某元素满足compare()关系元素的序号\n");
    printf("6.返回某元素的前驱\n");
    printf("7.返回某元素的后继\n");
    printf("8.删除线性表中的第j个元素\n");
    printf("9.把顺序表清空\n");
    printf("10.退出程序\n");
    printf("Please enter the serial number of the operation you want to perform:\n");
    while(cin >> num) //循环输入， 可执行多个操作
    {
        switch(num)
        {
            case 0: InitList(L); 
                    Create(L, n, i); break;
            case 1: ListInsert(L, i, x); break;
            case 2: Itis_none(L); break;
            case 3: Howmany(L); break;
            case 4: Search(L, i); break;
            case 5: LocateElem_Sq(L, e, ElemCompare); break;
            case 6: Listback(L, i); break;
            case 7: Listadd(L, i); break;
            case 8: ListDelete(L, j); break;
            case 9: Clear(L); break;
            case 10: printf("see you next time");exit(0);
            default: printf("The serial number is illegal.Please enter again:\n");
        }
        printf("Please enter the serial number of the operation you want to perform:\n");
    }
    return 0;
}