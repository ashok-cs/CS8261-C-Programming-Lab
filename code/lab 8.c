#include "stdio.h"
#define SIZE 2

int main(void) {
  float WH[SIZE][SIZE];
  float BMI[SIZE];
  for(int i=0; i < SIZE; i++)
  {
    printf("Enter weight(kg) and height(m) for Person %d:\n", i+1);
    scanf("%f %f",&WH[i][0], &WH[i][1]);
  }
  for(int i=0; i < SIZE; i++)
  {
      BMI[i] = WH[i][0] / (WH[i][1] * WH[i][1]);
      printf("BMI for person %d: %.1f\n", i+1, BMI[i]);
  }
}