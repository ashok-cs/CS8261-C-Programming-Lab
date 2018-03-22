#include <stdio.h>

struct acc{
  unsigned int number;  // account number
  char name[30];         // account name
  double balance;        // account balance  
};

void insert();
void count(float);

int main(void) {
  int choice = 0;
  float minBal = 5000.00;
  while (choice != 3)
  {
    printf("\n1 insert records\n");
    printf("2 Count min balance holders\n");
    printf("3 Exit\n");
    printf("Enter choice:");
    scanf("%d", &choice);
    switch(choice)
    {
      case 1: insert(); break;
      case 2: count(minBal); break;
    }
  }

} 

void insert()
{
    FILE *fp; 
    struct acc account;
    int records;
    fp = fopen("clients.txt", "w");
    if (fp == NULL) perror ("Error opening file");
    printf("How many new records ? ");
    scanf("%d", &records);
    puts("\nEnter the account number, name, and balance.\n");
    printf("******************************************\n");
    while (records > 0) {
      printf("\n Enter record  :");
      scanf("%d%29s%lf", &account.number, account.name, &account.balance);
      fprintf(fp, "%d %s %.2f\n", account.number, account.name, account.balance);
      records--;
    }  // end while
    fclose(fp);
}

void count(float minBal)
{
  FILE *fp; 
  struct acc account;
  int count = 0;
  fp = fopen("clients.txt", "r");
  if (fp == NULL) perror ("Error opening file");
  printf("\nThe account holders whose balance is less than the minimum balance\n");
  printf("AccNumber    AccountHolderName   Balance\n");
  printf("******************************************\n");
  fscanf(fp, "%d%29s%lf", &account.number, account.name, &account.balance);
  while (!feof(fp)) {
    // "%d:%[^:]:%lf\n"
    if (account.balance < minBal) 
    {
        printf("%-10d%-13s%7.2f\n", account.number, account.name, account.balance);
        count++;
    }
    fscanf(fp, "%d%29s%lf", &account.number, account.name, &account.balance);
  }  // end while
  printf("\nNumber of accounts :");
  printf("%d \n", count);
  fclose(fp);
}