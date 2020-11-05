#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 20
#define N 30
#include "ReadData.h"
#include "CopyScore.h"
#include "Sumarray.h"
#include "Printscore.h"
#include "statistics.h"
#include "Search.h"

int main()
{
    int n,ret,m,sum,average,rank;
    long num[N],orgnum[N],score[N],orgscore[N],numb;
    char name[N][MAX_LEN],nam[MAX_LEN];
    puts("Welcome to use our system V2.0!");

    do
    {
        printf("\n1.Input record\n2.Calculate total and average score\n"
               "3.Sort in descending order by score\n4.Sort in ascending order by score\n"
               "5.Sort in ascending order by number\n" "6.Sort in dictionary order by name\n"
               "7.Search by number\n""8.Search by name\n"
               "9.Statistic analysis\n10.List record\n11.Exit\n");

        do
        {
            printf("please enter your choice number:");
            ret=scanf("%d",&n);
            if(ret!=1)
            {
                while(getchar()!='\n');
                printf("please enter your choice number:");
                ret=scanf("%d",&n);
            }
        }
        while(n<0||n>11);

        switch(n)
        {
        case 1:
        {
            do
            {
                puts("please input no more than 30 student.");
                m=ReadScore(score,num,name);
            }
            while(m<1 || m>30);
            printf("You have finished input record.\n\n");
            CopyArray(orgnum,num,m);
            CopyArray(orgscore,score,m);
            break;
        }
        case 2:
        {
            sum=SumArray(score,m);
            average=sum/(float)m;
            printf("sum=%d,average=%d\n\n",sum,average);
            break;
        }
        case 4:
        {
            SelectionSort(score,num,name,m,Ascending);
            PrintScore(score,num,name,m);
            break;
        }
        case 3:
        {
            SelectionSort(score,num,name,m,Descending);
            PrintScore(score,num,name,m);
            break;
        }
        case 5:
        {
            SelectionSort(num,score,name,m,Ascending);
            PrintScore(score,num,name,m);
            break;
        }
        case 6:
        {
            SortString(score,num,name,m);
            PrintScore(score,num,name,m);
            break;
        }
        case 7:
        {
            puts("please input a ID to search:");
            scanf("%ld",&numb);
            rank=Search(score,num,name,m,numb)+1;
            if(rank==0)
            {
                puts("Not found!");
                break;
            }
            printf("the student rank=%d,score=%ld\n\n",rank,score[rank-1]);
            break;
        }
        case 8:
        {
            puts("please input a name to search:");
            while(getchar()!='\n');
            gets(nam);
            rank=NameSearch(score,num,name,m,nam)+1;
            if(rank==0)
            {
                puts("Not found!");
                break;
            }
            printf("the student rank=%d,score=%ld\n\n",rank,score[rank-1]);
            break;
        }
        case 9:
        {
            Clas(score,m);
            break;
        }
        case 10:
        {
            PrintScore(orgscore,orgnum,name,m);
            sum=SumArray(orgscore,m);
            average=sum/(float)m;
            printf("sumofall=%d,average=%d\n\n",sum,average);
            break;
        }
        case 11:
        {
            puts("Thank you for using!");
            exit(0);
        }
        default:
            exit(1);
        }

    }while(n != 0);
    return 0;
}
