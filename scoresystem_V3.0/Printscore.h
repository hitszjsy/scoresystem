

//print 1 dimension array's first n elements.
void PrintArray(long x[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%4ld",x[i]);
    }
}

void PrintScore(long totalscore[],long num[],char name[][MAX_LEN],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%10ld %10s totalscore=%4ld \n",num[i],name[i],totalscore[i]);
    }
}

void PrintAll(long num[],long score[][MAX_COURSE],char name[][MAX_LEN],int n,int c)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%10ld %10s ",num[i],name[i]);
        PrintArray(score[i],c);
        puts("");//\n
    }
}
