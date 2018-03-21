#include "stdio.h"

void display(int *, int);

void selectionsort(int *A, int N)
{
  int i, j, min, m, t;
  for(i=0; i < N-1; i++)
  {
    min = A[i]; m = i;
    for(j=i+1; j < N; j++)
    {
      if (A[j] < min)
      {
        min = A[j]; m = j;
      }
    } // end inner for-loop
    if (m != i)
    {
      A[m] = A[i];
      A[i] = min;
    }
  }
}

void main()
{
  int numbers[5] = {42, 13, 2, 18, 22};
  printf("Before sorting\n");
  display(numbers, 5);
  selectionsort(numbers, 5);
  printf("After sorting\n");
  display(numbers, 5);
}

void display(int *A, int N)
{
  int i;
  for (i=0; i < N; i++)
    printf("%d ",A[i]);
  printf("\n");
  
}