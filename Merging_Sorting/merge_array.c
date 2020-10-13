/*
Merging of two arrays
*/
#include <stdio.h>
int arr1[100];
int arr2[100];
int res[100];
int n1, n2;
void quicksort(int arr[], int l, int r)
{
    int i, j;
    i = l;                     // This is the leftmost element
    j = r;                    // This is the rightmost element
    // Assign the pivot element
    int p = arr[i], flag = 0, t;
    if (r > l)
    {
        while (!flag)
        {
            while (arr[i] <= p && i <= r)
            {
                i++;         // Condition for increasing
            }
            while (arr[j] >= p && j > l)
            {
                j--;
            }
            if (i >= j)
            {
                // Swap a[l] and a[j] and set flag =1 and come out.
                t = arr[l];
                arr[l] = arr[j];
                arr[j] = t;
                flag = 1;
            }

            else
            {
                // Swap a[i] and a[j]
                t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }

        }                      // end while loop
        quicksort(arr,l, j - 1);
        quicksort(arr,i, r);
    }                         // end if block
}

void mergeArray(int arr1[], int arr2[])
{
   int  i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            res[k] = arr1[i];
            i++;
        }
        else
        {
            res[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        res[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        res[k] = arr2[j];
        j++;
        k++;
    }
}

void main()
{
    int i, j, k;
    printf("\nEnter the size of Array 1??\n");
    scanf("%d", &n1);
    for (i = 0; i < n1; i++)
    {
        printf("\nEnter the element %d for Array 1??\n",(i+1));
        scanf("%d", &arr1[i]);
    }
    printf("\nEnter the size of Array 2??\n");
    scanf("%d", &n2);
    for (i = 0; i < n2; i++)
    {
        printf("\nEnter the element %d for Array 2??\n", (i + 1));
        scanf("%d", &arr2[i]);
    }
    quicksort(arr1, 0, (n1 - 1));
    quicksort(arr2, 0, (n2 - 1));
    printf("\n");
    for (i = 0; i < n1; i++)
    {
        printf("%d\t", arr1[i]);
    }
    printf("\n");
    for (i = 0; i < n2; i++)
    {
        printf("%d\t", arr2[i]);
    }
    mergeArray(arr1, arr2);
    printf("\n\nResultant Merged\n\n");
    for (i = 0; i < (n1+n2); i++)
    {
        printf("%d\t", res[i]);
    }
    printf("\n");
}
