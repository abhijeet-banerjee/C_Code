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

struct Poly3
{
    int data;
    char var;
    int power;
    struct Node* left;
    struct Node* right;
};

struct Poly4
{
    int data;
    char var;
    int power;
    struct Node* left;
    struct Node* right;
};

struct Poly1* root1 = NULL;
struct Poly2* root2 = NULL;
struct Poly3* root3 = NULL;
struct Poly4* root4 = NULL;
struct Poly1* tmp1[100];
struct Poly2* tmp2[100];
struct Poly3* tmp3[100];
struct Poly4* tmp4[100];

void appendPoly1(int n, char polyVar)
{
    int i;
    printf("\n---\tPolynomial 1\t---\n");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    struct Poly1* p;
    for (i = n; i >= 0; i--)
    {
        tmp1[i] = (struct Poly1*)malloc(sizeof(struct Poly1));
        printf("\nEnter the %d term coefficient value??\n", i);
        scanf("%d", &tmp1[i]->data);
        getchar();
        tmp1[i]->var = polyVar;
        tmp1[i]->power = n--;
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

void printPoly1(int n)
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
        while (p != NULL && n >= 0)
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


void appendPoly2(int n, char polyVar)
{
    int i;
    printf("\n---\tPolynomial 2\t---\n");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    struct Poly2* p;
    for (i = n; i >= 0; i--)
    {
        tmp2[i] = (struct Poly2*)malloc(sizeof(struct Poly2));
        printf("\nEnter the %d term coefficient value??\n", i);
        scanf("%d", &tmp2[i]->data);
        getchar();
        tmp2[i]->var = polyVar;
        tmp2[i]->power = n--;
        tmp2[i]->left = NULL;
        tmp2[i]->right = NULL;
        // By this time we prepared the node.
        if (root2 == NULL)
        {
            root2 = tmp2[i];
        }

        else
        {
            p = root2;
            while (p->right != NULL)
            {
                p = p->right;
            }
            // Making Right link connection is more important
            p->right = tmp2[i];
            tmp2[i]->left = p;
        }

    }
}


void printPoly2(int n)
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
        while (p != NULL && n >= 0)
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

void appendPolyAddition(int n, char polyVar)
{
    int i;
    struct Poly3* p;
    for (i = n; i >= 0; i--)
    {
        if ((tmp1[i]->data + tmp2[i]->data) == 0)
        {
            n--;
            continue;
        }
        tmp3[i] = (struct Poly3*)malloc(sizeof(struct Poly3));
        tmp3[i]->data = tmp1[i]->data + tmp2[i]->data;
        tmp3[i]->var = polyVar;
        tmp3[i]->power = n--;
        tmp3[i]->left = NULL;
        tmp3[i]->right = NULL;
        // By this time we prepared the node.
        if (root3 == NULL)
        {
            root3 = tmp3[i];
        }

        else
        {
            p = root3;
            while (p->right != NULL)
            {
                p = p->right;
            }
            // Making Right link connection is more important
            p->right = tmp3[i];
            tmp3[i]->left = p;
        }

    }
}

void printPolyAddition(int n)
{
    struct Poly3* p;
    if (root3 == NULL)
    {
        printf("\nPolynomial is empty !!\n");
    }

    else
    {
        int nc = 0;
        p = root3;
        while (p != NULL && n >= 0)
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
        printf("\n\n");
    }
}

void appendPolySubs(int n, char polyVar)
{
    int i;
    struct Poly4* p;
    for (i = n; i >= 0; i--)
    {
        if ((tmp1[i]->data - tmp2[i]->data) == 0)
        {
            n--;
            continue;
        }
        tmp4[i] = (struct Poly4*)malloc(sizeof(struct Poly4));
        tmp4[i]->data = tmp1[i]->data - tmp2[i]->data;
        tmp4[i]->var = polyVar;
        tmp4[i]->power = n--;
        tmp4[i]->left = NULL;
        tmp4[i]->right = NULL;
        // By this time we prepared the node.
        if (root4 == NULL)
        {
            root4 = tmp4[i];
        }

        else
        {
            p = root4;
            while (p->right != NULL)
            {
                p = p->right;
            }
            // Making Right link connection is more important
            p->right = tmp4[i];
            tmp4[i]->left = p;
        }

    }
}

void printPolySubs(int n)
{
    struct Poly4* p;
    if (root4 == NULL)
    {
        printf("\nPolynomial is empty !!\n");
    }

    else
    {
        int nc = 0;
        p = root4;
        while (p != NULL && n >= 0)
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
        printf("\n\n");
    }
}

void main()
{
    int n,ch;
    char polyVar;

    while (1)
    {
        printf("\n1.Add Poly\n2.Substract Poly\n3.Exit\n\n");
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
            printf("\t");
            printf("(");
            printPoly1(n);
            printf(")");
            printf(" + ");
            printf("(");
            printPoly2(n);
            printf(")");
            printf("  =  ");
            printPolyAddition(n);
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
            printf("\t");
            printf("(");
            printPoly1(n);
            printf(")");
            printf(" - ");
            printf("(");
            printPoly2(n);
            printf(")");
            printf("  =  ");
            printPolySubs(n);
            break;
        case 3: exit(0);
        default: printf("\nInvalid  Choice entered\n");
        }
    }
  

}
