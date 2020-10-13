/*
--------------------------------------------------------------------------------------
                                Merge Sort
--------------------------------------------------------------------------------------
*/
#include <stdio.h>
void merge_sort(int*, int, int);
void merge(int*, int, int, int);

void main()
{
    int i, n;
    printf("\nEnter total no. of elements???\n");
    scanf("%d", &n);
    int arr[100];
    for (i = 0; i < n; i++)
    {
        printf("\nEnter element %d\n", (i + 1));
        scanf("%d", &arr[i]);
    }
    merge_sort(arr, 0, n-1);
    printf("\n\n ::: MERGE SORTING :::\n\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }

}

void merge_sort(int arr[], int l, int r)
{
    /*
    The idea of this method is to break further and further array into smallest single unit possible
    via recursion.
    */
    if (l < r)
    {
        int m = l + (r - l) / 2;
        // This is because as it is resilient to overflow for larger values of l and r.
        // First Half
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
   }

}

void merge(int arr[], int l, int m, int r)
{
    /*
    The idea of this method is to merge back all the units that were segregated as part of merge_sort
    function back into a consolidated array.
    */

int s1 = (m - l + 1), s2 = (r - m);
    int i, j, k;
    int left[100], right[100]; // Dont worry, setting size 100 wont matter, as no array bounds checking in C
    // Copy the array.
    for (i = 0; i < s1; i++)
        left[i] = arr[l + i];  // bcoz, left array starts from 'l'
    for (j = 0; j < s2; j++)
        right[j] = arr[m + 1 + j];   // bcoz right array starts from mid(or 'm' here) +1.

  // Now, hereafter initialize i,j and k, as beforehand running loops might have cause change in i/j values.
    i = 0, j = 0, k = l;   
    while (i < s1 && j < s2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < s1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < s2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}
