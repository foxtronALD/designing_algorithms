#include<bits/stdc++.h>
using namespace std;
vector<int> s;
int n;
void printsol(void)
{
     vector<int> ::iterator it;
     for(it=s.begin();it!=s.end();it++)
        cout<<*it<<" ";
    printf("\n");
}
void subset(int sum,int total,int a[],int i)
{
    if(i>n)
        return;
    else if(total==sum)
    {
        printsol();
        return;
    }
    for(int j=i;j<n;j++)
    if(total+a[j]<=sum)
    {
        s.push_back(a[j]);
        total+=a[j];
        subset(sum,total,a,j+1);
        s.pop_back();
        total-=a[j];
    }
}
int main()
{
    int sum,a[100],i;
    printf("enter no of elements:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("enter required sum\n");
    scanf("%d",&sum);
    subset(sum,0,a,0);
}
