#include "Swap.h"
#include <string.h>
void SelectionSort(long a[],long b[],char name[][MAX_LEN],int n,int (*compare)(long x,long y))
{
    int i,j,k;
    char temp[MAX_LEN];
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if((*compare)(a[j],a[k])) k=j;
        }
        if(k!=i)
        {
            Swap(&a[k],&a[i]);
            Swap(&b[k],&b[i]);
            strcpy(temp,name[i]);
            strcpy(name[i],name[k]);
            strcpy(name[k],temp);
        }
    }
}


int Ascending(long a,long b)
{
    return a<b;
}


int Descending(long a,long b)
{
    return a>b;
}


void SortString(long score[],long num[],char name[][MAX_LEN],int n)
{
    int i,j;
    char temp[MAX_LEN];
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strcmp(name[i],name[j])>0)
            {
                strcpy(temp,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],temp);
                Swap(&score[i],&score[j]);
                Swap(&num[i],&num[j]);
            }
        }
    }
}
