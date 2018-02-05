#include<bits/stdc++.h>
using namespace std;
int dp[100][100],w[100],r[1000],grid[1000][1000],n,p[100];
void print(int n,int m)
{
    if(n==0||m==0)
        return;
    else if(grid[n][m]==1)
    {
        r[n]=1;
        print(n-1,m-w[n]);
    }
    else
    {
        r[n]=0;
        print(n-1,m);
    }
}
int fun(int i,int c)
{
    int &ans=dp[i][c];
    if(ans)
        return ans;
    if(i==n+1)
        return 0;
    ans=fun(i+1,c);
    if(c>=w[i])
    {
        int q=p[i]+fun(i+1,c-w[i]);
        if(q>ans)
        {
            grid[i][c]=1;
            ans=q;
        }
    }
    return ans;
}
int main()
{
    int i,j,c;
    printf("enter no of elements: ");
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>w[i];
    for(i=1;i<=n;i++)
        cin>>p[i];
    printf("enter capacity of sac : ");
    cin>>c;
    //cout<<fun(1,c)<<endl;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=c;j++)
        {
            if(i==0||j==0)
                dp[i][j]=0;
            else {
                if(w[i]>j)
                    dp[i][j]=dp[i-1][j];
                else
                {
                    int q=p[i]+dp[i-1][j-w[i]];
                    if(q>dp[i-1][j])
                        {dp[i][j]=q;
                         grid[i][j]=1;}
                    else
                        dp[i][j]=dp[i-1][j];
                }
            }
        }
    }
    cout<<dp[n][c]<<endl;
    print(n,c);
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=c;j++)
        cout<<dp[i][j]<<" ";
      cout<<endl;
    }
    for(i=1;i<=n;i++)
        cout<<r[i]<<" ";
    cout<<endl;
}
