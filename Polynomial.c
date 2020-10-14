/******************************************************************************
                                Add Two Polynomials
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct Poly1
{
int data;
char var;
int power;
struct Node *left;
struct Node *right;
};

struct Poly2
{
int data;
char var;
int power;
struct Node *left;
struct Node *right;
};

struct Poly3
{
int data;
char var;
int power;
struct Node *left;
struct Node *right;
};

int n;
struct Poly1 *root1 = NULL;
struct Poly2 *root2 = NULL;
struct Poly3 *root3 = NULL;
void appendPoly1()
{
    int i;
    printf("\nHow many n-th degree polynomial to be created??\n");
    scanf("%d",&n);
    struct Poly1 *p,*tmp[(n+1)];
    for(i=n;i>=0;i--)
    {
    tmp[i] = (struct Poly1 *)malloc(sizeof(struct Poly1));
    printf("\nEnter the %d term coefficient value??\n",i);
    scanf("%d",&tmp[i]->data);
    getchar();
        printf("\nEnter the %d term variable??\n",i);
    scanf("%c",&tmp[i]->var);
        printf("\nEnter the %d term raise to the power value??\n",i);
    scanf("%d",&tmp[i]->power);
    tmp[i]->left = NULL;
    tmp[i]->right = NULL;
    // By this time we prepared the node.
    if(root1 == NULL)
    {
        root1 = tmp[i];
    }
    
    else
    {
        p = root1;
        while(p->right !=NULL)
        {
            p = p->right;
        }
        // Making Right link connection is more important
        p ->right = tmp[i];
        tmp[i]->left = p;
    }
    
    }
}

void printPoly1()
{
    struct Poly1 *p;
    printf("\n\n");
if(root1 == NULL)
{
    printf("\nPolynomial is empty !!\n");
}

else
{
    int nc = 0;
    p = root1;
    while(p!=NULL)
    {
        nc++;
        if(p->data >=0)
         {
 
        if(p->power == 1)
        {
(nc==1)?((p->data == 1)?(printf("%c",p->var)):(printf("%d%c",p->data,p->var))) :((p->data == 1)?(printf("+%c",p->var)):(printf("+%d%c",p->data,p->var)));
        }
        else if(p->power == 0)
         {
     (nc==1)?printf("%d",p->data):printf("+%d",p->data);
         }
        else
        {
(nc==1)?((p->data == 1)?(printf("%c^%d",p->var,p->power)):(printf("%d%c^%d",p->data,p->var,p->power))) :((p->data == 1)?(printf("+%c^%d",p->var,p->power)):(printf("+%d%c^%d",p->data,p->var,p->power)));            
        }
        
         }
         
         
         if(p->data < 0)
        {
        if(p->power == 1)
        {
(p->data == 1)?(printf("%c",p->var)):(printf("%d%c",p->data,p->var));
        }
        else if(p->power == 0)
        printf("%d",p->data);
        else
        {
(p->data == 1)?(printf("%c%d",p->var,p->power)):(printf("%d%c%d",p->data,p->var,p->power));            
        }
        
        }

        p = p->right;
    }
    printf("\n");
}
    
}


void appendPoly2()
{
    int i;
    struct Poly2 *p,*tmp[(n+1)];
    for(i=n;i>=0;i--)
    {
    tmp[i] = (struct Poly2 *)malloc(sizeof(struct Poly2));
    printf("\nEnter the %d term coefficient value??\n",i);
    scanf("%d",&tmp[i]->data);
    getchar();
        printf("\nEnter the %d term variable??\n",i);
    scanf("%c",&tmp[i]->var);
        printf("\nEnter the %d term raise to the power value??\n",i);
    scanf("%d",&tmp[i]->power);
    tmp[i]->left = NULL;
    tmp[i]->right = NULL;
    // By this time we prepared the node.
    if(root2 == NULL)
    {
        root2 = tmp[i];
    }
    
    else
    {
        p = root2;
        while(p->right !=NULL)
        {
            p = p->right;
        }
        // Making Right link connection is more important
        p ->right = tmp[i];
        tmp[i]->left = p;
    }
    
    } 
}


void printPoly2()
{
  struct Poly2 *p;
    printf("\n\n");
if(root2 == NULL)
{
    printf("\nPolynomial is empty !!\n");
}

else
{
    int nc = 0;
    p = root2;
    while(p!=NULL)
    {
        nc++;
        if(p->data >=0)
         {
 
        if(p->power == 1)
        {
(nc==1)?((p->data == 1)?(printf("%c",p->var)):(printf("%d%c",p->data,p->var))) :((p->data == 1)?(printf("+%c",p->var)):(printf("+%d%c",p->data,p->var)));
        }
        else if(p->power == 0)
         {
     (nc==1)?printf("%d",p->data):printf("+%d",p->data);
         }
        else
        {
(nc==1)?((p->data == 1)?(printf("%c^%d",p->var,p->power)):(printf("%d%c^%d",p->data,p->var,p->power))) :((p->data == 1)?(printf("+%c^%d",p->var,p->power)):(printf("+%d%c^%d",p->data,p->var,p->power)));            
        }
        
         }
         
         
         if(p->data < 0)
        {
        if(p->power == 1)
        {
(p->data == 1)?(printf("%c",p->var)):(printf("%d%c",p->data,p->var));
        }
        else if(p->power == 0)
        printf("%d",p->data);
        else
        {
(p->data == 1)?(printf("%c%d",p->var,p->power)):(printf("%d%c%d",p->data,p->var,p->power));            
        }
        
        }

        p = p->right;
    }
    printf("\n");
}  
}

void appendPolyAddition()
{
    int i;
    struct Poly3 *p,*tmp[(n+1)];
    for(i=n;i>=0;i--)
    {
    tmp[i] = (struct Poly3 *)malloc(sizeof(struct Poly3));
    tmp[i]->left = NULL;
    tmp[i]->right = NULL;
    // By this time we prepared the node.
    if(root3 == NULL)
    {
        root3 = tmp[i];
    }
    
    else
    {
        p = root2;
        while(p->right !=NULL)
        {
            p = p->right;
        }
        // Making Right link connection is more important
        p ->right = tmp[i];
        tmp[i]->left = p;
    }
    
    } 
}

void printPolyAddition()
{
    
}

void main()
{
    appendPoly1();
    printPoly1();
    printf("\n=====================================================\n");
       appendPoly2();
    printPoly2();
}

