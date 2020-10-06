/******************************************************************************
SLL add a node at any position
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *root = NULL;

void append()
{
     struct Node *p,*tmp;
    tmp = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter the value for the node??\n");
    scanf("%d",&tmp->data);
    tmp->next=NULL;
    if(root == NULL)
    {
         root = tmp;
    }
    else{
        p =root;
        while(p->next!=NULL)
        {
            p = p->next;
        }
        p->next = tmp;
    }
}

int length()
{
    struct Node *p;
    p =root;
    int count=0;
    while(p){
        p = p->next;
        count++;
    }
    return count;
}

void afterwards()
{
    struct Node *p,*tmp;
    int pos;
    tmp = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter the value for the node??\n");
    scanf("%d",&tmp->data);
    tmp->next=NULL;
    // Node Prepared by now.
  printf("\nEnter the position for the node??\n");
    scanf("%d",&pos);
if(pos>0 && pos<=length())
       {
           if(root == NULL)
      {
          root = tmp;
      }
      else
      {
          int i=1;
          p =root;
          while(i<pos)
          {
              p = p->next;
              i++;
          }
                  tmp->next=p->next;
          p->next=tmp;
      }
      
       }
       else
       {
           printf("\nInvalid position\n");
       }
}

void print()
{
   struct Node *p;
   p = root;
   while(p!=NULL)
   {
       printf("%d --->> ",p->data);
       p=p->next;
   }
   printf("\n");
}



int main()
{
int ch;
while(1)
{
    printf("\n1.Append\n2.AddAnywhere\n3.Length\n4.Print\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: append();
        break;
        
        case 2: afterwards();
        break;
        
        case 3:  printf("Length = %d ",length());
        break;
        
        case 4: print();
        break;
    }
}

    return 0;
}
