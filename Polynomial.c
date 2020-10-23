/******************************************************************************
                    Polynomial  Arithmetic
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct Poly
{
    int data;
    char var;
    int power;
    struct Node* left;
    struct Node* right;
};

struct Poly *root1,*root2,*root3,*root4 = NULL;

void printPoly(int n, struct Poly *x)
{
       struct Poly* p;
    if (x == NULL)
    {
        printf("\nPolynomial is empty !!\n");
    }

    else
    {
        int nc = 0;
        p = x;
            printf("( ");
        while (p != NULL)
        {
            nc++;
            if (p->data > 0)
            {

                if (p->power == 1)
                {
                    (nc == 1) ? ((p->data == 1) ? (printf("%c", p->var)) : (printf("%d%c", p->data, p->var))) : ((p->data == 1) ? (printf("+%c", p->var)) : (printf("+%d%c", p->data, p->var)));
                }
                else if (p->power == 0)
                {
                    (nc == 1) ? printf("%d", p->data) : printf("+%d", p->data);
                }
                else
                {
                    (nc == 1) ? ((p->data == 1) ? (printf("%c^%d", p->var, p->power)) : (printf("%d%c^%d", p->data, p->var, p->power))) : ((p->data == 1) ? (printf("+%c^%d", p->var, p->power)) : (printf("+%d%c^%d", p->data, p->var, p->power)));
                }

            }


            else
            {
                if (p->power == 1)
                {
                    (p->data == -1) ? (printf("-%c", p->var)) : (printf("%d%c", p->data, p->var));
                }
                else if (p->power == 0)
                    printf("%d", p->data);
                else
                {
                    (p->data == -1) ? (printf("-%c^%d", p->var, p->power)) : (printf("%d%c^%d", p->data, p->var, p->power));
                }

            }

            p = p->right;
        }
       printf(" )  ");
    }
    
}


void appendPoly1(int n, char polyVar)
{
    int i;
    printf("\n---\tPolynomial 1\t---\n");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    struct Poly *p,*tmp1;
    for (i = n; i >= 0; i--)
    {
        tmp1 = (struct Poly*)malloc(sizeof(struct Poly));
        printf("\nEnter the %d term coefficient value??\n", i);
        scanf("%d", &tmp1->data);
        getchar();
        tmp1->var = polyVar;
        tmp1->power = n--;
        tmp1->left = NULL;
        tmp1->right = NULL;
        // By this time we prepared the node.
        if (root1 == NULL)
        {
            root1 = tmp1;
        }

        else
        {
            p = root1;
            while (p->right != NULL)
            {
                p = p->right;
            }
            // Making Right link connection is more important
            p->right = tmp1;
            tmp1->left = p;
        }

    }
}


void appendPoly2(int n, char polyVar)
{
    int i;
    printf("\n---\tPolynomial 2\t---\n");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    struct Poly *p,*tmp2;
    for (i = n; i >= 0; i--)
    {
        tmp2 = (struct Poly*)malloc(sizeof(struct Poly));
        printf("\nEnter the %d term coefficient value??\n", i);
        scanf("%d", &tmp2->data);
        getchar();
        tmp2->var = polyVar;
        tmp2->power = n--;
        tmp2->left = NULL;
        tmp2->right = NULL;
        // By this time we prepared the node.
        if (root2 == NULL)
        {
            root2 = tmp2;
        }

        else
        {
            p = root2;
            while (p->right != NULL)
            {
                p = p->right;
            }
            // Making Right link connection is more important
            p->right = tmp2;
            tmp2->left = p;
        }

    }

}


void appendPolyAddition(int n, char polyVar)
{
    struct Poly *p1,*p2,*p,*tmp;
    p1 = root1;
    p2 = root2;
    while(p1 && p2)
    {
          tmp = (struct Poly*)malloc(sizeof(struct Poly));
            
        if ((p1->data + p2->data) == 0)
        {
            n--;
            continue;
        }
        tmp->data = p1->data + p2->data;
        tmp->var = polyVar;
        tmp->power = n--;
        tmp->left = NULL;
        tmp->right = NULL;
        // By this time we prepared the node.
        if (root3 == NULL)
        {
            root3 = tmp;
        }

        else
        {
            p = root3;
            while (p->right != NULL)
            {
                p = p->right;
            }
            // Making Right link connection is more important
            p->right = tmp;
            tmp->left = p;
        }
         p2 = p2->right;
        p1 = p1->right;
    
    }     
}

void appendPolySubs(int n, char polyVar)
{
        struct Poly *p1,*p2,*p,*tmp;
    p1 = root1;
    p2 = root2;
    while(p1 && p2)
    {
          tmp = (struct Poly*)malloc(sizeof(struct Poly));
            
        if ((p1->data - p2->data) == 0)
        {
            n--;
            continue;
        }
        tmp->data = p1->data - p2->data;
        tmp->var = polyVar;
        tmp->power = n--;
        tmp->left = NULL;
        tmp->right = NULL;
        // By this time we prepared the node.
        if (root3 == NULL)
        {
            root3 = tmp;
        }

        else
        {
            p = root3;
            while (p->right != NULL)
            {
                p = p->right;
            }
            // Making Right link connection is more important
            p->right = tmp;
            tmp->left = p;
        }
         p2 = p2->right;
        p1 = p1->right;
    
    } 
}


void appendPolyMultiply(int n, char polyVar)
{
    int k=0;
    struct Poly *p,*p1,*p2,*z,*tmp;
    p1 = root1, p2 = root2;
    z = p2;
        while (p1 != NULL)
        {
            while (p2 != NULL)
            {
                tmp = (struct Poly*)malloc(sizeof(struct Poly));
                if (p1->data * p2->data == 0)
                {
                    continue;
                }
                tmp->data = p1->data * p2->data;
                tmp->var = polyVar;
                tmp->power = (p1->power + p2->power);

                // Now appending.
                if (root3 == NULL)
                {
                    root3 = tmp;

                }

                else
                {
                    p = root3;
                    while (p->right != NULL)
                    {
                        p = p->right;
                    }
                    // Making Right link connection is more important
                    p->right = tmp;
                    tmp->left = p;

                }
                p2 = p2->right;
                k++;
            }
            p2 = z;
            p1 = p1->right;
        }
    }
       


void equation(int n,char polyVar)
{
    struct Poly *p,*z,*w,*x;
           p = root3;
           z = p;
    w = root4;
    int pw,s=0;
    for(pw=(2*n);pw>=0;pw--)
    {
        s =0;
         x = (struct Poly*)malloc(sizeof(struct Poly));
      while(p)
      {
            if(p->power == pw)
            {
            s= s+(p->data);
           }
       p = p->right;
      }
      x->data = s;
      x->var = polyVar;
      x->power = pw;
        x->left = NULL;
            x->right = NULL;
                      if (root4 == NULL)
                    {
                    root4 = x;

                     }

                else
                {
                    w = root4;
                    while (w->right != NULL)
                    {
                        w = w->right;
                    }
                    // Making Right link connection is more important
                    w->right = x;
                    x->left = w;

                }
             p =z;       
    }
    }

void main()
{
     int n,ch;
    char polyVar;

    while (1)
    {
        printf("\n1.Add Poly\n2.Substract Poly\n3.Multiply\n4.Exit\n\n");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("\nSupply n-th degree polynomial to be created?\n");
            scanf("%d", &n);
            getchar();
            printf("\nEnter the underlying variable for both of the Polynomials??\n");
            scanf("%c", &polyVar);
            getchar();
            appendPoly1(n, polyVar);
            appendPoly2(n, polyVar);
            appendPolyAddition(n, polyVar);
            printf("\n\n===========================<<<RESULT>>>=================================\n\n");
            printPoly(n,root1);
            printf(" + ");
             printPoly(n,root2);
            printf("  =   ");
            printPoly(n,root3);
              printf("\n");
            break;
        case 2:
            printf("\nSupply n-th degree polynomial to be created?\n");
            scanf("%d", &n);
            getchar();
            printf("\nEnter the underlying variable for both of the Polynomials??\n");
            scanf("%c", &polyVar);
            getchar();
            appendPoly1(n, polyVar);
            appendPoly2(n, polyVar);
            appendPolySubs(n, polyVar);
            printf("\n\n===========================<<<RESULT>>>=================================\n\n");
            printPoly(n,root1);
            printf(" - ");
            printPoly(n,root2);
            printf(")");
            printf("  =   ");
            printPoly(n,root3);
              printf("\n");
            break;
        case 3:
            printf("\nSupply n-th degree polynomial to be created?\n");
            scanf("%d", &n);
            getchar();
            printf("\nEnter the underlying variable for both of the Polynomials??\n");
            scanf("%c", &polyVar);
            getchar();
            appendPoly1(n, polyVar);
            appendPoly2(n, polyVar);
            appendPolyMultiply(n, polyVar);
            printf("\n\n===========================<<<RESULT>>>=================================\n\n");
            printPoly(n,root1);
            printf(" X  ");
            printPoly(n,root2);
            printf("  =   ");
            equation(n,polyVar);
            printPoly(n,root4);
            printf("\n");
            break;
        case 4: exit(0);
        default: printf("\nInvalid  Choice entered\n");
        }
    }
  

}
