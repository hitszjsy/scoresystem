#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 10
#define N 30
#define MAX_COURSE 6
#include "Creatclumearray.h"
#include "ReadData.h"
#include "CopyScore.h"
#include "Sumarray.h"
#include "Printscore.h"
#include "statistics.h"
#include "Search.h"

int main()
{
    int n,ret,m,rank,c,i,j;
    long num[N],orgnum[N],score[N][MAX_COURSE],orgscore[N][MAX_COURSE],numb,aver[MAX_COURSE],sumcourse[MAX_COURSE];//numb is a storage for num input.
    long totalscore[N],sum,average,coursescore[N];//coursescore is used for storing all score of a course tentatively.
    char name[N][MAX_LEN]={0},nam[MAX_LEN]={0};//nam[] is not a print error,but a storage for name input.
    puts("Welcome to use our system V3.0!");

    do
    {
        printf("\n1.Input record\n2.Calculate total and average score of every course\n3. Calculate total and average score of every student"
               "\n4.Sort in descending order by total score of every student\n5. Sort in ascending order by total score of every student\n"
               "6.Sort in ascending order by number\n" "7.Sort in dictionary order by name\n"
               "8.Search by number\n""9.Search by name\n"
               "10.Statistic analysis for every course\n11.List record\n0.Exit\n");

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
            int *pm=&m,*pc=&c;
            puts("please input no more than 30 student and no more than 6 course.");
            ReadScore(score,num,name,pm,pc);

            printf("You have finished input record.\n\n");
            CopyArray(orgnum,num,m);
            for(i=0;i<m;i++)
            {
                CopyArray(orgscore[i],score[i],c);
            }
            break;
        }
        case 2:
        {
            SumCourse(sumcourse,score,m,c);
            for(j=0;j<c;j++)
            {
                aver[j]=sumcourse[j]/(float)m;
                printf("sum of course%d=%ld,average of it=%ld\n\n",j+1,sumcourse[j],aver[j]);
            }

            break;
        }
        case 3:
        {
            for(i=0;i<m;i++)
            {
                sum=SumArray(score[i],c);
                average=sum/(float)c;
                printf("num %ld ,name %s ,sumofallcourse=%ld ,average=%ld",num[i],name[i],sum,average);
                puts("");//\n
            }
            break;
        }

        case 4:
        {
            for(i=0;i<m;i++)
            {
                totalscore[i]=SumArray(score[i],c);
            }
            SelectionSort(totalscore,num,name,m,Descending);
            PrintScore(totalscore,num,name,m);
            break;
        }
        case 5:
        {
            for(i=0;i<m;i++)
            {
                totalscore[i]=SumArray(score[i],c);
            }
            SelectionSort(totalscore,num,name,m,Ascending);
            PrintScore(totalscore,num,name,m);
            break;
        }
        case 6:
        {
            SortByNum(num,score,name,m,c);
            PrintAll(num,score,name,m,c);
            break;
        }
        case 7:
        {
            SortString(score,num,name,m,c);
            PrintAll(num,score,name,m,c);
            break;
        }
        case 8:
        {
            puts("please input a ID to search:");
            scanf("%ld",&numb);
            rank=Search(score,num,name,m,numb);
            if(rank==-1)
            {
                puts("Not found!");
                break;
            }
            printf("num %ld, name %10s, ",num[rank],name[rank]);
            PrintArray(score[rank],c);
            break;
        }
        case 9:
        {
            puts("please input a name to search:");
            while(getchar()!='\n');
            gets(nam);
            rank=NameSearch(score,num,name,m,nam);
            if(rank==-1)
            {
                puts("Not found!");
                break;
            }
            printf("num %ld, name %10s, ",num[rank],name[rank]);
            PrintArray(score[rank],c);
            break;
        }
        case 10:
        {
            for(i=0;i<c;i++)
            {
                printf("course%d",i+1);
                CreatArray(coursescore,score,i,m);
                Clas(coursescore,m);
            }
            break;
        }
        case 11:
        {
            for(i=0;i<m;i++)
            {
                sum=SumArray(score[i],c);
                average=sum/(float)c;
                printf("%10ld %10s ",num[i],name[i]);
                PrintArray(score[i],c);
                printf("   ,sum=%ld,average=%ld",sum,average);
                puts("");
            }
            break;
        }
        case 0:
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
