#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
void heapfy(int a[],int n,int i)
{
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && a[largest]<a[l])
    {
        largest=l;
    }
    if(r<n && a[largest]<a[r])
    {
        largest=r;
    }
    if(largest!=i)
    {
        swap(&a[i],&a[largest]);
        heapfy(a,n,largest);
    }
}
void heapsort(int a[],int n)
{
    int i;
    for(i=n/2-1;i>=0;i--)
        heapfy(a,n,i);
    for(i=n-1;i>=0;i--)
    {
        swap(&a[0],&a[i]);
        heapfy(a,i,0);
    }
}
int main()
{
  int a[1000];
  int i,n;
  printf("enter no of elements: ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  heapsort(a,n);
  for(i=0;i<n;i++)
    printf("%d ",a[i]);
}
