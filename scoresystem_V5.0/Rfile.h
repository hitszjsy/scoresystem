
int Rfile(FILE *fp,STUDENT stu[])
{
    int i=0;
    while(!feof(fp))
    {
        fread(&stu[i],sizeof(STUDENT),1,fp);
        i++;
    }
    return i-1;
}
