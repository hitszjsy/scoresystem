
void Readinfo(STUDENT stu[],int *pm,int *pc)
{
    int i=-1,c,j,ret;
    do
    {
        while(getchar()!='\n');//necessary
        puts("How many course do you want to input?");
        ret=scanf(" %d",&c);
        while(ret!=1)
        {
            while(getchar()!='\n');
            printf("please input a number:");
            ret=scanf(" %d",&c);
        }
    }
    while(c<=0 || c>6);

    do
    {
        i++;
        puts("Please input a student's ID & name & score(no more than 6):(input a minus number to stop input)");
        scanf("%ld %s",&stu[i].ID, stu[i].name);
        for(j=0;j<c;j++)
        {
            scanf("%ld",&stu[i].score[j]);
        }
    }while(stu[i].ID > 0);
    *pm=i;  *pc=c;
}
