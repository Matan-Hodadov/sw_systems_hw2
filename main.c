#include <stdio.h>
#include "myBank.h"

void printMenu(){
    printf("\n");
    printf("Please choose a transaction type: \n");
    printf(" O-Open Account \n");
    printf(" B-Balance Inquiry \n");
    printf(" D-Deposit \n");
    printf(" W-Withdrawal \n");
    printf(" C-Close Account \n");
    printf(" I-Interest \n");
    printf(" P-Print \n");
    printf(" E-Exit \n");
}

int main(){
    
    char input = 0;
    char dummy;
    int accountNum;
    double amount;
    int interestRate;

    init();

    while(input != 'E'){
        printMenu();
        do{
            scanf("%c", &input);
            
        }   while(input == '\n');
        
            switch (input)
            {
            case 'O':
                printf("Please enter amount for deposit: ");
                if(scanf("%lf", &amount) != 1){
                    printf("Failed to read the amount \n");
                }
                else{
                    if(amount < MIN_AMOUNT_TO_DEPOSIT){
                        printf("Invalid Amount \n");
                    }
                    else{
                        open(amount);
                    }
                }
                break;
            case 'B':
                printf("Please enter account number: ");
                if(scanf("%d", &accountNum) != 1){
                    printf("Failed to read the account number \n");
                }
                else{
                    balance(accountNum);
                }
                break;
            case 'D':
                printf("Please enter account number: ");
                if(scanf("%d", &accountNum) != 1){
                    printf("Failed to read the account number \n");
                    break;
                }
                if(accountNum < FIRST_ACC_ID || accountNum >= (FIRST_ACC_ID + MAX_ACC)){
                    printf("Invalid account number \n");
                    break;
                }
                int account_number_index = accountNum - FIRST_ACC_ID;
                if(accounts[1][account_number_index] != OPEN_ACC){
                    printf("This account is closed \n");
                    break;
                }
                printf("enter amount to deposit: ");
                if(scanf("%lf", &amount) != 1){
                    printf("Failed to read the amount \n");
                    break;
                }
                deposit(accountNum, amount);
                break;
            case 'W':
                printf("Please enter account number: ");
                if(scanf("%d", &accountNum) != 1){
                    printf("Failed to read the account number \n");
                }
                else{
                    if(accountNum < FIRST_ACC_ID || accountNum >= FIRST_ACC_ID + MAX_ACC){
                        print("Invalid account number");
                    }
                    else{
                        int account_number_index = accountNum - FIRST_ACC_ID;
                        if(accounts[1][account_number_index] == CLOSE_ACC){
                            printf("This account is closed \n");
                        }
                        printf("Please enter the amount to withdraw: ");
                        if(scanf("%lf", &amount) != 1){
                            printf("Failed to read the amount \n");
                        }
                        else{
                            withdraw(accountNum, amount);
                        }
                    }                    
                }
                break;
            case 'C':
                printf("Please enter account number: ");
                if(scanf("%d", &accountNum) != 1){
                    printf("Failed to read the account number \n");
                }
                else{
                    close(accountNum);
                }
                break;

            case 'I':
                printf("Please enter interest rate: ");
                if(scanf("%d", &interestRate) != 1){
                    printf("Failed to read the interest rate \n");
                }
                else{
                    interest(interestRate);
                }
                break;
            case 'P':
                print();
                break;
            case 'E':
                exitAcc();
                break;

            case '\n':
                break;

            default:
                printf("Invalid transaction type \n");
                break;
            }
    }
    return 0;
}
