
int SumArray(long score[],int n)
{
    int i,sum=0;
    for(i=0;i<n;i++)
    {
        sum+=score[i];
    }
    return sum;
}
