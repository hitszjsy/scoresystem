
void SortByTotalScore(STUDENT stu[],int m,int (*compare)(long a,long b))
{
    int i,j,k;
    STUDENT stud;
    for(i=0; i<m; i++)
    {
        k=i;
        for(j=i+1; j<m; j++)
        {
            if((*compare)(stu[j].totalscore,stu[i].totalscore))
                k=j;
        }
        if(k!=i)
        {
            stud=stu[i];
            stu[i]=stu[k];
            stu[k]=stud;
        }
    }
}

int Ascending(long a,long b)
{
    return a<b;
}

int Descending(long a,long b)
{
    return a>b;
}

void SortByNum(STUDENT stu[],int m)
{
    int i,j,k;
    STUDENT stud;
    for(i=0; i<m; i++)
    {
        k=i;
        for(j=i+1; j<m; j++)
        {
            if(stu[j].ID<stu[i].ID)
                k=j;
        }
        if(k!=i)
        {
            stud=stu[i];
            stu[i]=stu[k];
            stu[k]=stud;
        }
    }
}

void SortByName(STUDENT stu[],int m)
{
    int i,j,k;
    STUDENT stud;
    for(i=0; i<m; i++)
    {
        k=i;
        for(j=i+1; j<m; j++)
        {
            if(strcmp(stu[j].name,stu[i].name)<0)
                k=j;
        }
        if(k!=i)
        {
            stud=stu[i];
            stu[i]=stu[k];
            stu[k]=stud;
        }
    }
}
