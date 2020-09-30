/******************************************************************************
         C Program create and return a simple 3-D Array
*******************************************************************************/

#include <stdio.h>
void disp(int *,int,int,int);
int main()
{
    int SET,ROW,COL,i,j,k;
    printf("\nEnter total no. of sets??\n");
    scanf("%d",&SET);
    printf("\nEnter total no. of rows??\n");
    scanf("%d",&ROW);
    printf("\nEnter total no. of columns??\n");
    scanf("%d",&COL);
 int arr[SET][ROW][COL];
    for(i=0;i<SET;i++)
    {
        printf("\nInside SET %d\n",(i+1));
        for(j=0;j<ROW;j++)
        {
              printf("\nEnter values for ROW  %d\n",(j+1));
            for(k=0;k<COL;k++)
            {
                scanf("%d",&arr[i][j][k]);
            }
        }
    }
    disp(arr,SET,ROW,COL);
    
    return 0;
}

void disp(int *z,int s,int r,int c)
{
    printf("\n");
    int i,j,k;
        for(i=0;i<s;i++)
    {
        for(j=0;j<r;j++)
        {
            for(k=0;k<c;k++)
            {
                printf("%d ",*(z+i*r*c+j*c+k));
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("\n===========================\n");
    }
    

