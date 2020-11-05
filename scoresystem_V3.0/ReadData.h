
void ReadScore(long score[][MAX_COURSE],long num[],char name[][MAX_LEN],int *pm,int *pc)
{
    int i=-1,j,c;
    puts("How many course do you want to input?");
    scanf("%d",&c);
    do
    {
        i++;
        printf("Please input a student's ID & name & score(no more than 6):(input a minus number to stop input)\n");
        scanf("%ld %10s",&num[i],name[i]);
        for(j=0;j<c;j++)
        {
            scanf("%ld",&score[i][j]);
        }
    }while(num[i]>0);
    *pm=i; *pc=c;
}
