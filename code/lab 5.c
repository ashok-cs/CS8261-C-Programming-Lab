#include<stdio.h>
void main(){
	int A;
	int sum = 0; 
	int T;
	scanf("%d", &A);
	T = A;
	while (T > 0)
	{
		d = T % 10;
		sum += pow(d,3);
		T /= 10;
	}
	if ( sum == A)
		printf("Armstrong number");
	else
		printf("Not an armstrong number");
}