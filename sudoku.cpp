#include<bits/stdc++.h>
using namespace std;
int grid[10][10],n;
void print(void)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
            printf("%d ",grid[i][j]);
        cout<<endl;
    }
}
bool check(int &row,int &col)
{
    for(row=0;row<9;row++)
        for(col=0;col<9;col++)
        if(grid[row][col]==0)
        return false;
    return true;
}
bool issafe(int row,int col,int num)
{
    for(int i=0;i<9;i++)
        if(grid[i][col]==num || grid[row][i]==num)
        return false;
    int r=row-row%3;
    int c=col-col%3;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
    {
        if(grid[r+i][c+j]==num)
            return false ;
    }
    return true;
}
bool solvesudoku(void)
{
    int row,col;
    if(check(row,col))
      return true;
    for(int num=1;num <=9;num++)
    {
        if(issafe(row,col,num))
        {
            grid[row][col]=num;
            int sol=solvesudoku();
            if(sol)
                return sol;
        }
    }
    grid[row][col]=0;
    return false;
}
int main()
{
    solvesudoku();
    print();
}
