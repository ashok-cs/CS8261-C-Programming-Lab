#include "stdio.h"
#define MAX 10

struct sub{
  int test1, test2, model;
  float internal;
};

struct stud{
  int rollno;
  struct sub subject[5];
};

void getDetails(struct stud *, int);
void display(struct stud *, int);

int main(void) {
  struct stud student[MAX];
  int N;
  printf("Number of students (<= %d):", MAX);
  scanf("%d", &N);
  getDetails(student, N);
  display(student, N);
  return 0;
}

void getDetails(struct stud *student, int N)
{
  int i,j;
  printf("Enter test1, test2, model marks:\n");
  for(i=0; i<N; i++)
  {
    
    student[i].rollno = i+1;
    printf("\tRollNo: %d \n", student[i].rollno);
    for(j=0; j<5; j++)
    {
      printf("subject %d:", j+1);
      scanf("%d", &student[i].subject[j].test1);
      scanf("%d", &student[i].subject[j].test2);
      scanf("%d", &student[i].subject[j].model);
      
      student[i].subject[j].internal = (student[i].subject[j].test1 + student[i].subject[j].test2 + student[i].subject[j].model)/ (3.0 * 5);
    } // end inner for-loop
  }
}

void display(struct stud *student, int N)
{
  int i,j;
  printf("\n\n\t\t Marks statement\n");
  printf("Subject\t Test1\t Test2\t Model\t Internal\n");
  printf("***************************************************\n");
  for(i=0; i<N; i++)
  {
    printf("Roll No %d\n", student[i].rollno);
    for(j=0; j<5; j++)
    {
      printf("%d\t",j+1);
      printf("%d\t",student[i].subject[j].test1);
      printf("%d\t",student[i].subject[j].test2);
      printf("%d\t",student[i].subject[j].model);
      printf("%.0f\n",student[i].subject[j].internal);
    }
  }
}