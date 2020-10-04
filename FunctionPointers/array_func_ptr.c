/*
This code focusses on the Array of Pointers to functions
*/
#include <stdio.h> 
void add(int a, int b)
{
	printf("Addition is %d\n", a + b);
}
void subtract(int a, int b)
{
	printf("Subtraction is %d\n", a - b);
}
void multiply(int a, int b)
{
	printf("Multiplication is %d\n", a * b);
}

int main()
{
	void (*fp[])(int, int) = { add,subtract,multiply };
	int ch,a,b;
	printf("\nEnter your choice??\n");
	scanf("%d", &ch);
	printf("\nEnter two numeric values??\n");
	scanf("%d%d", &a, &b);
	if (ch < 0 || ch >2) exit();
    (*fp[ch])(a, b);
	return 0;
}