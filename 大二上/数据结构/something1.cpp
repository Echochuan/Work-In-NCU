#include <iostream>
#include <stdlib.h>

using namespace std;
#define MAXSIZE 100
#define QElemType int
#define Status    int
#define ERROR -1
#define OK     1
typedef struct {
    QElemType *base;
    int front;
    int rear;
} SqQueue;
 
Status InitQueue(SqQueue &Q) {
    Q.base = (QElemType *) malloc(MAXSIZE * sizeof(QElemType));
    if (! Q.base)exit(0);
    Q.front = Q.rear = 0;
    return OK;
}
 
Status InQueue(SqQueue &Q, int num) {
    if (num > 100) {
        cout << "超出空间" << endl;
        return ERROR;
    }
    while (num --) {
        Q.base[Q.rear] = rand() % 100 + 1;
        Q.rear = (Q.rear + 1) % MAXSIZE;
    }
    return OK;
}
 
Status OutQueue(SqQueue Q) {
    int k = 0;
    SqQueue p;
    p.front = Q.front;
    while (p.front != Q.rear) {
        p.front = (p.front + 1) % MAXSIZE;
        k ++;
    }
    for (int i = 0; i < k + 1; i ++) {
        cout << "[" << i << "]" << "\t";
    }
    cout << endl;
    p.front = Q.front;
    for (int i = 0; i < k - 1; i ++) {
        cout << Q.base[p.front] << "\t";
        p.front=(p.front+1)%MAXSIZE;
    }
    cout << endl;
    cout << " ^";
    for (int i = 0; i < k - 1; i ++) {
        cout << "\t ";
    }
    cout << " ^";
    cout << endl;
    cout << " |";
    for (int i = 0; i < k - 1; i ++) {
        cout << "\t ";
    }
    cout << " |";
    cout << endl;
    cout << "front";
    for (int i = 0; i < k - 1; i ++) {
        cout << "\t ";
    }
    cout << "rear";
    cout<<endl;
    return OK;
}
 
Status EnQueue(SqQueue &Q, QElemType e) {
    if ((Q.rear + 1) % MAXSIZE == Q.front)return ERROR;
    Q.base[Q.rear-1] = e;
    Q.rear = (Q.rear + 1) % MAXSIZE;
    return OK;
}
 
Status DeQueue(SqQueue &Q) {
    if (Q.front == Q.rear)return ERROR;
    Q.front = (Q.front + 1) % MAXSIZE;
    return OK;
}
 
Status Gethead(SqQueue Q) {
    if (Q.front == Q.rear)return ERROR;
    QElemType e;
    e = Q.base[Q.front];
    return e;
}
 
Status EmptyQueue(SqQueue Q) {
    if(Q.front==Q.rear&&!Q.front)cout<<"循环队列为空"<<endl;
    else cout<<"循环队列不为空"<<endl;
    return OK;
}
 
Status FillQueue(SqQueue Q) {
    if((Q.rear==Q.front&&Q.front))cout<<"循环队列已满"<<endl;
    else cout<<"循环队列不满"<<endl;
    return OK;
}
 
Status QueueLength(SqQueue Q) {
    int k;
    if(Q.front==Q.rear&&Q.base[Q.front]){
        k=MAXSIZE;
    }
    else if(Q.front==Q.rear&&!Q.base[Q.front]){
        k=0;
    }
    else k=(Q.rear-Q.front-1+MAXSIZE)%MAXSIZE;
    return k;
}
 
Status ClearQueue(SqQueue &Q) {
    Q.front=Q.rear=0;
    Q.base[Q.front]=NULL;
    return OK;
}
 
Status Menus() {
    cout << "1.进队列（循环队列队尾插入元素）" << endl;
    cout << "2.出队列（循环队列队头删除元素）" << endl;
    cout << "3.读循环队列队头元素到e" << endl;
    cout << "4.判断循环队列是否为空" << endl;
    cout << "5.判断循环队列是否已满" << endl;
    cout << "6.求循环队列中元素的个数" << endl;
    cout << "7.把一个循环队列赋值给另一个循环队列" << endl;
    cout << "8.把循环队列置空" << endl;
    cout << "9.随机生成循环队列" << endl;
    cout << "0.推出程序" << endl;
    cout << "请输入你要进行的操作" << endl;
    int n;
    cin >> n;
    return n;
}
 
int main() {
    SqQueue Q,M;
    InitQueue(Q);
    int num, problem;
    srand(time(0));
    num = rand() % 10 + 5;
    InQueue(Q, num);
    OutQueue(Q);
    problem = Menus();
    while (problem) {
        if (problem == 1) {
            QElemType e;
            cout << "请输入插入的元素值" << endl;
            cin >> e;
            EnQueue(Q, e);
            OutQueue(Q);
        } else if (problem == 2) {
            DeQueue(Q);
            cout << "删除循环队列队头成功" << endl;
            OutQueue(Q);
        } else if (problem == 3) {
            cout << "队头元素为" << Gethead(Q) << endl;
        } else if (problem == 4) {
            EmptyQueue(Q);
        } else if (problem == 5) {
            FillQueue(Q);
        } else if (problem == 6) {
            cout<<"循环队列的元素个数为："<<QueueLength(Q)<<endl;
        } else if (problem == 7) {
            cout<<"已经将循环队列Q赋值给循环队列M，下面打印M"<<endl;
            InitQueue(M);
            SqQueue p;
            p.front=Q.front;
            while(p.front!=Q.rear){
                M.base[M.rear]=Q.base[p.front];
                p.front=(p.front+1)%MAXSIZE;
                M.rear=(M.rear+1)%MAXSIZE;
            }
            OutQueue(M);
        } else if (problem == 8) {
            cout<<"循环队列已经置空"<<endl;
            ClearQueue(Q);
        } else if (problem == 9) {
            srand(time(0));
            num = rand() % 10 + 5;
            InQueue(Q, num);
            OutQueue(Q);
        }
            problem = Menus();
    }
}
