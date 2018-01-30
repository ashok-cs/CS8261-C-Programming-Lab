#include<stdio.h>
#include<math.h>
int main()
{
	int choice;
	int x, y;
	float z;
	printf("1	Addition\n");
	printf("2	Subtraction\n");
	printf("3	Multiplication\n");
	printf("4	Division\n");
	printf("5	Square root\n");
	printf("Enter choice:");
	scanf("%d", &choice);
	printf("Enter the input values\n");
	scanf("%d", &x);
	if(choice != 5)
		scanf("%d",&y);
	switch(choice)
	{
		case 1: z = x + y; break;
		case 2: z = x - y; break;
		case 3: z = x * y; break;
		case 4: z = (float) x / y; break;
		case 5: z = sqrt(x) ; break;
	}
	printf("%f", z);
}