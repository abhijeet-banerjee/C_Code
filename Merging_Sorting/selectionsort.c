/******************************************************************************
                               Selection Sort
*******************************************************************************/

#include <stdio.h>

void selectionSort(int *,int);
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
selectionSort(a,n);
printf("\n\n ::: SELECTION SORTING :::\n\n");
 for(i=0;i<n;i++)
 {
     printf("%d\n",a[i]);
 }
    return 0;
}

void selectionSort(int a[], int n)
{
    // We will go till n-2 passes, as the last element would have been sorted
   int i,j,min,t;
    for(i=0;i<n-1;i++)
    {
        min = i;    // Considering first element as min.
        for(j=i+1;j<n;j++)
        {
            if(a[j] < a[min])
            min = j;          //  assign that index as min.
        }
        t =a[i];
        a[i]=a[min];
        a[min]=t;
    }
}
