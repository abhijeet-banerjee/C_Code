/******************************************************************************
                      SLL Implemntation with core features
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* root = NULL;

void append()
{
    struct Node* p, * tmp;
    tmp = (struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter the value for the node to be appended??\n");
    scanf("%d", &tmp->data);
    tmp->next = NULL;
    if (root == NULL)
    {
        root = tmp;
    }
    else {
        p = root;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = tmp;
    }
}

int length()
{
    struct Node* p;
    p = root;
    int count = 0;
    while (p) {
        p = p->next;
        count++;
    }
    return count;
}

void afterwards()
{
    struct Node* p, * tmp;
    int pos;
    printf("\nEnter after which position node has to be added??\n");
    scanf("%d", &pos);
    tmp = (struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter the value for the node to be inserted afterwards node %d??\n", pos);
    scanf("%d", &tmp->data);
    tmp->next = NULL;
    // Node Prepared by now.
    if (pos > 0 && pos <= length())
    {
        if (root == NULL)
        {
            root = tmp;
        }
        else
        {
            int i = 1;
            p = root;
            while (i < pos)
            {
                p = p->next;
                i++;
            }
            tmp->next = p->next;
            p->next = tmp;
        }

    }
    else
    {
        printf("\nInvalid position\n");
    }
}

void start()
{
    struct Node* tmp;
    tmp = (struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter the value for the node to be inserted at beginning??\n");
    scanf("%d", &tmp->data);
    tmp->next = NULL;
    tmp->next = root;
    root = tmp;
}

void reverse_sll()
{
    int i = 0, j = length() - 1, k, tmp;
    struct Node* p, * q;
    p = q = root;
    while (i < j)
    {
        k = 0;
        while (k < j)
        {
            q = q->next;
            k++;
        }
        tmp = p->data;
        p->data = q->data;
        q->data = tmp;

        i++;
        j--;
        p = p->next;
        q = root;

    }
}

void sort()
{
    int i, j, tmp;
    struct Node* p, * q;
    p = root;
    while (p != NULL)
    {
        for (q = p->next; q != NULL; q = q->next)
        {
            if (p->data > q->data)
            {
                tmp = p->data;
                p->data = q->data;
                q->data = tmp;
            }
        }
        p = p->next;
    }
}

void print()
{
    struct Node* p;
    p = root;
    if (root == NULL)
    {
        printf("\nList empty\n");
    }
    while (p != NULL)
    {
        printf("%d --->> ", p->data);
        p = p->next;
    }
    printf("\n");
}

void deleteStart()
{
    struct Node* p;
    if (root == NULL)
    {
        printf("\nNothing to delete as LL is empty\n");
    }
    else
    {
        p = root;
        root = p->next;
        free(p);
    }

}


void deleteLast()
{
    struct Node *p,*q;
    int i = 0, j = 0;
    if (root == NULL)
    {
        printf("\nList empty\n");
        exit(0);
    }
    if (length() == 1)
        deleteStart();
    else
    {
        p = q = root;
        while (p->next!=NULL)
        {
            p = p->next;
            i++;
        }
        while (j < (length() - 2))
        {
            q = q->next;
            j++;
        }
        q->next = NULL;
        free(p);
    }

}


void deleteAnywhere()
{
    struct Node *p,*q;
    int pos, i=0,j = 0;
    printf("\nEnter the position of the node??\n");
    scanf("%d", &pos);
    if (root == NULL)
    {
        printf("\nList empty\n");
        exit(0);
    }
    if (pos == 1)
        deleteStart();
    if (pos == length())
        deleteLast();
    else
    {
        p = q = root;
        while (i < (pos - 1))
        {
            p = p->next;
            i++;
        }
        while(j < (pos - 2))
        {
            q = q->next;
            j++;
        }
        q->next = p->next;
        p->next = NULL;
        free(p);
    }

}

int main()
{
    int ch;
    while (1)
    {
        printf("\n1.Append\n2.AddAnywhere\n3.Length\n4.Add at starting\n5.Print\n6.Reverse SLL\n7.Sort\n8.Delete at Start\n9. Delete at Last\n10.Delete Anywhere\n11.Exit\n\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: append();
            break;

        case 2: afterwards();
            break;

        case 3:  printf("Length = %d ", length());
            break;

        case 4: start();
            break;

        case 5: print();
            break;

        case 6: reverse_sll();
            break;

        case 7: sort();
            break;

        case 8: deleteStart();
            break;

        case 9: deleteLast();
            break;

        case 10: deleteAnywhere();
            break;

        case 11: exit(0);
            break;
        }
    }
    return 0;
}
