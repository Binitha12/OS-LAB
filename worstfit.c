#include<stdio.h>

int main()
{
int i,j,blocknos,blocksize[10],processnos,processsize[10];
int t,flag,largestsize,largestindex;
printf("Enter the no of memory blocks");
scanf("%d",&blocknos);

printf("Enter the size of each block in order");
for(i=0;i<blocknos;i++)
{
scanf("%d",&blocksize[i]);
}
printf("Enter the no of process");
scanf("%d",&processnos);

printf("Enter the size of each process");
for(i=0;i<processnos;i++)
{
scanf("%d",&processsize[i]);
}
printf("Blockno.\tBlocksize\n");
for(i=0;i<blocknos;i++)
{
printf("%d\t\t%d",i+1,blocksize[i]);
printf("\n");
}
printf("Processno.\tProcessSize\n");
for(i=0;i<processnos;i++)
{
printf("%d\t\t%d",i+1,processsize[i]);
printf("\n");
}
printf("WORST FIT MEMORY ALLOCATION\n");

printf("Processno\tAllocated blockno\tAllocated blocksize\tFragment left\n");
i=0;
while(i<processnos)
{
       flag=0;
       for(j=0;j<blocknos;j++)
       {
            if(processsize[i]<=blocksize[j])
             {
                  if(flag==0)
                   {
                      largestsize=blocksize[j];
                      largestindex=j;
                      flag++;
                   }

                  else if(blocksize[j]>largestsize)
                   {
                      largestsize=blocksize[j];
                      largestindex=j;
                   
                   }
            }
      }
t=blocksize[largestindex];
blocksize[largestindex]=blocksize[largestindex]-processsize[i];
printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\n",i+1,largestindex+1,t,blocksize[largestindex]);
i++;
}
}

