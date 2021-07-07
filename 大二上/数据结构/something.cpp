#include <iostream>
#include <stdlib.h>

using namespace std;
typedef int SElemtype;
typedef int Status;
#define STACK_INIT_SIZE 100
#define OK 1
#define ERROR -1
#define STACKINCREMENT 10
typedef struct {
    SElemtype *base;
    SElemtype *top;
    int stacksize;
} SqStack;

Status InitStack(SqStack *S) {
    S->base = (SElemtype *) malloc(STACK_INIT_SIZE * sizeof(SElemtype));
    if (! S->base) {
        cout << "存储空间分配失败" << endl;
        return ERROR;
    }
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return OK;
}

Status GetTop(SqStack *S) {
    SElemtype e;
    if (S->top == S->base) {
        cout << "栈空,无法返回." << endl;
        return ERROR;
    }
    e = *(S->top - 1);
    cout<<"栈顶结点的数据域为"<<e<<endl;
    return OK;
}

Status Push(SqStack *S, SElemtype e) {
    if (S->top - S->base >= S->stacksize){
        S->base = (SElemtype *) realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemtype));//增加容量
        if (! S->base)
            exit(0);//存储分配失败
        S->top = S->base + S->stacksize;//更新栈顶指针
        S->stacksize += STACKINCREMENT;//更新栈容量
    }
    *S->top ++ = e;//栈顶数据变为e
    return OK;
}

Status pop(SqStack *S){
    SElemtype e;
    if(S->top==S->base){
        cout<<"删除有误."<<endl;
        exit(0);
    }
    else{
        e=*--S->top;
        cout<<"弹出数据为："<<e<<endl;
    }
    return OK;
}

Status Empty(SqStack *S){
    S->top=S->base;
    return OK;
}

Status Ifempty(SqStack *S){
    if(S->base==S->top)cout<<"链栈为空"<<endl;
    else cout<<"链栈不为空"<<endl;
    return OK;
}

Status Num(SqStack *S){
    int k=0;
    SElemtype *p;
    p=S->base;
    while(p!=S->top){
        k++;
        p++;
    }
    return k;
}

Status ShowStack(SqStack *S){
    SElemtype *p;
    p=S->top;
    while(p!=S->base){
        cout<<*--p;
        if(p!=S->base)cout<<"->\t";
    }
    cout<<"^";
    cout<<endl;
    cout<<" ^"<<endl;
    cout<<" |"<<endl;
    cout<<"top"<<endl;
    return OK;
}

Status In(SqStack *S,int num){
    Empty(S);
    srand(time(0));
    while(num--){
        *S->top= rand() % 100 + 1;
        S->top++;
    }
    ShowStack(S);
    return OK;
}

Status Visit(SqStack *S,SqStack *M){
    SElemtype *p;
    p=S->base;
    while(p!=S->top){
        *M->top=*p++;
        M->top++;
    }
    return OK;
}
Status Menus(){
    cout<<"1.在栈顶压入一个数据域为e的结点"<<endl;
    cout<<"2.弹出栈顶结点"<<endl;
    cout<<"3.读栈顶结点的数据域"<<endl;
    cout<<"4.判断链栈是否为空"<<endl;
    cout<<"5.求链栈中结点的个数"<<endl;
    cout<<"6.把一个链栈赋值给另一个链栈"<<endl;
    cout<<"7.把链栈置空"<<endl;
    cout<<"8.随机生成链栈"<<endl;
    cout<<"0.推出程序"<<endl;
    cout<<"请输入你要执行的操作序号："<<endl;
    int n;
    cin>>n;
    return n;
}
int main(){
    SqStack S;
    int problem;
    InitStack(&S) ;
    int ss;
    ss=rand()%10+5;
    In(&S,ss);
    problem=Menus();
    while(problem){
        if(problem==1){
            SElemtype e;
            cout<<"请输入你要压入的元素e"<<endl;
            cin>>e;
            Push(&S, e);
            ShowStack(&S);
        }
        else if(problem==2){
            pop(&S);
            cout<<"弹出后链栈为："<<endl;
            ShowStack(&S);
        }
        else if(problem==3){
            GetTop(&S);
        }
        else if(problem==4){
            Ifempty(&S);
        }
        else if(problem==5){
            int k;
            k=Num(&S);
            cout<<"链栈中结点的个数为："<<k<<endl;
        }
        else if(problem==6){
            SqStack M;
            InitStack(&M) ;
            Visit(&S,&M);
            cout<<"已经将S链栈赋值给M链栈,下面打印M链栈"<<endl;
            ShowStack(&M);
        }
        else if(problem==7){
            Empty(&S);
            cout<<"链栈已经置空"<<endl;
        }
        else if(problem==8){
            int num;
            srand(time(0));
            num=rand()%10+5;
            In(&S,num);
        }
        problem=Menus();
    }
    return 0;
}
