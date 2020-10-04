/*
implement custom search method.
*/
#include <stdio.h>
#include <stdbool.h>

bool compare(const void* p, const void* q)
{
	return (*(int*)p == *(int*)q);
}

int search(void* arr, int arr_size, int el_size, void* x, bool compare(const void* , const void* ))
{
	char* a = (char*)arr;
	int i;
	for (i = 0; i < arr_size; i++)
		if (compare((a + (i * el_size)), x))
			return i;
	return -1;
}

void main()
{
	int x = 145;
	int arr[] = { 12,44,77,88,99,66,77,88,99 };
	int i = search(arr, (sizeof(arr) / sizeof(arr[0])), sizeof(int), &x, compare);
	if (i == -1)
		printf("\nElement not found\n");
	else
		printf("\nElement found at position = %d\n",(i+1));
}
