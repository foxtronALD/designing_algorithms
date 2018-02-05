#include<stdio.h>
#include<math.h>
#include<string.h>
struct point{
int index;
char text[20];
};
int comp(const void* aa,const void* bb)
{
    struct point *a=(struct point *)aa;
    struct point *b=(struct point *)bb;
    return strcmp(a->text,b->text);
}
void fun(char *s)
{
    int i,n=strlen(s);
    struct point suffix[n+1];
    for(i=0;i<n;i++)
    {
        suffix[i].index=i;
        strcpy(suffix[i].text,(s+i));
        printf("%s\n",suffix[i].text);
    }
    qsort(suffix,n,sizeof(suffix[0]),comp);
    printf("wf");
    for(i=0;i<n;i++)
        printf("%d ",suffix[i].index);
    printf("\n");
}
int main()
{
    char s[100];
    printf("enter text: ");
    scanf("%s",s);
    fun(s);
}
