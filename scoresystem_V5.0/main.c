#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COURSE 6
#define MAX_LEN 10
#define N 30
#include "Index.h"
#include "struct_student.h"
#include "ReadInfo.h"
#include "SumArray.h"
#include "CourseScore.h"
#include "Sort.h"
#include "Print.h"
#include "Search.h"
#include "analysis.h"
#include "Wfile.h"
#include "Rfile.h"

int main()
{
    STUDENT stu[N];
    int m,c,ret,n,i,finish=0;
    long sum,average,alist[N],numb;
    char name[MAX_LEN];
    FILE *fp;
    puts("Welcome to use our scoresystem V5.0!");
    do
    {
        Index();
        do
        {
            do
            {
                printf("please enter your choice number:(ensure to input all information first)");
                ret=scanf("%d",&n);
                while(ret!=1)
                {
                    while(getchar()!='\n');
                    printf("please enter your choice number:");
                    ret=scanf("%d",&n);
                }
            }while(n!=1 && finish==0 && n!=13);
        }
        while(n<0 || n>13);

        switch(n)
        {
        case 1:
            {
                puts("please input no more than 30 student and no more than 6 course.");
                Readinfo(stu,&m,&c);
                for(i=0;i<m;i++)
                {
                    stu[i].totalscore=SumArray(stu[i].score,c);
                }
                puts("You have finished score input.");
                finish=1;
                break;
            }
        case 2:
            {
                for(i=0;i<c;i++)
                {
                    CourseScore(alist,stu,m,i);
                    sum=SumArray(alist,m);
                    average=sum/(float)m;
                    printf("course%d sum=%ld, average=%ld\n",i+1,sum,average);
                }
                break;
            }
        case 3:
            {
                for(i=0;i<m;i++)
                {
                    sum=SumArray(stu[i].score,c);
                    average=sum/(float)c;
                    printf("%10ld %5s sum=%ld, average=%ld\n",stu[i].ID,stu[i].name,sum,average);
                }
                break;
            }
        case 4:
            {
                SortByTotalScore(stu,m,Descending);
                for(i=0;i<m;i++)
                {
                    PrintInfo(stu[i],c);
                }
                break;
            }
        case 5:
            {
                SortByTotalScore(stu,m,Ascending);
                for(i=0;i<m;i++)
                {
                    PrintInfo(stu[i],c);
                }
                break;
            }
        case 6:
            {
                SortByNum(stu,m);
                for(i=0; i<m; i++)
                {
                    PrintInfo(stu[i],c);
                }
                break;
            }
        case 7:
            {
                SortByName(stu,m);
                for(i=0; i<m; i++)
                {
                    PrintInfo(stu[i],c);
                }
                break;
            }
        case 8:
            {
                puts("Input a number to search:");
                scanf("%ld",&numb);
                i=SearchNum(stu,m,numb);
                if(i == -1) break;
                else
                {
                    PrintInfo(stu[i],c);
                    break;
                }
            }
        case 9:
            {
                puts("Input a name to search:");
                scanf("%s",name);
                i=SearchName(stu,m,name);
                if(i == -1) break;
                else
                {
                    PrintInfo(stu[i],c);
                    break;
                }
            }
        case 10:
            {
                for(i=0;i<c;i++)
                {
                    printf("course%d:",i+1);
                    CourseScore(alist,stu,m,i);
                    analyse(alist,m);
                }
                break;
            }
        case 11:
            {
                for(i=0;i<m;i++)
                {
                    PrintInfo(stu[i],c);
                }
                break;
            }
        case 12:
            {
                if( ( fp=fopen("D:\\testrecord.txt","w") ) == NULL )
                {
                    puts("Fail to open testrecord.txt!");
                    exit(0);
                }
                Wfile(fp,stu,m);
                fclose(fp);
                puts("You have finished score record!");
                break;
            }
        case 13:
            {
                if( ( fp=fopen("D:\\testrecord.txt","r") ) == NULL )
                {
                    puts("Fail to open testrecord.txt!");
                    exit(0);
                }
                do
                {
                    puts("How many courses are there in the file?");
                    ret=scanf(" %d",&c);
                    while(ret!=1)
                    {
                        while(getchar()!='\n');
                        printf("please input a number:");
                        ret=scanf(" %d",&c);
                    }
                }while(c<=0 || c>6);
                m=Rfile(fp,stu);
                fclose(fp);
                printf("Total students is %d.\n",m);
                puts("Here is a list of the record:");
                for(i=0;i<m;i++)
                {
                    PrintInfo(stu[i],c);
                }
                finish=1;
                break;
            }
        case 0:
            {
                puts("Thank you for using our product!");
                exit(0);
            }
        default:
            exit(1);
        }
    }while(n != 0);
}
