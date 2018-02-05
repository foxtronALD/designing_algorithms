#include<bits/stdc++.h>
using namespace std;
struct node{
char data;
int freq;
struct node*left,*right;
node(char data,int freq)
{
    left=right=NULL;
    this->data=data;
    this->freq=freq;
}
};
struct compare
{
    bool operator()(node* l,node *r)
    {
        return l->freq > r->freq;
    }
};
void print(struct node* root,string str)
{
    if(!root)
        return ;
    else if(root->data!='#')
    {
        cout<<root->data<<":"<<str<<endl;
    }
    print(root->left,str+"0");
    print(root->right,str+"1");
}
void huffman(char data[],int freq[],int n)
{
    int i;
    struct node *tmp,*left,*right;
    priority_queue<node*,vector<node*>,compare>minheap;
    for(i=0;i<n;i++)
        minheap.push(new node(data[i],freq[i]));
    while(minheap.size()!=1)
    {
        left=minheap.top();
        minheap.pop();
        right=minheap.top();
        minheap.pop();
        tmp=new node('#',left->freq+right->freq);
        tmp->left=left;
        tmp->right=right;
        minheap.push(tmp);
    }
    print(minheap.top(),"");
}
int main()
{
 char data[100];
 int i,n,freq[100];
 printf("enter no of elements : ");
 cin>>n;
 for(i=0;i<n;i++)
    cin>>data[i]>>freq[i];
 huffman(data,freq,n);
 return 0;
}
