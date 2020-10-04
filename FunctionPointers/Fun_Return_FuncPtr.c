/*
Function that return a function pointer
*/
#include <stdio.h>
int add(int a, int b)
{
	return (a + b);
}

int sub(int a, int b)
{
	return (a - b);
}

int mul(int a, int b)
{
	return (a * b);
}

int (*funptr(char ch))(int, int)
{
	return (ch == '+') ? add : ((ch == '-') ? sub : mul);
}

void main()
{
	printf("%d\n", funptr('+')(77, 88));
}