#include<bits/stdc++.h>
using namespace std;
void increasekey(int a[],int n,int idx,int key)
{
    int parent;
    if(a[idx]>=key)
    printf("no can't be increased\n");
    else {
    parent=(idx%2==0)?(idx/2-1):(idx/2);
    a[idx]=key;
    while((idx>=0)&& a[idx]>a[parent])
    {
    swap(a[idx],a[parent]);
    idx=parent;
    }
    }
}
void maxheapfy(int a[],int n,int i)
{
    int largest=i,l=2*i+1,r=2*i+2;
    if((l<n)&&(a[l]>a[largest]))
        largest=l;
    if((r<n)&&(a[r]>a[largest]))
        largest=r;
    if(largest!=i)
    {
        swap(a[i],a[largest]);
        maxheapfy(a,n,largest);
    }
}
void minheapfy(int a[],int n,int i)
{
    int largest=i,l=2*i+1,r=2*i+2;
    if((l<n)&&(a[l]<a[largest]))
        largest=l;
    if((r<n)&&(a[r]<a[largest]))
        largest=r;
    if(largest!=i)
    {
        swap(a[i],a[largest]);
        maxheapfy(a,n,largest);
    }
}
void decreasekey(int a[],int n,int idx,int key)
{
    if(a[idx]<=key)
    printf("no can't be decreased\n");
    else {
        a[idx]=key;
        maxheapfy(a,n,idx);
        }
}
void heapsort(int a[],int n)
{
    int i;
    for(i=n/2-1;i>=0;i--)
    {
        maxheapfy(a,n,i);
    }
    for(i=n-1;i>=0;i--)
    {
        swap(a[0],a[i]);
        maxheapfy(a,i,0);
    }
}
int main()
{
    int i,a[1000],c,n,idx,key,parent;
    printf("enter no of elements: ");
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    //heapsort(a,n);
    for(i=n/2-1;i>=0;i--)
    {
        maxheapfy(a,n,i);
    }
    while(1)
    {
    printf("enter choice : \n");
    printf("1:extract Max\n2:Increase Key\n3:Decrease Key\n4:Delete Key\n5:Insert Key\n6:Display\n7:Exit\n");
    cin>>c;
    switch(c)
    {
    case 1:cout<<a[0]<<endl;
           a[0]=a[n-1];
           n--;
           maxheapfy(a,n,0);
           break;
    case 2:printf("enter index and no to increase : ");
           scanf("%d%d",&idx,&key);
           increasekey(a,n,idx,key);
           break;
    case 3:printf("enter index and no to decrease : ");
           scanf("%d%d",&idx,&key);
           decreasekey(a,n,idx,key);
           break;
    case 4:printf("enter index to delete : ");
           cin>>idx;
           a[idx]=a[n-1];
           maxheapfy(a,n,idx);
           break;
    case 5:printf("enter key to insert : ");
           cin>>key;
           n++;
           a[n-1]=INT_MIN;
           increasekey(a,n,n-1,key);
           break;
    case 6:printf("heap is :\n");
           for(i=0;i<n;i++)
           cout<<a[i]<<" ";
           cout<<endl;
           break;
    case 7:exit(0);
    }
    }
}
