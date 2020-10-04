/*
sample demo of qsort()
*/
#include <stdio.h>
#include <stdlib.h>

int compare(const void* p, const void* q)
{
	 // return (*(int *)q - *(int*)p);          ------  Returns greater of the two.
	return (*(int*)p - *(int*)q);            //         Returns smaller of the two.
}

int main()
{
	int arr[] = { 1,10,2,80,13,44,12,3,99,25 };
	int n = sizeof(arr) / sizeof(arr[0]);
	qsort((void*)arr, n, sizeof(int), compare);
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}