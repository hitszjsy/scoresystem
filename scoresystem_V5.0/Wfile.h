
void Wfile(FILE *fp,STUDENT stu[],int n)
{
    fwrite(stu,sizeof(STUDENT),n,fp);
}
