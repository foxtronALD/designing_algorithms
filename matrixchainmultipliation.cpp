#include<bits/stdc++.h>
using namespace std;
char
m[1000];
int dp[100][100],b[100][100],p[1000];
void print(int i,int j)
{
    if(i==j)
    {
        cout<<m[i];
        return;
    }
    else
    {
        printf("(");
        print(i,b[i][j]);
        print(b[i][j]+1,j);
        printf(")");
    }
}
int matrix(int i,int j)
{
    int &ans=dp[i][j];
    if(ans)
        return ans;
    if(i==j)
        return ans=0;
    ans=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int q=matrix(i,k)+matrix(k+1,j)+p[i-1]*p[k]*p[j];
        if(q<ans)
        {
            ans=q;
            b[i][j]=k;
        }
    }
    return ans;
}
int main()
{
    int i,n;
    memset(dp,0,sizeof(dp));
    memset(b,0,sizeof(b));
    printf("enter no of matrices : ");
    scanf("%d",&n);
    for(i=0;i<=n;i++)
        scanf("%d",&p[i]);
    for(i=1;i<=n;i++)
        m[i]=(char)(i+64);
    cout<<matrix(1,n)<<endl;
    print(1,n);
}
