
int SearchNum(STUDENT stu[],int m,long numb)
{
    int i;
    for(i=0;i<m;i++)
    {
        if(numb==stu[i].ID)
        {
            return i;
        }
    }
    puts("Not found!");
    return -1;
}

int SearchName(STUDENT stu[],int m,char name[])
{
    int i;
    for(i=0;i<m;i++)
    {
        if(strcmp(name,stu[i].name)==0)
        {
            return i;
        }
    }
    puts("Not found!");
    return -1;
}
