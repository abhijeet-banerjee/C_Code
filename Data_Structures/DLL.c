
/******************************************************************************
                                 DLL Implementation
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
int data;
struct Node *left;
struct Node *right;
};

struct Node *root = NULL;

int length()
{
    struct Node *p;
    int countNodes = 0;
if(root == NULL)
{
    printf("\nList is empty !!\n");
}

else
{
    p = root;
    while(p!=NULL)
    {
        p = p->right;
        countNodes++;
    }
}
return countNodes;
}

void append()
{
    struct Node *p,*tmp;
    tmp = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter the value of the node to be appended??\n");
    scanf("%d",&tmp->data);
    tmp->left = NULL;
    tmp->right = NULL;
    // By this time we prepared the node.
    if(root == NULL)
    {
        root = tmp;
    }
    
    else
    {
        p = root;
        while(p->right !=NULL)
        {
            p = p->right;
        }
        // Making Right link connection is more important
        p ->right = tmp;
        tmp->left = p;
    }
}

void addBegin()
{
    struct Node *p,*tmp;
    tmp = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter the value of the node to be added at beginning??\n");
    scanf("%d",&tmp->data);
    tmp->left = NULL;
    tmp->right = NULL;
    if(root == NULL)
    {
        root = tmp;
    }
    
    else
    {
        p= root;
        tmp->right =  p;
        p->left = tmp;
        root = tmp;
    }
}


void addAnyWhere()
{
    struct Node *p,*tmp;
    int pos,i=1;
    tmp = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter the value of the node to be added??\n");
    scanf("%d",&tmp->data);
    tmp->left = NULL;
    tmp->right = NULL;
    printf("\nEnter after which position node has to be added ??\n");
    scanf("%d",&pos);
    if(root == NULL)
    {
        root = tmp;
    } 
   else
   {
        if(pos>0 && pos<=length())
    {
        p = root;
       while(i<pos){
           p = p->right;
           i++;
       }
       // Now this step as it will be the last node and it wont have anything after it(i.e., to the right of it)
      if(pos == length())
      {
       p->right = tmp;
       tmp->left = p; 
      }
         // Now this step as this node will be preceded and succeded by some other nodes as well
      else
      {
      tmp->right=p->right;
     p->right->left=tmp;
       p->right = tmp;
       tmp->left = p;
      }
    }
    
    
    else
    {
printf("\nInvalid Position entered\n"); 
    }
   }
}


void deleteLL()
{
   struct Node* q; 
  
   while (root != NULL)  
   { 
       q = root; 
       root = root->right;
       free(q); 

   } 

}

void print()
{
    struct Node *p;
if(root == NULL)
{
    print("\nList is empty !!\n");
}

else
{
    p = root;
    while(p!=NULL)
    {
        printf("%d <<--->> ",p->data);
        p = p->right;
    }
    printf("\n");
}
    
}

void deleteAtStart()
{
    struct Node *p;
    if(root == NULL)
    {
        printf("\nList is already empty\n");
    }
    else
    {
        p = root;
        root = p->right;
        p ->right =NULL;
        free(p);
    }
}

void deleteAtLast()
{
     struct Node *p;
    if(root == NULL)
    {
        printf("\nList is already empty\n");
    }
    else
    {
        p = root;
     while(p->right !=NULL)
       {
          p = p->right;
      }
        p->left->right = NULL;
        p->left = NULL;
        free(p);
}
}

void deleteAnywhere()
{
       struct Node *p,*q;
       int pos,i=0,j=0;
    if(root == NULL)
    {
        printf("\nList is already empty\n");
    }
    else
    {
      printf("\nEnter the position of the node to delete??\n");
      scanf("%d",&pos);
      if(pos >=1 && pos<=length())
      {
             if(pos == 1)
      deleteAtStart();
      else if(pos == length())
      deleteAtLast();
      else
      {
          p = q = root;
          
           while(j < pos-1)       
          {
              /*
 In this case, pos-1 points to the current node where we wish to stop as of now, right at the position entered
              */
              p = p->right;
              j++;
          }
          
          while(i < pos-2)
          {
              /*
 In this case, pos-2  points to the current node where we wish to stop as of now, right one less than the position entered
              */
              q = q->right;
              i++;
          }
          q->right = p->right;
          p->right->left = q;
          p->left =NULL;
          p->right=NULL;
          free(p);
      }
      
      }
      
      else
      {
        printf("\nInvalid position\n");
      }
}
}

void sort()
{
      struct Node *p,*q;
      int t;
    if(root == NULL)
    {
        printf("\nList is already empty\n");
    }   
    
    else
    {
        p = root;
       while(p!=NULL)
       {
                for(q=p->right;q!=NULL;q=q->right)
                {
                    if(p->data > q->data)
                    {
                        t =p->data;
                        p->data = q->data;
                        q->data = t;
                    }
                }
                p = p->right;
       }
    }
}

int main()
{
int ch;
while(1)
{
    printf("\n1.Append\n2.Add at start\n3.Print\n4.Add Anywhere\n5.Print\n6.Length\n7.Delete at Start\n8.Delete At Last\n9.Delete Anywhere\n10.Sort\n11.Delete LL\n12.Exit\n\n");
    scanf("%d",&ch);
    switch(ch){
        case 1: append();
        break;
        case 2: addBegin();
        break;
        case 3: print();
        break;
        case 4: addAnyWhere();
        break;
        case 5: print();
        break;
        case 6: printf("\nLength of DLL = %d nodes\n",length());
        break;
        case 7: deleteAtStart();
        break;
        case 8: deleteAtLast();
        break;
        case 9: deleteAnywhere();
        break;
        case 10: sort();
        break;
        case 11: deleteLL();
        break;
        case 12: exit(0);
        default: printf("\nWrong Choice\n");
        break;
    }
}

    return 0;
}
