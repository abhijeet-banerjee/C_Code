#include <stdio.h>

void fun1()
{
	printf("\n I am from function 1\n");
}
void fun2()
{
	printf("\n I am from function 2\n");
}

void passFunPtrAsArg(void (*funptr)())
{
	funptr();
}

int main()
{
	passFunPtrAsArg(fun1);
	passFunPtrAsArg(fun2);
	return 0;
}