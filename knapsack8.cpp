#include<bits/stdc++.h>
using namespace std;
stack<pair<int,int> > s;
int cnt,changex[8]={0,0,1,-1,-1,-1,1,1},arr[100][100],vis[100][100],changey[8]={1,-1,0,0,1,-1,-1,1},n,m,b[1000][1000];
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
        cnt++;
        print();
        return ;
    }
    else
    {
        for(int c=0;c<8;c++)
        {
           int xn=x+changex[c];
           int yn=y+changey[c];
           if(issafe(xn,yn))
           {
               vis[xn][yn]=1;
               arr[xn][yn]=1;
               ratmaze(xn,yn);
               vis[xn][yn]=0;
               arr[xn][yn]=0;
           }
        }
    }
    return ;
}
int main()
{
    int i,j;
    printf("enter row and column: ");
    cin>>m>>n;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        cin>>b[i][j];
    cout<<endl;
    vis[0][0]=1;
    ratmaze(0,0);
    cout<<"total paths are : "<<cnt;
    //print();
}
