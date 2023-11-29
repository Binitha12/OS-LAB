#include<stdio.h>

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
    
    int n,ttat,twt,quanta;
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
    printf("Enter the time quanta");
scanf("%d",&quanta);
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

    int completed=0;
    int time=0;
    int current;
    
       current=-1;
       while(completed<n)
       {

       
      for(int i=0;i<n;i++)
      {
    
       
        if(p[i].at<=time && p[i].rmtime>quanta)
        {
            printf("%d",p[i].pid);
            p[i].rmtime=p[i].rmtime-quanta;
            time=time+quanta;
        }
         else if(p[i].at<=time && p[i].rmtime<quanta &&p[i].rmtime>0)
        {
             printf("%d",p[i].pid);
        time=time+p[i].rmtime;
            p[i].rmtime=0;
            current=i;
        
        
      }
      else
      {
        printf("%d",p[i].pid);
        time=time+quanta;
        p[i].rmtime=0;
      }
    
      
if(p[i].rmtime==0)
{
    completed++;
    p[i].tat= time - p[i].at;
            p[i].wt = p[i].tat- p[i].bt;
}
      }


    


}
  twt = 0;
    ttat = 0;
    printf("\n|------------------------------Process Scheduling--------------------------------|");
    printf("\n|Process\t|Arrival Time\t|Burst Time\t|Turnaround Time |Waiting Time |\n");
    printf("|--------------------------------------------------------------------------------|");
    for (int i = 0; i < n; i++){
       printf("\n %d\t\t %d\t\t %d\t\t %d\t\t %d", p[i].pid, p[i].at, p[i].bt, p[i].tat, p[i].wt);
        twt += p[i].wt;
        ttat += p[i].tat;
    }
    printf("\n|--------------------------------------------------------------------------------|");
    printf("\nTotal Waiting Time: %.2f\n", twt);
    printf("Total Turn Around Time: %.2f\n", ttat);
    printf("Average Waiting Time: %.2f\n", twt / n);
    printf("Average Turnaround Time: %.2f\n", ttat / n);
}