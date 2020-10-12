/******************************************************************************
                                 Quick Sort
*******************************************************************************/

#include <stdio.h>
#define MAX 100

void quicksort(int,int);
int arr[MAX],n;

int main()
{
     int i;
   printf("\nEnter size??\n");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
       printf("\nEnter element %d\n",(i+1));
       scanf("%d",&arr[i]);
   }
   printf("\nAfter Sorting\n\n");
   quicksort(0,(n-1));
             for(i=0;i<n;i++)
             {
       printf("%d\n",arr[i]);
           }
    return 0;
}

void quicksort(int l,int r)
{
    int i,j;
    i = l;                     // This is the leftmost element
    j = r;                    // This is the rightmost element
    // Assign the pivot element
    int p = arr[i], flag = 0, t;
    if(r>l)
    {
        while(!flag)
        {
            while(arr[i]<=p && i<=r)
            {
                i++;         // Condition for increasing
            }
            while(arr[j]>=p && j>l)
            {
                j--;
            }
            if(i>=j)
            {
                // Swap a[l] and a[j] and set flag =1 and come out.
                t=arr[l];
                arr[l]=arr[j];
                arr[j]=t;
                flag=1;
            }
            
            else
            {
                  // Swap a[i] and a[j]
                t=arr[i];
                arr[i]=arr[j];
                arr[j]=t;
            }
            
        }                      // end while loop
        quicksort(l,j-1);
        quicksort(i,r);
    }                         // end if block
}
