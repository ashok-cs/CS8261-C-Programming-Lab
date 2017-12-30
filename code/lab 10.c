#include "stdio.h"
#include "string.h"

void strrev(char* S){
  int right = strlen(S)-1;
  int left = 0;
  char t;
  while(left < right){
    t = S[left];
    S[left++] = S[right];
    S[right--] = t;
  }
  printf("\n");
}

char get_digit(int d){
  switch(d){
    case 10: return 'A';
    case 11: return 'B';
    case 12: return 'C';
    case 13: return 'D';
    case 14: return 'E';
    case 15: return 'F';
    default: return d + '0';
  }
}


void conv(int decimal, int base, char b[]){
  int i = 0; 
  if(base != 2 && base != 8 && base != 16)
    {strcpy(b,"NA"); return;} 
  while(decimal > 0){
    b[i] =  get_digit(decimal % base);
    decimal /= base; 
    i++;
  }
  strrev(b);
}


int main(void) {
  int decimal;
  char bin[20], oct[20], hex[20];
  scanf("%d", &decimal);
  conv(decimal, 2, bin);
  printf("binary = %s\n", bin);
  conv(decimal, 8, oct);
  printf("octal = %s\n", oct );
  conv(decimal, 16, hex);
  printf("hex = %s\n", hex);
  return 0;
}