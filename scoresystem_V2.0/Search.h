#include "Sort.h"
int Search(long score[],long num[],char name[][MAX_LEN],int n,long numb)
{
    int i;
    SelectionSort(score,num,name,n,Descending);
    for(i=0;i<n;i++)
    {
        if(numb==num[i])
        {
            return i;
        }
    }
    printf("Not found!");
    return -1;
}


int NameSearch(long score[],long num[],char name[][MAX_LEN],int n,char a[])
{
    int i;
    SelectionSort(score,num,name,n,Descending);
    for(i=0;i<n;i++)
    {
        if(strcmp(name[i],a)==0)
        {
            return i;
        }
    }
    puts("Not found!");
    return -1;
}
