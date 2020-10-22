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
    struct Node* left;
    struct Node* right;
};

struct Poly2
{
    int data;
    char var;
    int power;
    struct Node* left;
    struct Node* right;
};


struct Poly1* root1 = NULL;

struct Poly1 *tmp1[100];

struct Poly2* root2 = NULL;

void appendPoly1(int n, char polyVar)
{
    int i;
    printf("\n---\tPolynomial 1\t---\n");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    struct Poly1* p;
    for (i = 0; i<n; i++)
    {
        tmp1[i] = (struct Poly1*)malloc(sizeof(struct Poly1));
        printf("\nEnter the %d term coefficient value??\n", i);
        scanf("%d", &tmp1[i]->data);
        getchar();
         printf("\nEnter the %d term exponent value??\n", i);
        scanf("%d", &tmp1[i]->power);
        tmp1[i]->var = polyVar;
        tmp1[i]->left = NULL;
        tmp1[i]->right = NULL;
        // By this time we prepared the node.
        if (root1 == NULL)
        {
            root1 = tmp1[i];
        }

        else
        {
            p = root1;
            while (p->right != NULL)
            {
                p = p->right;
            }
            // Making Right link connection is more important
            p->right = tmp1[i];
            tmp1[i]->left = p;
        }

    }
}

void printPoly1()
{
    struct Poly1* p;
    if (root1 == NULL)
    {
        printf("\nPolynomial is empty !!\n");
    }

    else
    {
        int nc = 0;
        p = root1;
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


            else if (p->data < 0)
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

    }

}

void equation(char polyVar)
{
    struct Poly1 *p,*z;
    struct Poly2 *w,*tmp2;
           p = root1;
           z = p;
    w = root2;
    int pw,s=0;
    for(pw=2;pw>=0;pw--)
    {
        s =0;
         tmp2 = (struct Poly2*)malloc(sizeof(struct Poly2));
      while(p)
      {
            if(p->power == pw)
            {
            s= s+(p->data);
           }
       p = p->right;
      }
      tmp2->data = s;
      tmp2->var = polyVar;
      tmp2->power = pw;
        tmp2->left = NULL;
            tmp2->right = NULL;
                      if (root2 == NULL)
                {
                    root2 = tmp2;

                }

                else
                {
                    w = root2;
                    while (w->right != NULL)
                    {
                        w = w->right;
                    }
                    // Making Right link connection is more important
                    w->right = tmp2;
                    tmp2->left = w;

                }
             p =z;       
    }
    }


void printPoly()
{
    struct Poly2* p;
    if (root2 == NULL)
    {
        printf("\nPolynomial is empty !!\n");
    }

    else
    {
        int nc = 0;
        p = root2;
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
    }
}

void main()
    {
int n;
    char polyVar;
            printf("\nSupply max size?\n");
            scanf("%d", &n);
            getchar();
            printf("\nEnter the underlying variable for both of the Polynomials??\n");
            scanf("%c", &polyVar);
            getchar();
            appendPoly1(n, polyVar);
            printf("\n\n===========================<<<RESULT>>>=================================\n\n");
            printPoly1();
                printf("\n\n===========================<<<FINAL RESULT>>>=================================\n\n");
                equation(polyVar);
            printPoly();

}
