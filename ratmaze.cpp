#include<bits/stdc++.h>
using namespace std;
stack<pair<int,int> > s;
int changex[4],arr[100][100],vis[100][100],changey[4],n,m,b[1000][1000];
bool issafe(int i,int j)
{
    if(i>m || j>n || b[i][j]==0||i<0||j<0||vis[i][j]==1)
        return false;
    else return true;
}
void print(void)
{
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
    {
        if(i==0&&j==0)
            cout<<"1 ";
        else if(arr[i][j]==1)
            cout<<"1 ";
        else cout<<"0 ";
    }
    cout<<endl;
    }
    cout<<endl;
}
void ratmaze(int x,int y)
{
    if(x==m-1 && y==n-1)
    {
        print();
        return ;
    }
    else
    {
        for(int c=0;c<4;c++)
        {
           int xn=x+changex[c];
           int yn=y+changey[c];
           vis[xn][yn]=1;
           if(issafe(xn,yn))
           {
               arr[xn][yn]=1;
               ratmaze(xn,yn);
           }
        }
    }
    arr[x][y]=0;
}
int main()
{
    int i,j;
    changex[0]=1;
    changex[1]=0;
    changex[2]=-1;
    changex[3]=0;
    changey[0]=0;
    changey[1]=1;
    changey[2]=0;
    changey[3]=-1;
    printf("enter row and column: ");
    cin>>m>>n;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        cin>>b[i][j];
    ratmaze(0,0);
    //print();
}
