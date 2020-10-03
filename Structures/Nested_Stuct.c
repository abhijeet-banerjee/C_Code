/*
Nested Structures
*/

#include <stdio.h>
#define MAX 100
struct dob
{
	int dd;
	int mm;
	int yy;
	char zodiac[10];	
};
struct Person *p[MAX];	
int n;
struct Person
{
long long int uid;
char name[50];
char job[50];
struct dob d[MAX];
};

struct Person **fetchBack()
{
	int i;
for(i=0;i<n;i++)
{
	p[i] = (struct Person *) malloc(sizeof(struct Person));
printf("\nEnter your day of birth?\n");
scanf("%d",&p[i]->d[i].dd);
printf("\nEnter your month?\n");
scanf("%d",&p[i]->d[i].mm);
printf("\nEnter your year?\n");
scanf("%d",&p[i]->d[i].yy);
fflush(stdin);
printf("\nEnter your Zodiac Sign?\n");
gets(p[i]->d[i].zodiac);
printf("\nEnter your UID?\n");
scanf("%lld",&p[i]->uid);
fflush(stdin);
printf("\nEnter your Name?\n");
gets(p[i]->name);
printf("\nEnter your Job Title?\n");
gets(p[i]->job);
printf("\n..........................................\n");			
}
	return (struct Person *)p;	
}

void printStruct(struct Person **p)
{
	int i;
	for(i=0;i<n;i++)
	{
printf("DOB & Zodiac Sign : %d/%d/%d, %s\n",p[i]->d[i].dd,p[i]->d[i].mm,p[i]->d[i].yy,p[i]->d[i].zodiac);		
printf("Name : %s\n",p[i]->name);
printf("UID : %lld\n",p[i]->uid);
printf("Job : %s\n\n",p[i]->job);
	}	
}

int main()
{
	printf("\nHow many persons are there??\n");
	scanf("%d",&n);
struct Person **x = fetchBack();
	printStruct(x);
	return 0;
}