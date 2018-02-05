#include<bits/stdc++.h>
using namespace std;
int dp[3000][3000];
int edit(char str1[], char str2[], int m,int n)
{
    int i,j;
    memset(dp,0,sizeof(dp[0][0])*(m+1)*(n+1));
    for(int i=0;i<=m;i++)
            dp[i][0] = i;
    for(int j=0;j<=n;j++)
            dp[0][j] = j;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
    {
        if (str1[i-1]==str2[j-1])
            dp[i][j]=dp[i-1][j-1];
        else
        {
            dp[i][j]=min(min(dp[i-1][j]+1,dp[i][j-1]+1),dp[i-1][j-1]+1);
        }
    }
    return dp[m][n];
}
int main()
{
  int t;
  char str1[3001],str2[3001];
  while(t--)
  {
      scanf("%s%s",str1,str2);
      printf("%d\n",edit(str1,str2,strlen(str1),strlen(str2)));
  }
}
