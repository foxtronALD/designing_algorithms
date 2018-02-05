#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
int data;
int freq;
struct node *left,*right;
};
void minheapfy(struct node *pq,int i)
{
    int largest=i,l=2*i+1,r=2*i+2;
    if((l<n)&&(pq[l].freq<pq[largest].freq))
        largest=l;
    if((r<n)&&(pq[r].freq<pq[largest].freq))
        largest=r;
    if(largest!=i)
    {
        struct node tmp;
        /*tmp.data=pq[i].data;
        tmp.freq=pq[i].freq;
        pq[i].data=pq[largest].data;
        pq[i].freq=pq[largest].freq;
        pq[largest].data=tmp
        */
        tmp=pq[i];
        pq[i]=pq[largest];
        pq[largest]=tmp;
        maxheapfy(pq,largest);
    }
}
struct node extractmin(struct node* pq )
{
struct node d=pq[0];
pq[0]=pq[n-1];
n--;
minheapfy(pq,0);
return d;
}
int main()
{
struct node pq[100];
int i;
printf("enter no of elements:\n");
cin>>n;
for(i=0;i<n;i++)
    cin>>pq[i].data>>pq[i].freq;
for(i=n/2-1;i>=0;i--)
{
    minheapfy(pq,i);
}
for(i=0;i<n;i++)
    cout<<pq[i].data<<" "<<pq[i].freq<<endl;
printf("min is : ");
while(n!=1)
{
    struct node x,y,tmp;
    x=extractmin(pq);
    y=extractmin(pq);
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp.data=-1;
    tmp.freq=x.freq+y.freq;
    tmp.left=x;
    tmp.right=y;
}
}
