#include "stdio.h"
#define SIZE 5

int main(void) {
  int A[SIZE];
  int i, sum = 0, total;
  float avg;
  
  for (i=0; i < SIZE; i++){
    scanf("%d", &A[i]);
    sum += A[i];
  }
  
  avg = sum / SIZE;
  printf("Average height: %f \n", avg);
  
  total = 0;
  for (i=0; i < SIZE; i++){
    if(A[i] > avg)
      total++;
  }
  printf("Number of persons above average height: %d \n", total);
  
  return 0;
}