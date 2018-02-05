#include<bits/stdc++.h>
using namespace std;
int n,a[1000];
int solve (int curr,int last)
{
    int ans=0;
    if(curr==n)
        return 0;
    ans=max(ans,solve(curr+1,last));
    if(last==-1||a[curr]>a[last])
        ans=max(ans,1+solve(curr+1,curr));
    return ans;
}
int main()
{
        int i,j,lis[1000],m=INT_MIN;
        cin>>n;
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<n;i++)
            lis[i]=1;
        for(i=1;i<=n;i++)
            for(j=0;j<i;j++)
        {
            if(a[i]>a[j] && lis[i]<lis[j]+1)
                lis[i]=lis[j]+1;
        }
        stack<int> s;
        for(i=0;i<n;i++)
            m=max(lis[i],m);
        for(i=n-1;i>=0;i--)
          if(lis[i]==m)
        {
            s.push(a[i]);
            m--;
        }
        while(!s.empty())
        {
            cout<<s.top()<<" ";
            s.pop();
        }
}
