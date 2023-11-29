#include<stdio.h>

int main()
{

int p,f,flag;
int miss=0;
int hit=0;
printf("Enter no of pages");
scanf("%d",&p);
printf("Enter no of frames");
scanf("%d",&f);

int pages[p];
int frames[f];

printf("Enter the pages ");
for(int i=0;i<p;i++)
scanf("%d",&pages[i]);

for(int i=0;i<f;i++)
frames[i]=-1;

int fr=0;
for(int i=0;i<p;i++)
{
    flag=0;
    for(int j=0;j<f;j++)
    {
        if(pages[i]==frames[j])
        {
            flag=1; 
            hit++;
            break;

        }
        }
      if(flag==0)
        {
            frames[fr]=pages[i];
            fr=(fr+1)%f;
            miss++;
        }
    
    printf("Page frame:");
    for(int k=0;k<f;k++)
    {
        printf("%d",frames[k]);
    }

}

printf("Total hits are %d\n",hit);
printf("Total miss are %d\n",miss);
}



