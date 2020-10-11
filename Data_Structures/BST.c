#include <stdio.h>
#include <stdlib.h>

struct BST
{
	int data;
	struct BST* left;
	struct BST* right;
};

struct BST* root = NULL;

void insert()
{
	struct BST* t, * p, * curr;;
	t = (struct BST*)malloc(sizeof(struct BST));
	printf("\nEnter the value of the node to be inserted into the BST??\n");
	scanf("%d",&t->data);
	t->left = NULL;
	t->right = NULL;

	if (root == NULL)
	{
		root = t;
	}
	else
	{
		p = curr = root;
		while (curr)
		{
			p = curr;
			if (t->data > curr->data)
				curr = curr->right;
			else
				curr = curr->left;
		}
		if ((t->data) > (p->data))
			p->right = t;
		else
			p->left = t;
	}
}

int newNodeValue(struct BST *z)
{
	struct BST *q;
	q = z->left;
	int d = q->data;
	z->left = q->left;
	free(q);
	return d;

}

void deleteBSTNode(int n)
{
	struct BST *curr;
	curr = root;
	int cn = totalChildNodes(n);
	switch (cn) {
	case 0:
		while (curr)
		{
			if (n > curr->data)
			{
				if (curr->right->left == NULL && curr->right->right == NULL)
				{
					curr->right = NULL;
					curr = curr->right;
					break;
				}
					curr = curr->right;
			}
			else
			{
				if (curr->left->left == NULL && curr->left->right == NULL)
				{
					curr->left = NULL;
					curr = curr->left;
					break;
				}
					curr = curr->left;
			}
		}
		free(curr);
		break;
	case 1:
		while (curr)
		{
			if (n > curr->data)
				curr = curr->right;
			else if (n < curr->data)
				curr = curr->left;
			else
				break;
		}
		if (curr->left !=NULL)
		{
			curr->data = curr->left->data;
			curr->left = NULL;
			free(curr->left);
		}
		if (curr->right != NULL)
		{
			curr->data = curr->right->data;
			curr->right = NULL;
			free(curr->right);
		}
		break;
	case 2:
		while (curr)
		{
			if (n > curr->data)
				curr = curr->right;
			else if (n < curr->data)
				curr = curr->left;
			else
				break;
		}
		int val = newNodeValue(curr);
		curr->data = val;
		break;
	}
}
int totalChildNodes(int n)
{
	struct BST* p;
	p = root;
	int count = 0;
	while (p)
	{
		if (n > p->data)
			p = p->right;
		else if (n < p->data)
			p = p->left;
		else
			break;
	}
	if (p->left) count++;
	if (p->right) count++;
	return count;
}

void inorder(struct BST *t)
{
	if (t == NULL)
	{
		printf("\nBST is empty as of now\n");
	}
	else
	{
		if (t->left != NULL)
			inorder(t->left);
		printf("  %d  ", t->data);
		if (t->right != NULL)
			inorder(t->right);
	}
}

void preorder(struct BST *t)
{
	printf(" %d ", t->data);
	if (t->left != NULL)
		inorder(t->left);
	if (t->right != NULL)
		inorder(t->right);
}

void postorder(struct BST *t)
{
	if (t->left != NULL)
		inorder(t->left);
	if (t->right != NULL)
		inorder(t->right);
	printf("  %d  ", t->data);
}

int main()
{
	int ch,v;
	while (1)
	{
		printf("\n1.Insert\n2.Print\n3.Count Total no. of Child nodes?\n4.Delete Node\n5.Exit\n\n");
		scanf("%d",&ch);
		switch (ch)
		{
		case 1: insert();
			break;
		case 2: inorder(root);
			break;
		case 3: printf("\nEnter a node value??\n");
			scanf("%d",&v);
			printf("\nTotal Child Nodes =  %d \n",totalChildNodes(v));
			break;
		case 4: printf("\nEnter a node value??\n");
			scanf("%d", &v);
			deleteBSTNode(v);
			printf("\nDeleted Node %d\n", v);
			break;
		case 5: exit(0);

		default: printf("\nInvalid Choice\n");
			break;
		}
	}
	return 0;
}