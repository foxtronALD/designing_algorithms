#include<bits/stdc++.h>
using namespace std;
int m,n,adj[1000][1000],v[100];
bool issafe(int p,int c)
{
    int i;
    for(i=0;i<n;i++)
        if(p!=i)
        if(adj[p][i] && v[i]==c)
        return false;
    return true;
}
bool mcoloring(int p)
{
    if(p==n)
        return true;
    for(int c=1;c<=m;c++)
    {
        if(issafe(p,c))
        {
            v[p]=c;
            int sol=mcoloring(p+1);
            if(sol)
                return sol;
        }
    }
    v[p]=0;
    return false;
}
int main()
{
    int i,j;
    printf("enter no of row \n");
    cin>>n;
    cout<<"enter adjacency matrix : \n";
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        cin>>adj[i][j];
    printf("enter no of color\n");
    cin>>m;
    mcoloring(0);
    for(i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
