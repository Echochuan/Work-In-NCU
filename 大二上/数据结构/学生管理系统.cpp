#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;


#define LIST_INIT_SIZE  100  //学生表储存空间的初始分配量 
#define LISTINCREMENT  10    //学生表存储空间的分配增量
#define TRUE  1
#define FALSE 0 
#define OK    1
#define ERROR 0
#define INFEASIBLE  -1
#define OVER_FLOW    -2

typedef int Status;
int order;

typedef struct {
    char Name[10];
    int number;
    int Chinese;
    int English;
    int Math;
    int Averge;
    int Sum;
}Student;

typedef Student ElemType;

typedef struct{
	ElemType *elem;
	int length;
	int listsize;
}SqList;

Status InitList(SqList &L){
	// 构造一个空的学生信息表
	
	L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L.elem) exit(OVER_FLOW);  //存储分配失败 
	L.length=0;				//空表长度为0
	L.listsize=LIST_INIT_SIZE;//初始存储容量
	return OK;
}

void IncreRoom(int len,SqList &L){
	//重新分配空间
	
	ElemType *newbase;
	while(L.listsize<len) L.listsize+=LISTINCREMENT; 
	newbase=(ElemType *)realloc(L.elem,(L.listsize)*sizeof(ElemType));
	if(!newbase) exit(OVER_FLOW);
	L.elem=newbase; 
}

Status ListInit(SqList &L,int i,ElemType e){
	//在第i个学生之前插入新学生
	
	if(i<1||i>L.length+1) return ERROR;
	if(L.length>=L.listsize) IncreRoom(L.length+1,L);
	for(int j=L.length;j>=i;j--) L.elem[j]=L.elem[j-1];//将第i个学生及其之后的往后移 
	L.elem[i-1]=e;
	L.length++;
	
	return OK;
} 

Status EmptyList(SqList L){
	//学生表是否为空 
	
	if(L.length==0) return TRUE;
	return FALSE;
}

Status ListLength(SqList L){
	//学生表中学生的人数
	
	return L.length;
}

Status GetElem(SqList L,int i,ElemType &e){
	//返回学生表中第i个学生
	
	if(i<1||i>L.length) return ERROR;
	e=L.elem[i-1]; 
	return OK;
}

Status PriorElem(SqList L,char Name[]){
	//根据姓名查找某学生并返回其前驱的序号 
	
	for(int i=2;i<=L.length;i++)
		if(!strcmp(L.elem[i-1].Name,Name)) return i-1;	
	return 0;
}

Status NextElem(SqList L,char Name[]){
	//根据姓名查找某学生并返回其后续的序号 
	
	for(int i=1;i<L.length;i++)
		if(!strcmp(L.elem[i-1].Name,Name)) return i+1;	
	return 0;
}

Status ListDelete(SqList &L,int i,ElemType &e){
	//删除学生表的第i个学生
	
	if(i<1||i>L.length) return ERROR;
	
	e=L.elem[i-1];
	for(int j=i;j<=L.length;j++) L.elem[j-1]=L.elem[j];
	L.length--;
	
	return OK;
}

void ListCopy(SqList La,SqList &Lb){
	//把一个学生表赋值给另外一个学生表
	
	Lb.length=La.length;
	if(Lb.listsize<La.length) IncreRoom(La.length,Lb);
	for(int i=0;i<La.length;i++) Lb.elem[i]=La.elem[i];
}

void ClearList(SqList &L){
	//设置学生表为空表
	
	L.length=0;
}

void RandomList(SqList &L,int len){
	//随机生成学生表
	
	int i,j,k,x,y;
	L.length=len;
	if(L.listsize<len) IncreRoom(len,L);
	srand((unsigned)time(NULL));//随机种子
	
	char a[10][10]={"赵","钱","孙","李","周","吴","郑","王","冯","陈"}; 
	char b[10][10]={"明理","守德","多智","晓礼","懂义","兴国","承信","阳明"}; 
	
	for(i=0;i<len;i++){
		x=rand()%10;
		y=rand()%10;
		for(j=0;j<strlen(a[x]);j++) L.elem[i].Name[j]=a[x][j];
		for(k=0;k<strlen(b[y]);k++) L.elem[i].Name[j+k]=b[y][k];
		L.elem[i].Name[strlen(a[x])+strlen(b[y])]='\0';
		L.elem[i].number=rand()%99+1;
		L.elem[i].Chinese=rand()%91+10;
		L.elem[i].English=rand()%91+10;
		L.elem[i].Math=rand()%91+10;
		L.elem[i].Sum=L.elem[i].Chinese+L.elem[i].English+L.elem[i].Math;
		L.elem[i].Averge=L.elem[i].Sum/3;
	}
}

void InputList(SqList &L,int len){
	//输入学生表
	
	if(L.listsize<len) IncreRoom(len,L);
	cout<<" 学号 "<<" 姓名 "<<" 语文 "<<" 英语 "<<" 数学 "<<endl;
	for(int i=0;i<len;i++){
		cin>>L.elem[i].number>>L.elem[i].Name;
		cin>>L.elem[i].Chinese>>L.elem[i].English;
		cin>>L.elem[i].Math;
		L.elem[i].Sum=L.elem[i].Chinese+L.elem[i].English+L.elem[i].Math;
		L.elem[i].Averge=L.elem[i].Sum/3;
		
	}
}

void PrintList(SqList L){
	//将学生表打印 
	
	cout<<"当前学生表（采用顺序表存储）有"<<L.length<<"个学生，分别为："<<endl<<endl;
	cout<<" 学号 "<<" 姓名 "<<" 语文 "<<" 英语 "<<" 数学 "<<" 平均分 "<<" 总分 "<<endl;  
	for(int i=0;i<L.length;i++){
		cout<<"  "<<setw(2)<<setfill('0')<<L.elem[i].number<<"  ";
		cout<<L.elem[i].Name;
		cout<<setfill(' ')<<setw(4)<<L.elem[i].Chinese<<setw(6)<<L.elem[i].English<<setw(6)<<L.elem[i].Math<<setw(7)<<L.elem[i].Averge<<setw(7)<<L.elem[i].Sum<<endl; 
	}
}


void ShowMenu() // 菜单
{
    system("Cls");
    puts("                 ************************************************");
    puts("                          学生信息管理（顺序表的应用）         ");
    puts("                 ------------------------------------------------");
    puts("                        请输入您要操作的指令<1-13>：    ");
    puts("                 ------------------------------------------------");
    puts("                              1.在第i个学生之前插入新学生           \n");
    puts("                              2.判断学生表是否为空           \n");
    puts("                              3.求学生表中学生的人数           \n");
    puts("                              4.返回学生表中的第i个学生           \n");
    puts("                              5.返回某姓名学生的前驱           \n");
    puts("                              6.返回某姓名学生的后继           \n");
    puts("                              7.删除学生表的第i个学生           \n");
    puts("                              8.把一个学生表赋值给另外一个学生表           \n");
    puts("                              9.设置学生表为空表           \n");
    puts("                              10.随机生成学生表           \n");
    puts("                              11.用以有的学生表初始化另一个学生表           \n");
    puts("                              12.输入学生表           \n");
    puts("                              13.退出程序           \n");
    puts("                 ************************************************");
}

void ExitSystem() // 退出
{
    system("Cls");
    puts("\n\n\n                 **************************************");
    puts("                               正在退出...          ");
    puts("                 **************************************\n\n\n");
    system("pause");
    exit(0);
}

void InputError() // 输入错误
{
    puts("\n                 **************************************");
    puts("                      您输入的指令有误，请重新输入。   ");
    puts("                 **************************************\n");
}

int main()
{
    int i,k,len;
	char name[10];
	ElemType e,cur_e,pre_e,next_e;
	SqList L,La;
	
	InitList(L);
	InitList(La);

	cout<<"-----------------------------------------------"<<endl;
	cout<<endl;
    
    RandomList(L,len=2);
	PrintList(L);

    cout<<endl;
	cout<<"-----------------------------------------------"<<endl;
	cout<<endl; 

    while(1)
    {
        ShowMenu();
        printf("指令："); scanf("%d", &order);
        if (order == 13) ExitSystem();
        while((order<0)||(order>13))
        {
            ShowMenu();
            InputError();
            printf("指令："); scanf("%d", &order);
        }
        switch (order){
            case 1: 
				cout<<"请输入插入位置i：";
				cin>>i;
				cout<<"请输入要插入元素信息：";
				cin>>e.number>>e.Name>>e.Chinese>>e.English>>e.Math;
				e.Sum=e.Chinese+e.English+e.Math;
				e.Averge=e.Sum/3;
				if(ListInit(L,i,e)) cout<<"插入成功"<<endl;
				else cout<<"操作失败"<<endl;
				PrintList(L);
                break;
            
            case 2:
        		if(EmptyList(L)) cout<<"学生表为空"<<endl;
				else cout<<"学生表非空"<<endl;
				break;

            case 3: 
            	cout<<"学生表中学生的人数："<<ListLength(L)<<endl;
				break;

            case 4:
            	cout<<"请输入你想要取出学生信息的位置i：";
				cin>>i;
				if(GetElem(L,i,e)){
					cout<<"学号:"<<e.number<<"  姓名:"<<e.Name;
					cout<<"  语文:"<<e.Chinese<<"  英语:"<<e.English;
					cout<<"  数学:"<<e.Math<<"  平均分:"<<e.Averge;
					cout<<"  总分:"<<e.Sum<<endl; 
				}
				else cout<<"操作失败"<<endl;
				break;
            
            case 5:
    			cout<<"请输入学生姓名：";
				cin>>name;
				i=PriorElem(L,name);
				if(i){
					cout<<name<<"的前驱是学生表的第"<<i<<"个学生"<<endl;
					cout<<"学号:"<<L.elem[i-1].number<<"  姓名:"<<L.elem[i-1].Name;
					cout<<"  语文:"<<L.elem[i-1].Chinese<<"  英语:"<<L.elem[i-1].English;
					cout<<"  数学:"<<L.elem[i-1].Math<<"  平均分:"<<L.elem[i-1].Averge;
					cout<<"  总分:"<<L.elem[i-1].Sum<<endl; 
				}
				else cout<<"操作失败"<<endl;
				break;

            case 6:
                cout<<"请输入学生姓名：";
				cin>>name;
				i=NextElem(L,name);
				if(i){
					cout<<name<<"的后续是学生表的第"<<i<<"个学生"<<endl;
					cout<<"学号:"<<L.elem[i-1].number<<"  姓名:"<<L.elem[i-1].Name;
					cout<<"  语文:"<<L.elem[i-1].Chinese<<"  英语:"<<L.elem[i-1].English;
					cout<<"  数学:"<<L.elem[i-1].Math<<"  平均分:"<<L.elem[i-1].Averge;
					cout<<"  总分:"<<L.elem[i-1].Sum<<endl; 
				}
				else cout<<"操作失败"<<endl;
				break;

            case 7:
            	cout<<"请输入删除学生序号：";
				cin>>i;
				if(ListDelete(L,i,e)){
					cout<<"删除成功"<<endl;
					cout<<"删除学生信息为："<<endl;
					cout<<"学号:"<<e.number<<"  姓名:"<<e.Name;
					cout<<"  语文:"<<e.Chinese<<"  英语:"<<e.English;
					cout<<"  数学:"<<e.Math<<"  平均分:"<<e.Averge;
					cout<<"  总分:"<<e.Sum<<endl; 
				}
				else cout<<"操作失败"<<endl;
				PrintList(L);
				break;

            case 8:
        		cout<<"现有学生表L："<<endl;
				PrintList(L);
				ListCopy(L,La);
				cout<<"赋值后另一个学生表La："<<endl;
				PrintList(La); 
				break;

            case 9:
            	ClearList(L);
				PrintList(L);
				break;

            case 10:
        		cout<<"请输入顺序表长度："; 
				cin>>len;
				if(len<0) cout<<"操作失败"<<endl; 
				else RandomList(L,len);
				PrintList(L);
				break;

            case 11:
    			SqList Lb;
				Lb.elem=L.elem;
				Lb.length=L.length;
				Lb.listsize=L.listsize;
				cout<<"初始化的学生表Lb如下："<<endl;
				PrintList(Lb);
				break;

            case 12:
            	cout<<"请输入导入学生数：";
				cin>>len;
				InputList(L,len);
				PrintList(L);
				break;
        }
    	cout<<endl; 
		cout<<"-----------------------------------------------"<<endl;
		cout<<endl;
    }
    return 0;
}