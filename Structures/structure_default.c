#include <stdio.h>

struct
{
int id;
char name[50];
char job[50];
}
p={12456789,"Abhijeet","Software Engg"};

int main()
{
 
printf("%d\n",p.id);
printf("%s\n",p.name);
printf("%s\n",p.job);
    return 0;
}
