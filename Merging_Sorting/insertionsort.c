/******************************************************************************
                          Insertion Sort
*******************************************************************************/

#include <stdio.h>

void insertionSort(int *,int);

int main()
{
 int i,n;
 printf("\nEnter total no. of elements???\n");
 scanf("%d",&n);
 int a[n];
 for(i=0;i<n;i++)
 {
     printf("\nEnter element %d\n",(i+1));
 scanf("%d",&a[i]); 
 }
insertionSort(a,n);
printf("\n\n ::: INSERTION SORTING :::\n\n");
 for(i=0;i<n;i++)
 {
     printf("%d\n",a[i]);
 }

    return 0;
}

void insertionSort(int a[], int n)
{
    int i,j,key;
    for(i=1;i<n;i++)
    {
        key = a[i];
        j = i-1;
     while(j>=0 && a[j]>key)
     {
        a[j+1] = a[j];
        j--;
     }
     a[j+1] = key;
    }
}
