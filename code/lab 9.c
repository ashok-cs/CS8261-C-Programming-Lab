#include "stdio.h"
#include "string.h"
#include "ctype.h"

int main(void) {
  char A[20];
  char t;
  int left, right;
  scanf("%s", A);
  left = 0;
  right = strlen(A) - 1;
  while (left < right)
  {
    while(!isalpha(A[left])) left++;
    while(!isalpha(A[right])) right--;
    if (left < right)
    {
      t = A[left];
      A[left] = A[right];
      A[right] = t;
      left++; right--; 
    }
  }
  printf("%s\n", A);
  return 0;
}