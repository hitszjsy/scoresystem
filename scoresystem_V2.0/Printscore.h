
void PrintScore(long score[],long num[],char name[][MAX_LEN],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%10ld %10s %4ld\n",num[i],name[i],score[i]);
    }
}
