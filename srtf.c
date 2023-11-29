#include<stdio.h> //not verified

typedef struct process{
    int pid;
    int at;
    int bt;
    int wt;
    int ct;
    int tat;
    int rmtime;
}process;

int main()
{
    
    int n,ttat=0,twt=0,shortest;
    float avwt,avtat;
    printf("Enter the no of processes\n");
    scanf("%d",&n);
    struct process p[n];
    printf("Enter the arrival time,Burst Time of each\n");
    //printf("Process no           Arrival time        Burst Time\n ");
    for(int i=0;i<n;i++)
    {
        p[i].pid=i;
        printf("p[%d]",i);
        scanf("%d  %d",&p[i].at,&p[i].bt);
        p[i].rmtime=p[i].bt;
        printf("\n");

    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(p[i].at>p[j].at)
            {
                struct process temp;
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
int time=0;
int completed=0;
while(completed<n)
{
 shortest=-1;
 for(int i=0;i<n;i++)
 {
    if(p[i].at<=time && p[i].rmtime>0)
    {
        if(shortest=-1|| p[i].rmtime<p[shortest].rmtime)
        shortest=i;

    }
 }
 if(shortest==-1)
 {
    time++;
    continue;
 }
 p[shortest].rmtime--;
 time++;
 if(p[shortest].rmtime==0)
 {
    completed++;
    p[shortest].tat=time-p[shortest].at;
    p[shortest].wt=p[shortest].tat-p[shortest].bt;
    ttat=ttat+p[shortest].tat;
 twt=twt+p[shortest].wt;
 }




}


 


avtat=(float)ttat/(float)n;
avwt=(float)twt/(float)n;
printf("Process ID   Arrival Time  Burst Time   CT     TAT     WT\n");

for(int i=0;i<n;i++)
{

    printf(" %d     %d      %d      %d      %d      %d      \n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);

}
printf("Total wt is %d\n",twt);
printf("Total tat is %d\n",ttat);
printf("Average wt is %f\n",avwt);
printf("Average tat is %f\n",avtat);

}