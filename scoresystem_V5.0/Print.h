
void PrintInfo(STUDENT stu,int c)
{
    int i;
    printf("%10ld %5s ",stu.ID,stu.name);
    for(i=0;i<c;i++)
    {
        printf("%4ld",stu.score[i]);
    }
    printf("  totalscore=%4ld",stu.totalscore);
    puts("");
}
