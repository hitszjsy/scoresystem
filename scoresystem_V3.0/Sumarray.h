
int SumArray(long score[],int n)
{
    int i,sum=0;
    for(i=0;i<n;i++)
    {
        sum+=score[i];
    }
    return sum;
}

void SumCourse(long sumcourse[],long score[][MAX_COURSE],int m,int c)
{
    int j;
    long course[N];
    for(j=0;j<c;j++)
    {
        CreatArray(course,score,j,m);
        sumcourse[j]=SumArray(course,m);
    }
}
