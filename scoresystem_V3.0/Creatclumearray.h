
void CreatArray(long course[],long score[][MAX_COURSE],int j,int m)
{
    int i;
    for(i=0;i<m;i++)
    {
        course[i]=score[i][j];/*course[] is used for storing all score of a course tentatively.*/
    }
}
