#include<stdio.h> //verified

int main()
{

    int m,n;
    int flag,t,leastindex,leastsize;
    
    printf("Enter the no of blocks");
    scanf("%d",&m);
    int blocks[m];
    printf("Enter the sizes of each block");
    for(int i=0;i<m;i++)
    {
        scanf("%d",&blocks[i]);
        

    } 
    printf("Enter the no of processes");
    scanf("%d",&n);
   int  process[n],allocation[n];
    printf("Enter the size of each processes");
    for(int i=0;i<n;i++)
    {
    scanf("%d",&process[i]);
    allocation[i]=-1;
}
for(int i=0;i<n;i++)
{
   flag=0;
    for(int j=0;j<m;j++)
    {
        
        if(process[i]<=blocks[j] )
        {
          
          if(flag==0) 
          {
            leastsize=blocks[j];
            leastindex=j;
            flag++;
          } 
          else if(blocks[j]<=leastsize)
          {
            leastsize=blocks[j];
            leastindex=j; 
          }

        } 
    }

t=blocks[leastindex];
blocks[leastindex]=blocks[leastindex]-process[i];
printf("%d %d %d %d\n",i+1,process[i],leastindex+1,t);
 


}




}