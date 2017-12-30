#include "stdio.h"
int main(){
	int a, b= 50, c;
	a = 5 <= 8 && 6 != 5;	
	c =  b++ + ++b;
	printf("a= %d, b= %d, c=%d \n", a, b, c);
}