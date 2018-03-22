#include <stdio.h>

void insert();
void count();

int main(void) {
  int choice = 0;
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
      case 2: count(); break;
    }
  }
} 

void insert()
{
  unsigned int account;  // account number
  char name[30];         // account name
  double balance;        // account balance

  FILE* cfPtr;  // cfPtr = clients.dat file pointer

  // fopen opens file. Exit program if unable to create file
  if ((cfPtr = fopen("clients.dat", "w")) == NULL) {
    puts("File could not be opened");
  }  // end if
  else {
    int records;
    printf("How many new records ? ");
    scanf("%d", &records);
    puts("Enter the account, name, and balance.");
    // write account, name and balance into file with fprintf
    while (records > 0) {
      printf("Enter record: ");
      scanf("%d%29s%lf", &account, name, &balance);
      fprintf(cfPtr, "%d %s %.2f\n", account, name, balance);
      records--;
    }  // end while

    fclose(cfPtr);  // fclose closes file
  }                 // end else


}

void count()
{

  unsigned int account;  // account number
  char name[30];         // account name
  double balance;        // account balance
  float minBal = 5000.00;
  int count = 0;
  FILE *cfPtr;  // cfPtr = clients.dat file pointer
  
  // fopen opens file; exits program if file cannot be opened
  if ((cfPtr = fopen("clients.dat", "r")) == NULL) {
    puts("File could not be opened");
  }       // end if
  else {  // read account, name and balance from file
    printf("%-10s%-13s%s\n", "Account", "Name", "Balance");
    fscanf(cfPtr, "%d%29s%lf", &account, name, &balance);

    // while not end of file
    while (!feof(cfPtr)) {
      if (balance < minBal)
      {
        printf("%-10d%-13s%7.2f\n", account, name, balance);
        count++;
      }
      fscanf(cfPtr, "%d%29s%lf", &account, name, &balance);
    }  // end while
    fclose(cfPtr);  // fclose closes the file
    printf("The number of account holders whose balance is less than the minimum balance: ");
    printf("%d\n", count);
  }                 // end else

}