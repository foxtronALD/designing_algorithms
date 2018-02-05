#include<bits/stdc++.h>
using namespace std;
int x[1000],n;
void print(void)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(x[i]==j)
                printf("1 ");
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
    cout<<endl;
}
bool issafe(int r,int c)
{
    for(int q=1;q<r;q++)
    {
        if(x[q]==c||(abs(q-r)==abs(c-x[q])))
            return false;
    }
    return true;
}
bool queen(int row)
{
    if(row>n)
        return true;
    for(int col=1;col<=n;col++)
    {
        if(issafe(row,col))
        {
            x[row]=col;
            int sol=queen(row+1);
            if(sol)
                print();
        }
    }
    return false;
}
int main()
{
    printf("enter no of queens : ");
    cin>>n;
    queen(1);
}
