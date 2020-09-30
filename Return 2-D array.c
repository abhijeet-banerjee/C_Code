/******************************************************************************
         C Program to return 2-D array
       There are the following three ways:
 1. Returning the base address as a pointer to an integer
 2. Returning base address as a pointer to 0th entry of 1-D array
 3. Returning the pointer to 2D-Array
*******************************************************************************/

#include <stdio.h>

#define ROW 3
#define COL 3

// The below part returns the base address as a pointer to an integer
int *a;
int *fun1();

// The below part returns the base address as a pointer to 0th entry of 1-D array
int (*b)[COL];
int (*fun2())[COL];

// The below part returns the pointer to 2D-Array
int (*c)[ROW][COL];
int (*fun3())[ROW][COL];


int main()
{
 int i,j;
 a = fun1();
 
 printf("From Fun1()\n");
 for(i=0;i<ROW;i++)
 {
     for(j=0;j<COL;j++)
     {
         printf("%d ",*(a+i*COL+j));
     }
     printf("\n");
 }
 printf("\n");
 
  b = fun2();
 
 printf("From Fun2()\n");
 for(i=0;i<ROW;i++)
 {
    int *p = (b+i);
     for(j=0;j<COL;j++)
     {
         printf("%d ",*(p+j));
     }
     printf("\n");
 }
 printf("\n");
 
   c = fun3();
 
 printf("From Fun3()\n");
 for(i=0;i<ROW;i++)
 {
     for(j=0;j<COL;j++)
     {
         printf("%d ",(*c)[i][j]);
     }
     printf("\n");
 }
 printf("\n");
    return 0;
}

int *fun1(){
    static int arr[3][3] ={
        11,22,33,
        44,55,66,
        77,88,99
    };
  return (int *)arr;
}

int (*fun2())[COL]
{
        static int arr[3][3] ={
        11,22,33,
        44,55,66,
        77,88,99
    };
    return arr;
}

int (*fun3())[ROW][COL]
{
        static int arr[3][3] ={
        11,22,33,
        44,55,66,
        77,88,99
    };
    return (int (*)[ROW][COL])arr;
}
