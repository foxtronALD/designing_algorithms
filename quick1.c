#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int partition(int a[],int l,int u)
{
    int p=l-1;
    int key=a[u],j,i;
    for(j=l;j<u;j++)
    {
        if(a[j]<key)
        {
            p++;
            int t=a[j];
            a[j]=a[p];
            a[p]=t;
        }
    }
    int t=a[u];
    a[u]=a[p+1];
    a[p+1]=t;
    return p+1;
}
void quicksort(int a[],int l,int u)
{
    if(l<u)
    {
        int pivot=partition(a,l,u);
        quicksort(a,l,pivot-1);
        quicksort(a,pivot+1,u);
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
  quicksort(a,0,n-1);
  for(i=0;i<n;i++)
    printf("%d ",a[i]);
}
