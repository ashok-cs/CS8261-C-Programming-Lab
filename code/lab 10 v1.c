#include "stdio.h"

int dec2bin(int decimal){
  int binary = 0; 
  int zeros = 0;
  while(decimal > 0){
    binary = binary * 10 + decimal % 2;
    if (decimal % 2 == 0 && binary == 0)  zeros++;
    decimal = decimal / 2;
    printf("%d %d\n", binary, decimal);
  }
  while (zeros > 0) { binary *= 10; zeros--; }
  return binary;
}


int main(void) {
  int decimal;
  int binary, octal, hex;
  scanf("%d", &decimal);
  binary = dec2bin(decimal);
  //octal = dec2oct(decimal);
  //hex = dec2hex(decimal);
  printf("binary = %d\n", binary);
  //printf("octal = %d\n", octal);
  //printf("hex = %d\n", hex);
  return 0;
}