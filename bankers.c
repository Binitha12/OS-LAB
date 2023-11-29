#include<stdio.h> //verified
#include<stdlib.h>

int main()
{


    int p,r;
    
    printf("Enter the no of processes");
    scanf("%d",&p);
    printf("Enter the no of resources");
    scanf("%d",&r);
    int alloc[p][r],max[p][r],need[p][r];
    int finish[p],available[r],work[r],safeseq[p];
    printf("Enter the allocated matrix");
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++)
        {
    scanf("%d",&alloc[i][j]);

        }
        finish[i]=0;
    }


    printf("Enter the max matrix");
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++)
        {
    scanf("%d",&max[i][j]);

        }

      }

      printf("Enter the available resources");
      for(int i=0;i<r;i++)
      {
      scanf("%d",&available[i]);
      work[i]=available[i];
      }

      printf("The need matrix is ");
      for(int i=0;i<p;i++)
      {
        for(int j=0;j<r;j++)
        {
    need[i][j]=max[i][j]-alloc[i][j];
    printf("%d ",need[i][j]);
        }
        printf("\n");
      }
      int over=0;
      int flag=0;
int k=0;
while(over<p)
{
    for(int i=0;i<p;i++)
    {
        flag=0;
        if(finish[i]==0)
        {
 for(int j=0;j<r;j++)
 {
    if(need[i][j]<=work[j])
    {
        flag++;
    }
 }
        }
 if(flag==r)
 {
    for(int j=0;j<r;j++)
    {
        work[j]=work[j]+alloc[i][j];
    }
    
    safeseq[over]=i+1;
    finish[i]=1;
    over++;
    //printf("%d",safeseq[i]);
 }
        

        }
    }
        

     


if(over==p)
{
    printf("The safe sequence is \n");
    for(int i=0;i<p;i++)
    {
        printf("%d ",safeseq[i]);
    }
}
else{
    printf("The system is not safe");
}




}