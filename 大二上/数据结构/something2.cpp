#include <iostream>
#include <stdlib.h>

using namespace std;
#define MAXSIZE 12500
#define ElemType int
#define Status   int
#define OK 1
#define ERROR -1
int dp[MAXSIZE][MAXSIZE];
int dp1[MAXSIZE][MAXSIZE],dp2[MAXSIZE][MAXSIZE];
typedef struct {
    int i,j;
    ElemType e;
}Triple;
typedef struct {
    Triple data[MAXSIZE+1];
    int mu,nu,tu;
}TSMatrix;
 
Status CreatSMatrix(TSMatrix &M){
    M.mu=rand()%7+3;
    M.nu=rand()%10+5;
    M.tu=0;
    int q=1;
    for(int m=1;m<=M.mu;m++){
        for(int n=1;n<=M.nu;n++){
            dp[m][n]=rand()%2;
            if(dp[m][n]==1)dp[m][n]=rand()%100;
            if(dp[m][n]!=0){
                M.data[q].e=dp[m][n];
                M.data[q].i=m;
                M.data[q].j=n;
                q++;
                M.tu++;
            }
        }
    }
    return OK;
}
 
Status SameCreatSMatrix(TSMatrix &M){
    M.mu=7;
    M.nu=13;
    M.tu=0;
    int q=1;
    for(int m=1;m<=M.mu;m++){
        for(int n=1;n<=M.nu;n++){
            dp[m][n]=rand()%2;
            if(dp[m][n]==1)dp[m][n]=rand()%100;
            if(dp[m][n]!=0){
                M.data[q].e=dp[m][n];
                M.data[q].i=m;
                M.data[q].j=n;
                q++;
                M.tu++;
            }
        }
    }
    return OK;
}
 
Status MultXCreatSMatrix(TSMatrix &M){
    M.mu=3;
    M.nu=3;
    M.tu=0;
    int q=1;
    for(int m=1;m<=M.mu;m++){
        for(int n=1;n<=M.nu;n++){
            dp[m][n]=rand()%2;
            if(dp[m][n]==1)dp[m][n]=rand()%10;
            if(dp[m][n]!=0){
                M.data[q].e=dp[m][n];
                M.data[q].i=m;
                M.data[q].j=n;
                q++;
                M.tu++;
            }
        }
    }
    return OK;
}
 
Status MultYCreatSMatrix(TSMatrix &M){
    M.mu=3;
    M.nu=3;
    M.tu=0;
    int q=1;
    for(int m=1;m<=M.mu;m++){
        for(int n=1;n<=M.nu;n++){
            dp[m][n]=rand()%2;
            if(dp[m][n]==1)dp[m][n]=rand()%10;
            if(dp[m][n]!=0){
                M.data[q].e=dp[m][n];
                M.data[q].i=m;
                M.data[q].j=n;
                q++;
                M.tu++;
            }
        }
    }
    return OK;
}
 
Status OutputMatrix(TSMatrix M){
    for(int m=0;m<M.nu;m++){
        cout<<"\t"<<"["<<m<<"]";
    }
    cout<<endl;
    int k=1;
    for(int m=1;m<=M.mu;m++){
        cout<<"["<<m-1<<"]"<<"\t";
        for(int n=1;n<=M.nu;n++){
                if(M.data[k].i==m&&M.data[k].j==n&&k<=M.tu) {
                    cout << M.data[k].e << " " << "\t";
                    k++;
                }
                else cout<<"0"<<" "<<"\t";
        }
        cout<<endl;
    }
    return OK;
}
 
Status TransposeSMatrix(TSMatrix M,TSMatrix &T){
    T.mu=M.nu;
    T.nu=M.mu;
    T.tu=M.tu;
    int q;
    if(T.tu){
        q=1;
        for(int col=1;col<=M.nu;col++){
            for(int p=1;p<=M.tu;p++){
                if(M.data[p].j==col){
                    T.data[q].i=M.data[p].j;
                    T.data[q].j=M.data[p].i;
                    T.data[q].e=M.data[p].e;
                    q++;
                }
            }
        }
    }
    return OK;
}
 
Status FastTransposeSMatrix(TSMatrix M,TSMatrix &T){
    int num[MAXSIZE],col;
    T.mu=M.nu;
    T.nu=M.mu;
    T.tu=M.tu;
    if(T.tu){
        for(col=1;col<=M.nu;col++)num[col]=0;
        for(int t=1;t<=M.tu;t++) ++num[M.data[t].j];
        int cpot[MAXSIZE];
        cpot[1]=1;
        for(col=2;col<=M.nu;col++) cpot[col]=cpot[col-1]+num[col-1];
        for(int p=1;p<=M.tu;p++){
            col=M.data[p].j;
            int q=cpot[col];
            T.data[q].i=M.data[p].j;
            T.data[q].j=M.data[p].i;
            T.data[q].e=M.data[p].e;
            ++cpot[col];
        }
    }
    return OK;
}
 
Status EveryMu(TSMatrix M){
    int p=1;
    for(int col=1;col<=M.mu;col++){
        while(M.data[p].i!=col){
            p++;
        }
        cout<<"稀疏矩阵第"<<col<<"行的第一个非零元素在三元组表中的下标为：";
        cout<<"行："<<col-1<<" 列："<<M.data[p].j-1<<endl;
        p++;
    }
    cout<<endl;
    return OK;
}
 
Status AddSMatrix(TSMatrix X,TSMatrix Y,TSMatrix &Z){
    memset(dp1,0,sizeof(dp1));
    memset(dp2,0,sizeof(dp2));
    int p=1;
    for(int m=1;m<=X.mu;m++){
        for(int n=1;n<=X.nu;n++){
            if(X.data[p].i==m&&X.data[p].j==n&&p<=X.tu){
                dp1[m][n]=X.data[p].e;
                p++;
            }
            else dp1[m][n]=0;
        }
    }
    p=1;
    for(int m=1;m<=Y.mu;m++){
        for(int n=1;n<=Y.nu;n++){
            if(Y.data[p].i==m&&Y.data[p].j==n&&p<=Y.tu){
                dp2[m][n]=Y.data[p].e;
                p++;
            }
            else dp2[m][n]=0;
        }
    }
    for(int m=1;m<=Y.mu;m++){
        for(int n=1;n<=Y.nu;n++){
            dp1[m][n]+=dp2[m][n];
        }
    }
    Z.mu=X.mu;
    Z.nu=X.nu;
    int q=1;
    for(int m=1;m<=Z.mu;m++){
        for(int n=1;n<=Z.nu;n++){
            if(dp[m][n]!=0){
                Z.data[q].e=dp1[m][n];
                Z.data[q].i=m;
                Z.data[q].j=n;
                q++;
                Z.tu++;
            }
        }
    }
    return OK;
}
 
Status PrintThree(TSMatrix M){
    cout<<"------------------"<<endl;
    cout<<"i\tj\te"<<endl;
    cout<<"------------------"<<endl;
    for(int col=1;col<=M.tu;col++){
        cout<<M.data[col].i<<"\t"<<M.data[col].j<<"\t"<<M.data[col].e<<endl;
    }
    cout<<"------------------"<<endl;
    return OK;
}
 
Status MultSMatrix(TSMatrix X,TSMatrix Y,TSMatrix &Z){
    if (X.nu!=Y.mu){ //如果M的列数不等于N的行数
        cout<<"这两个矩阵不能相乘"<<endl;
        return ERROR;
    }
    Z.mu = X.mu;
    Z.nu = Y.nu;
    Z.tu = 0;
    int s1[X.mu][X.nu];
    int s2[Y.mu][Y.nu];
    int s3[Z.mu][Z.nu];
    memset(s1,0,sizeof(s1));
    memset(s2,0,sizeof(s2));
    memset(s3,0,sizeof(s3));
    int p=1;
    for(int m=1;m<=X.mu;m++){
        for(int n=1;n<=X.nu;n++){
            if(X.data[p].i==m&&X.data[p].j==n&&p<=X.tu){
                s1[m][n]=X.data[p].e;
                p++;
            }
            else s1[m][n]=0;
        }
    }
    p=1;
    for(int m=1;m<=Y.mu;m++){
        for(int n=1;n<=Y.nu;n++){
            if(Y.data[p].i==m&&Y.data[p].j==n&&p<=Y.tu){
                s2[m][n]=Y.data[p].e;
                p++;
            }
            else s2[m][n]=0;
        }
    }
    for(int m=1;m<=Z.mu;m++){
        for(int n=1;n<=Z.nu;n++){
            for(int j=1;j<=X.nu;j++){
                s3[m][n]+=s1[m][j]*s2[j][n];
            }
        }
    }
    int q=1;
    for(int m=1;m<=Z.mu;m++){
        for(int n=1;n<=Z.nu;n++){
            if(s3[m][n]!=0){
                Z.data[q].e=s3[m][n];
                Z.data[q].i=m;
                Z.data[q].j=n;
                q++;
                Z.tu++;
            }
        }
    }
    return OK;
}
 
Status Menus(){
    cout<<"1.求稀疏矩阵的转置矩阵"<<endl;
    cout<<"2.快速求稀疏矩阵的转置矩阵"<<endl;
    cout<<"3.计算稀疏矩阵各行第一个非零元素在三元组表中的下标"<<endl;
    cout<<"4.求稀疏矩阵的加法"<<endl;
    cout<<"5.求稀疏矩阵的乘积"<<endl;
    cout<<"6.显示稀疏矩阵的三元组表示"<<endl;
    cout<<"7.随机生成稀疏矩阵"<<endl;
    cout<<"0.退出程序"<<endl;
    cout<<"请输入你要执行的序号："<<endl;
    int n;
    cin>>n;
    return n;
}
 
int main(){
    srand(time(0));
    TSMatrix M;
    CreatSMatrix(M);
    OutputMatrix(M);
    int problem=Menus();
    while(problem){
        if(problem==1){
            TSMatrix T;
            TransposeSMatrix(M,T);
            OutputMatrix(T);
        }
        else if(problem==2){
            TSMatrix T;
            FastTransposeSMatrix(M,T);
            OutputMatrix(T);
        }
        else if(problem==3){
            EveryMu(M);
        }
        else if(problem==4){
            TSMatrix X,Y,Z;
            cout<<"X矩阵："<<endl;
            SameCreatSMatrix(X);
            OutputMatrix(X);
            cout<<endl<<"Y矩阵："<<endl;
            SameCreatSMatrix(Y);
            OutputMatrix(Y);
            cout<<"随机生成两个行数、列数相等的稀疏矩阵,加法运算后得到矩阵 X+Y=Z  :"<<endl;
            AddSMatrix(X,Y,Z);
            OutputMatrix(Z);
        }
        else if(problem==5){
            TSMatrix X,Y,Z;
            cout<<"X矩阵："<<endl;
            MultXCreatSMatrix(X);
            OutputMatrix(X);
            cout<<endl<<"Y矩阵："<<endl;
            MultYCreatSMatrix(Y);
            OutputMatrix(Y);
            cout<<"随机生成两个稀疏矩阵(X的列数等于Y的行数),乘法运算后得到矩阵 X*Y=Z  :"<<endl;
            MultSMatrix(X,Y,Z);
            OutputMatrix(Z);
        }
        else if(problem==6){
            PrintThree(M);
        }
        else if(problem==7){
            CreatSMatrix(M);
            OutputMatrix(M);
        }
        problem=Menus();
    }
    return OK;
}
