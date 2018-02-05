#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int n,m,t[100][1000],d[100][1000];
string x,y;
int max(int *a,int *b)
{
    return (*a>*b)?*a:*b;
}
void print(int m,int n)
{
    if(m==0||n==0)
        return ;
    else if(t[m][n]==1)
    {
        print(m-1,n-1);
        printf("%c",x[m-1]);
    }
    else if(t[m][n]==2)
    {
        print(m,n-1);
    }
    else
        print(m-1,n);
}
int main()
{
 int i,j;
 printf("enter strings\n");
 cin>>x>>y;
 m=x.size();
 n=y.size();
 for(i=0;i<=m;i++)
 {
     for(j=0;j<=n;j++)
     {
         if(i==0|| j==0)
            t[i][j]=0;
         else if(x[i-1]==y[j-1])
         {
             t[i][j]=t[i-1][j-1]+1;
             d[i][j]=1;
         }
         else{
         if(t[i][j-1]>=t[i-1][j])
         {
         t[i][j]=t[i][j-1];
         d[i][j]=2;
         }
         else
         {
         t[i][j]=t[i-1][j];
         d[i][j]=3;
         }
       }
     }
 }
 printf("lcs is %d\n",t[m][n]);
 print(m,n);
 printf("\n");
}
