/******************************************************************************
                    CIRCULAR QUEUE Implementation using Arrays
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX 3

int front = -1, rear = -1;
int cq[MAX];

void insert(int el)
{
    // Firstly, check whether or not queue is full??
    if((front == rear +1) || (rear == MAX-1))
    printf("\nQueue is Full\n");
    else if(front ==-1 && rear == -1)
    {
        front = rear = 0;
        cq[rear] = el;
    }
    else if(rear == MAX-1)
    {
        rear = 0;
        cq[rear] = el;
    }
    else
    {
        rear ++;
      cq[rear] = el;
    }
}

void delete()
{
    int e;
       // Firstly, check whether or not queue is empty??
       if(front == -1 && rear == -1)
       {
        printf("\nQueue is Empty\n");
       }
       
       else if(front == rear)
       {
          e =  cq[front];
            printf("\nDeleted Element %d\n",e);
            front = rear = -1;
       }
       
       else if(front == MAX-1)
       {
                     e =  cq[front];
            printf("\nDeleted Element %d\n",e);
            front =0;
       }
       
       else
       {
                 e =  cq[front];
            printf("\nDeleted Element %d\n",e);
           front ++;
       }
       
}

void display()
{
   int i,j;
   if(front > rear)
   {
        for(i=front;i<MAX;i++)
       {
           printf("%d ",cq[i]);
       } 
        for(j=0;i<=rear;i++)
       {
           printf("%d ",cq[i]);
       }
   }
   
   else
   {
       for(i=0;i<=rear;i++)
       {
           printf("%d ",cq[i]);
       }
   }
}

int main()
{
int ch,e;
while(1)
{
       printf("\n1.Enquque\n2.Dequeue\n3.Display\n4.Exit\n\n");
       scanf("%d",&ch);
       switch(ch){
           case 1: 
               printf("\nEnter element???\n");
               scanf("%d",&e);
           insert(e);
           break;
            case 2: delete();
           break;
           
            case 3: display();
           break;
           
            case 4: exit(0);
           break;
           
       }
}
    return 0;
}
