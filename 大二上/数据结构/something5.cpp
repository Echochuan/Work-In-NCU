// #include <stdio.h>
// int insort(int s[], int n)
// {
//     int i,j;
//     for(i=2;i<=n;i++)    //数组下标从2开始，s[0]做监视哨
//     {
//         s[0]=s[i];    //给监视哨陚值
//         j=i-1;    //确定要比较元素的最右位置
//         while(s[0]<s[j])
//         {
//             s[j+1]=s[j];
//             j--;
//         }
//         s[j+1]=s[0];    //在确定的位置插入s[i]
//     }
//     return 0;
// }
// int main()
// {
//     int a[11],i;
//     printf("请输入10个数据：\n");
//     for (i =1;i<=10;i++)
//         scanf("%d",&a[i]);
//     printf("你输入的数据是：\n");
//     for(i=1;i<11;i++)
//         printf("%5d",a[i]);

//     insort(a,10);
//     printf("\n 使用直接插入排序：\n");
//     for(i=1;i<11;i++)
//         printf("%5d",a[i]);

//     printf("\n");
//     return 0;
// }

// #include <stdio.h>
// void print(int a[], int n ,int i){
//     printf("%d:",i);
//     for(int j=0; j<n; j++){
//         printf("%d",a[j]);
//     }
//     printf("\n");
// }
// void BInsertSort(int a[],int size){
//     int i,j,low = 0,high = 0,mid;
//     int temp = 0;
//     for (i=1; i<size; i++) {
//         low=0;
//         high=i-1;
//         temp=a[i];
//         while (low<=high) {
//             mid=(low+high)/2;
//             if (a[mid]>temp) {
//                 high=mid-1;
//             }else{
//                 low=mid+1;
//             }
//         }
//         for (j=i; j>low; j--) {
//             a[j]=a[j-1];
//         }
//         a[low]=temp;
//         printf("\n");
//         printf("按照折半输入排序:\n");
//         print(a, 10, i);
//     }
   
// }
// int main(){
//     int a[11],i;
//     printf("请输入10个数据：\n");
//     for (i =1;i<=10;i++)
//         scanf("%d",&a[i]);
//     printf("你输入的数据是：\n");
//     for(i=1;i<11;i++)
//         printf("%5d",a[i]);

//     BInsertSort(a, 10);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
 
// void ListinsertSort(int * v, int n)
//  {
// 	int * link = (int *)malloc(sizeof(int)*n);
// 	int head =0;
// 	int  next,cur,i;
// 	link[0] = -1;
// 	for (i = 1 ; i < n; i++){
// 		   if (v[head] > v[i]){
// 			   link[i] = head;
// 			   head = i;
// 			} else {
// 				   for (cur = head ; cur != -1 && v[cur] <= v[i]; cur = link[cur])
// 						  next =cur;
// 				   link[next] = i;
// 				   link[i] = cur;
// 			}
// 	}
// 	cur = head;
// 	for ( i = 0 ;i < n;i++){
// 		while(cur < i)
// 			 cur = link [cur];
// 		next = link[cur];
// 		if (cur != i) {
// 			int swap = v[i];
// 			v[i] = v[cur];
// 			v[cur] = swap;
// 			link[cur] = link[i];
// 			link[i] = cur;
// 		}
// 		cur = next;
// 	}
// 	free(link);
//  }
 
// int main(void) {
// 	int i;
// 	int* a = (int *)malloc(sizeof(int)*10);
//     printf("请输入10个数据：\n");
//     for (i =1;i<=10;i++)
//         scanf("%d",&a[i]);
//     printf("你输入的数据是：\n");
//     for(i=1;i<11;i++)
//         printf("%5d",a[i]);
 
// 	ListinsertSort(a, 10);
//     printf("\n进行静态链表输入排序:\n");
 
// 	for(i=0;i<10;i++){
// 	    printf(" %d",a[i]);
// 	}
// 	free(a);
//     return 0;
// }

// #include <stdio.h>
// int hxsort(int s[], int n)
// {
//     int i,j,d;
//     d=n/2;
//     while(d>=1)
//     {
//         for(i=d+1;i<=n;i++)
//         {
//             s[0]=s[i];  //设置监视哨
//             j=i-d;
//             while((j>0)&&(s[0]<s[j]))
//             {
//                 s[j+d]=s[j];
//                 j=j-d;
//             }
//             s[j + d]=s[0];
//         }
//         d = d/2;
//     }
// return 0;
// }
// int main()
// {
//     int a[11],i;
//     printf("请输入 10 个数据：\n");
//     for(i=1;i<=10;i++)
//     scanf("%d",&a[i]);
//     hxsort(a, 10);
//     printf("排序后的顺序是：\n");
//     for(i=1;i<=10;i++)
//     printf("%5d",a[i]);
//     printf("\n");
//     return 0;
// }

// # include <stdio.h>
// int main(void)
// {
//     int a[] = {90, 25, 323, -8, -34, 96, 43, 2, 65, -7, 60, -100, 45, 23, 250};
//     int n; 
//     int i; 
//     int j; 
//     int buf; 
//     n = sizeof(a) / sizeof(a[0]); 
//     for (i=0; i<n-1; ++i)
//     {
//         for (j=0; j<n-1-i; ++j)
//         {
//             if (a[j] < a[j+1])
//             {
//                 buf = a[j];
//                 a[j] = a[j+1];
//                 a[j+1] = buf;
//             }
//         }
//     }
//     for (i=0; i<n; ++i)
//     {
//         printf("%d\x20", a[i]);
//     }
//     printf("\n");
//     return 0;
// }


// #include <stdio.h>
// void Swap(int *, int *);
// void QuickSort(int *, int, int);
// int main(void)
// {
//     int i; 
//     int a[] = {900, 2, -58, 3, 34, 5, 76, 7, 32, 4, 43, 9, 1, 56, 8,-70, 635, -234, 532, 543, 2500};
//     QuickSort(a, 0, 20);
//     printf("最终排序结果为:\n");
//     for (i=0; i<21; ++i)
//     {
//         printf("%d ", a[i]);
//     }
//     printf("\n");
//     return 0;
// }
// void Swap(int *p, int *q)
// {
//     int buf;
//     buf = *p;
//     *p = *q;
//     *q = buf;
//     return;
// }
// void QuickSort(int *a, int low, int high)
// {
//     int i = low;
//     int j = high;
//     int key = a[low];
//     if (low >= high)
//     {
//         return ;
//     }
//     while (low < high)
//     {
//         while (low < high && key <= a[high])
//         {
//             --high;
//         }
//         if (key > a[high])
//         {
//             Swap(&a[low], &a[high]);
//             ++low;
//         }
//         while (low < high && key >= a[low])
//         {
//             ++low;
//         }
//         if (key < a[low])
//         {
//             Swap(&a[low], &a[high]);
//             --high;
//         }
//     }
//     QuickSort(a, i, low-1);
//     QuickSort(a, low+1, j);
// }
// #include <stdio.h>
// #include <stdlib.h>
// #define MAX 9

// typedef struct {
//     int key;
// }SqNote;

// typedef struct {
//     SqNote r[MAX];
//     int length;
// }SqList;

// void HeapAdjust(SqList * H,int s,int m){
//     SqNote rc=H->r[s];
//     for (int j=2*s; j<=m; j*=2) {
//         if (j+1<m && (H->r[j].key<H->r[j+1].key)) {
//             j++;
//         }
//         if (!(rc.key<H->r[j].key)) {
//             break;
//         }
//         H->r[s]=H->r[j];
//         s=j;
//     }
//     H->r[s]=rc;
// }

// void swap(SqNote *a,SqNote *b){
//     int key=a->key;
//     a->key=b->key;
//     b->key=key;
// }
// void HeapSort(SqList *H){
//     for (int i=H->length/2; i>0; i--) {
//         HeapAdjust(H, i, H->length);
//     }

//     for (int i=H->length; i>1; i--) {
//         swap(&(H->r[1]), &(H->r[i]));
//         HeapAdjust(H, 1, i-1);
//     }
// }
// int main() {
//     SqList * L=(SqList*)malloc(sizeof(SqList));
//     L->length=8;
//     L->r[1].key=80;
//     L->r[2].key=26;
//     L->r[3].key=74;
//     L->r[4].key=23;
//     L->r[5].key=45;
//     L->r[6].key=26;
//     L->r[7].key=57;
//     L->r[8].key=34;
//     HeapSort(L);
//     for (int i=1; i<=L->length; i++) {
//         printf("%d ",L->r[i].key);
//     }
//     return 0;
// // }
// #include<cstdio>
// #include<iostream>
// #include<algorithm>
// #include<cstring>
// using namespace std;
 
// void merge(int a[],int l,int r,int mid)
// {
//   int aux[r-l+1],i,j,k;
//   for(k=l;k<=r;k++)
//   aux[k-l]=a[k];
//   i=l;
//   j=mid+1;
//   for(k=l;k<=r;k++)
//   {
//   	if(i>mid)
//   	{
//   		a[k]=aux[j-l];
//   		j++;
// 	  }
// 	else if(j>r)
// 	{
// 		a[k]=aux[i-l];
// 		i++;
// 	  }
// 	else if(aux[i-l]>aux[j-l])
// 	{
// 		a[k]=aux[j-l];
// 		j++;
// 		}
// 	else
// 	{
// 		a[k]=aux[i-l];
// 		i++;
// 			}
// 	  }	
	
// }
 
// void merge_sort(int a[],int l,int r)
// {
//     if(l>=r)
// 	return ;	
// 	int mid=(l+r)/2;
// 	merge_sort(a,l,mid);
// 	merge_sort(a,mid+1,r);
// 	merge(a,l,r,mid);	
	
// }
 
 
// void mergesort(int a[],int l,int r)
// {
// 	merge_sort(a,l,r-1);
// }
 
// int main()
// {
// 	int a[11],n,i;
//     printf("输入需排序的十个数\n");
// 	for(i=0;i<10;i++)
// 	scanf("%d",&a[i]);
	
// 	mergesort(a,0,10);

// 	for(i=0;i<10;i++)
// 	printf("%d ",a[i]);

// 	return 0;
//  } 

#include<cstdio>
#include<cstdlib>
using namespace std;
 
typedef struct node{              
	int data;                       
	int next;                   
}Node;
 
int data[101];                     
Node bucket[10];                  
Node d[101];                     
int n;                   
 
int getdigit(){               
	int max=1;
	for(int i=0;i<n;i++){
		int x=data[i];
		int num=1;
		while(x/10){
			x/=10;
			num++;
		}
		if(num>max)
			max=num;
	}
	return max;
}
 
void init(){                    
	for(int i=0;i<10;i++){
		bucket[i].data=i;
		bucket[i].next=-1;
	}
	for(int i=0;i<n;i++){
		d[i].data=data[i];       
		d[i].next=-1;
	}
}
 
void Radixsort(){
	int digit=getdigit();         
	int key=1;
	for(int i=0;i<digit;i++){     
		init();
		for(int i=n-1;i>=0;i--){
			int a=(d[i].data/key)%10;
			d[i].next=bucket[a].next;
			bucket[a].next=i;
		}
		int b=0;                  
		for(int i=0;i<10;i++){
			if(bucket[i].next!=-1){
				int p=bucket[i].next;
				data[b++]=d[p].data;
				while(d[p].next!=-1){
					data[b++]=d[d[p].next].data;
					p=d[p].next;
				}
			}
		}
		key*=10;
	}
}
 
void print(){
	for(int i=0;i<n;i++)
		printf("%d ",data[i]);
	printf("\n");
}
 
int main(){
	printf("Please input the size of array:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&data[i]);
	Radixsort();
	print();
	return 0;	
}
 