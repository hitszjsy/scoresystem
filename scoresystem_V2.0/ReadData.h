
int ReadScore(long score[],long num[],char name[][MAX_LEN])
{
    int i=-1,ret;
    do
    {
        i++;
        printf("Please input a student's ID & name & score:(input a minus to stop input)\n");
        ret=scanf("%ld %s %ld",&num[i],name[i],&score[i]);
        while(ret!=3)
        {
            while(getchar()!='\n');
            puts("Input a student's ID & name & score:");
            ret=scanf("%ld %s %ld",&num[i],name[i],&score[i]);
        }
    }while(num[i]>0 && score[i]>=0);
    return i;
}
