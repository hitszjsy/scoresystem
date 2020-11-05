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


void SortString(long score[][MAX_COURSE],long num[],char name[][MAX_LEN],int n,int c)
{
    int i,j;
    char temp[MAX_LEN];
    long s[MAX_COURSE];
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strcmp(name[i],name[j])>0)
            {
                strcpy(temp,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],temp);
                CopyArray(s,score[i],c);
                CopyArray(score[i],score[j],c);
                CopyArray(score[j],s,c);
                Swap(&num[i],&num[j]);
            }
        }
    }
}

void SortByNum(long num[],long score[][MAX_COURSE],char name[][MAX_LEN],int n,int c)
{
    int i,j;
    char temp[MAX_LEN];
    long s[MAX_COURSE];
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(num[j]<num[i])
            {
                strcpy(temp,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],temp);
                CopyArray(s,score[i],c);
                CopyArray(score[i],score[j],c);
                CopyArray(score[j],s,c);
                Swap(&num[i],&num[j]);
            }
        }
    }
}
