#ifndef MYBANK
#define MYBANK

#define ROWS 2
#define COLUMNS 50
#define FIRST_ACC_ID 901
#define MAX_ACC 50
#define CLOSE_ACC 0
#define OPEN_ACC 1
#define MIN_AMOUNT_TO_DEPOSIT 0


extern double accounts[ROWS][COLUMNS];

void open(double amount);
void balance(int account_number);
void deposit(int account_number, double amount);
void withdraw(int account_number, double amount);
void close(int account_number);
void interest(int interest_rate);
void print();
void exitAcc();

void init();

#endif