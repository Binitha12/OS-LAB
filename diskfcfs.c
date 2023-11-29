#include<stdio.h>
#include<math.h>

int main()
{
    int n,start;
    int startpos,dist=0;
    
printf("Enter the no of tasks to be seeked");
scanf("%d",&n);
int arr[n];
printf("Enter the tasks");
for(int i=0;i<n;i++)
{
    scanf("%d",&arr[i]);
}
printf("Enter the starting posn");
scanf("%d",&start);
startpos=start;
for(int i=0;i<n;i++)
{
    printf("%d  ",arr[i]);
dist=dist+fabs(startpos-arr[i]);
startpos=arr[i];

}
printf("%d",dist);



}