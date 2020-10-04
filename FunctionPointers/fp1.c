#include <stdio.h>
void fun(int x)
{
	printf("%d\n", (x*2));
}

int main()
{
	// Create a function pointer pointing to function fun().
	void (*fun_ptr)(int) = &fun;
	// Using the function Pointer
	(*fun_ptr)(100);
	return 0;
}
