#include "stdio.h"
#define SIZE 5

int main(){
  int A[SIZE];
  int W[SIZE];
  int i, k, prime, t;
  /* read numbers */
  for(i=0; i < SIZE;  i++){
    scanf("%d", &A[i]);
  }
  
  /* find weights */
  for(i=0; i < SIZE;  i++){
    W[i] = 0;
    // check if A[i] is perfect cube
    for(k = 1 ; k < A[i] / 2; k++ )
    {
      if (k*k*k == A[i])
      {
        W[i] = 5;
        break;
      }
    }
    
    // multiple of 4 and divisible by 6 
    if (A[i] % 4 == 0 && A[i] % 6 == 0 )
      W[i] += 4;
    
    // check if A[i] is prime number
    prime = 1;
    for(k = 2; k < A[i]; k++)
    {
      if (A[i] % k == 0)
      {
        prime = 0;
        break;
      }
    }
    if(prime == 1)
      W[i] += 3;
    
    printf("<%d, %d>, ", A[i], W[i]);
  }
  
  printf("\n After sorting based on weights \n");
  /* sorting based on W */
  for(i=0; i < SIZE; i++)
    for(k=i+1; k < SIZE; k++)
      if (W[i] > W[k])
      {
        t = A[i]; A[i] = A[k]; A[k] = t;
        t = W[i]; W[i] = W[k]; W[k] = t;
      }
  
  /* print after sorting */
  for(i=0; i < SIZE; i++)
    printf("<%d, %d>, ", A[i], W[i]);
  printf("\n");
}