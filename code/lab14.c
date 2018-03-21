#include "stdio.h"
#define MAX 10

struct emp
{
int empno ;
char name[20];
float basic, allowance, deduction, netpay ; 
};

void getDetails(struct emp *, int );
void display(struct emp *, int);

int main(void) {
  struct emp staff[MAX];
  int N;
  printf("Enter Number of employees(<= %d)\n", MAX);
  scanf("%d", &N);
  getDetails(staff,N);
  display(staff, N);
  return 0;
}

void getDetails(struct emp * staff, int N)
{
  int i;
  for(i=0; i < N; i++)
  {
    printf("Employee # %d\n", i+1);
    printf("Enter name:");
    scanf("%s", staff[i].name);
    printf("Enter basic pay:");
    scanf("%f", &staff[i].basic);
    printf("Enter allowance:");
    scanf("%f", &staff[i].allowance);
    printf("Enter deduction:");
    scanf("%f", &staff[i].deduction);
    staff[i].netpay = staff[i].basic  + staff[i].allowance - staff[i].deduction;
  }
}

void display(struct emp * staff, int N)
{
  int i;
  for(i=0; i < N; i++)
  {
    printf("\n\nSalary slip for employee # %d\n", i+1);
    printf("*************************\n");
    printf("Name: %s \n", staff[i].name );
    printf("Basic pay: Rs. %.2f \n", staff[i].basic);
    printf("Allowance: Rs. %.2f \n", staff[i].allowance);
    printf("Deduction: Rs. %.2f \n", staff[i].deduction);
    printf("Net pay: Rs. %.2f \n", staff[i].netpay);
    printf("*************************\n\n");
  }
}
