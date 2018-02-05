#include<stdio.h>
int a[1000];
int randompartition(int l,int u)
{
    int q=rand()%(u-l)+l;
    int t=a[q],j;
    a[q]=a[u];
    a[u]=t;
    printf("q=%d\n",q);
    int p=l-1;
    int key=a[u];
    for(j=l;j<u;j++)
    {
        if(a[j]<key)
        {
            p++;
            int t=a[p];
            a[p]=a[j];
            a[j]=t;
        }
    }
    t=a[p+1];
    a[p+1]=a[u];
    a[u]=t;
    return p+1;
}
int quick(int l,int u,int i)
{
    if(l<=u)
    {
        if(l==u)
            return a[l];
        int q=randompartition(l,u);
        int ap=q-l+1;
        if(ap==i)
            return a[q];
        else if(ap>i)
            return quick(l,q-1,i);
        else
            return quick(q+1,u,i-ap);
    }
}
int main()
{
    int n,i,j;
    printf("enter no of elements : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    while(1){
    printf("enter i : ");
    scanf("%d",&i);
    printf("%d\n",quick(0,n-1,i));
    }
}
