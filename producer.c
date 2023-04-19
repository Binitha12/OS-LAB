#include<stdio.h>
#include<stdlib.h>

int main()
{
int full=0;
int empty=5;
int mutex=1,choice;
int x=0;

int wait(int n)
   {
     n=n-1;
        return n;
   }

int signal(int k)
   {
     k=k+1;
        return k;
    }

void producer()
        {


            empty=wait(empty);
            mutex=wait(mutex);

                   mutex=signal(mutex);
                   full=signal(full);
                   
            printf(" item %d produced by producer\n",++x);

         }

void consumer()
        {
           full=wait(full);
           mutex=wait(mutex);

                  mutex=signal(mutex);
                  empty=signal(empty);

            printf(" item %d consumed by consumer\n",x--);

        }


 do
   {
        printf("1.PRODUCER     2.CONSUMER     3.EXIT\n");
               printf("Enter your choice:");
                    scanf("%d",&choice);
                       switch(choice)
                            {
                              case 1:   if(mutex==1&& empty!=0)
                                           producer();
                                        else
                                           printf("BUFFER IS FULL\n\n");
                                        break;

                              case 2:  if(mutex==1&& full!=0)
                                          consumer();
                                        else
                                          printf("BUFFER IS EMPTY\n\n");
                                        break;

                              case 3:  exit(0);
                                       break;
                               
                            }
    }

while(choice!=3);

}








