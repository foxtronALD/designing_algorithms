#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void countsort(int a[],int n)
{
    int i,j,b[1000];
    
    int c[1000]={0};
    for(i=0;i<n;i++)
        c[a[i]]++;
    for(i=1;i<10;i++)
        c[i]+=c[i-1];
    for(i=0;i<n;i++)
    {
        b[c[a[i]]-1]=a[i];
        c[a[i]]--;
    }
    for(i=0;i<n;i++)
        printf("%d ",b[i]);
}

int main()
{
  int a[1000];
  int i,n;
  printf("Enter number of elements: ");
  scanf("%d",&n);
  printf("Enter the elements:\n");
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  countsort(a,n);
}
