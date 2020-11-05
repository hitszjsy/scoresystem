
void Clas(long score[],int n)
{
    float A,B,C,D,E;
    int a=0,b=0,c=0,d=0,e=0,i;
    for(i=0;i<n;i++)
    {
        long m=score[i];
        if(m>=90 && m<=100)
        {
            a++;
        }
        else if(m>=80 && m<90)
        {
            b++;
        }
        else if(m>=70 && m<80)
        {
            c++;
        }
        else if(m>=60 && m<70)
        {
            d++;
        }
        else if(m>0 && m<60)
        {
            e++;
        }
        else printf("input error!\n\n");
    }
    A=(float)a/n*100; B=(float)b/n*100; C=(float)c/n*100; D=(float)d/n*100; E=(float)e/n*100;
    printf("优秀%d 占%f%%;良好%d 占%f%%;中等%d 占%f%%;及格%d 占%f%%;不及格%d 占%f%%\n\n",a,A,b,B,c,C,d,D,e,E);
}
