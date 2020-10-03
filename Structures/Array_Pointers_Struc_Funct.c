/*
Program to demonstrate function returning Array of Pointers to structures
and another function accepting it as its parameter.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct emp **fetch();
void disp(struct emp **);
struct emp
{
	int eno;
	char name[50];
	int sal;
	
};

	struct emp *p[MAX];
	int n;
	
struct emp **fetch()
{
int i;
for(i=0;i<n;i++)
{
	  p[i] = (struct emp *)malloc(sizeof(struct emp));
	printf("Enter the employee id for Employee %d\n",(i+1));
	scanf("%d",&p[i]->eno);
	fflush(stdin);
	printf("Enter the employee name for Employee %d\n",(i+1));
	gets(p[i]->name);
    printf("Enter the employee salary for Employee %d\n",(i+1));
	scanf("%d",&p[i]->sal);
	fflush(stdin);
	printf("\n---------------------------\n");
}
return (struct emp (*))p;
}

void disp(struct emp **r)
{
int i;	
	for(i=0;i<n;i++)
	{
	printf("Employee no for Employee %d is %d\n",(i+1),r[i]->eno);
	printf("Employee name for Employee %d is %s\n",(i+1),r[i]->name);
	printf("Employee sal for Employee %d is %d\n",(i+1),r[i]->sal);
	printf("\n===============================================\n");	
	}	
}

int main()
{
	printf("Enter the total no. of employees??\n");
	scanf("%d",&n);
	fflush(stdin);
struct emp *e=fetch();
	disp(e);
return 0;	
}

