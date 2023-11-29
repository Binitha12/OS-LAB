//priority scheduling

#include<stdio.h>

struct process{

    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
    int priority;
};


int main()
{

    int n,time=0,count=0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process p[n];
    printf("Enter the arrival time, burst time and priority of each processes");
    for(int i=0;i<n;i++)
    {
    printf("\nProcess %d\n", i+1);
    printf("Arrival time: ");
    scanf("%d", &p[i].arrival_time);
    printf("Burst time: ");
    scanf("%d", &p[i].burst_time);
    printf("Priority: ");   
    scanf("%d", &p[i].priority);
    p[i].pid=i+1;

    }

    //sorting with arrival time
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(p[i].arrival_time>p[j].arrival_time)
            {
                struct process temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
time=p[0].arrival_time;

    //
    for(int i=0;i<n;i++)
    {
    count=0;
    for(int j=0;j<n;j++)
    {
        if(p[j].arrival_time<=time)
        {
            count++;
        }
        else{
            break;

        }
    }
    if(count>1)
    {
        for(int k=i;k<count;k++)
        {
            for(int l=k;l<count;l++)
            {
                if(p[k].priority>p[l].priority)
                {
                    struct process temp=p[k];
                    p[k]=p[l];
                    p[l]=temp;
                }
            }
        }
    }
    

    p[i].waiting_time=time-p[i].arrival_time;
p[i].turnaround_time=p[i].waiting_time+p[i].burst_time;
time=time+p[i].burst_time;
p[i].completion_time=time;




    }

float avg_waiting_time = 0;
    float avg_turnaround_time = 0;
    for(int i=0;i<n;i++)
    {
        avg_waiting_time += p[i].waiting_time;
        avg_turnaround_time += p[i].turnaround_time;
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    // Printing the details of the processes
    printf("\n\nProcess\tArrival time\tBurst time\tPriority\tWaiting time\tTurnaround time\tCompletion time\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time,p[i].priority, p[i].waiting_time, p[i].turnaround_time, p[i].completion_time);
    }

    // Printing the average waiting time and average turnaround time
    printf("\nAverage waiting time: %f", avg_waiting_time);
    printf("\nAverage turnaround time: %f", avg_turnaround_time);

    return 0;
}



