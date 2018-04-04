#include "stdio.h"
#include "string.h"
#include<stdlib.h>
#include<fcntl.h>
#define AMAX 10
#define FMAX 50
#define SMAX 100

typedef enum {A3, FC, SL} ClassType;

struct ticket
{
  char name[30];
  int age;
  int number;
  ClassType Class;
};

int A, F, S; // available seats

void book(FILE *);
void cancel(FILE *);
void chart(FILE *);
void check();
void count(FILE *);

int record = 0;

int main(void) {
  int choice = 0;
  FILE *fp = fopen( "tickets.dat", "rb+" );
  if (fp == NULL ) perror ("Error opening file");
  count(fp);
  check();
  while (choice != 5)
  {
    printf("\n1 Book\t \t 2 Check availability\n");
    printf("3 Cancel\t 4 Prepare Chart\n");
    printf("5 Exit\n Enter choice:");
    scanf("%d", &choice);
    switch(choice)
    {
      case 1: book(fp); break;
      case 2: check(fp); break;
      case 3: cancel(fp); break;
      case 4: chart(fp); break;
      default: ; 
    }
  }
  fclose(fp);
  return 0;
}


void count(FILE *fp)
{
  struct ticket t;
  rewind(fp);
  int record = 0;
  while(!feof(fp))
  {
    record = fread(&t, sizeof(t), 1, fp);
    if(record && strcmp(t.name,""))
    {
      if (t.Class == A3) A++;
      else if (t.Class == FC) F++;
      else if (t.Class == SL) S++;
    } 
  } // end-while
}

void book(FILE *fp)
{
  struct ticket t;
  printf("Enter name: ");
  scanf("%s", t.name);
  printf("Enter mobile number: ");
  scanf("%d", &t.number);
  printf("Enter age: ");
  scanf("%d", &t.age);
  printf("Enter Class (AC - 0, FC - 1, SL - 2): ");
  scanf("%d",&t.Class); 
  if (t.Class == A3) A++;
  else if (t.Class == FC) F++;
  else if (t.Class == SL) S++;
  fwrite(&t, sizeof(struct ticket), 1, fp);
}

void cancel(FILE *fp)
{
  char name[20], number[10];
  int result, record=0;
  struct ticket t, blank = {"", 0, 0, 0};
  printf("Enter name:");
  scanf("%s", name);
  rewind(fp);
  while(!feof(fp))
  {
    result = fread(&t, sizeof(struct ticket), 1, fp);
    if(result != 0 && strcmp(name, t.name) == 0)
    {
      fseek(fp, record*sizeof(struct ticket), SEEK_SET);
      fwrite(&blank, sizeof(struct ticket), 1, fp);
      printf("Cancelled successfully\n");
      if (t.Class == A3) A--;
      else if (t.Class == FC) F--;
      else if (t.Class == SL) S--;
      return;
    }
    record++;
  }
  printf("not found in %d records\n", record);
  
}

void chart(FILE *fp)
{
  struct ticket t;
  int result;
  rewind(fp);
  printf("\n\n \t\t  Chart\n\n");
  printf("Class Type: AC - 0, FC - 1, SL - 2 \n\n");
  printf("%20s %10s %10s %10s\n", "Name", "Number", "Age", "Class");
  printf("********************************************************\n");
  while(!feof(fp))
  {
    result = fread(&t, sizeof(struct ticket), 1, fp);
    if(result != 0 && strlen(t.name) > 0)
      printf("%20s %10d %10d %10d\n",t.name, t.number,
      t.age, t.Class);
  }
  printf("*********************************************************\n");
  
}

void check()
{

    printf("Available A3 = %d, FC = %d, SL = %d\n", AMAX - A, FMAX - F, SMAX - S);
  
}