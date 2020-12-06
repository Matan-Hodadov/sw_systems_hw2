#include "myBank.h"
#include <stdio.h>

// int first_available_acc = 0;

double accounts[ROWS][COLUMNS];

void init(){
    // accounts[ROWS][COLUMNS] = {0};
    for(int i = 0; i<ROWS ; i++){
        for(int j = 0; j<COLUMNS ; j++){
            accounts[i][j] = 0;
        }   
    }
}

int findFirstAvailableAcc(){
    for(int i=0; i<MAX_ACC; i++){
        if(accounts[1][i] == CLOSE_ACC){
            return i;
        }
    }
    return MAX_ACC;
}

void open(double amount){
    int first_available_acc = findFirstAvailableAcc();
    if(first_available_acc < MAX_ACC){        
        accounts[0][first_available_acc] = amount;
        accounts[1][first_available_acc] = OPEN_ACC;
        printf("New account number is: %d \n", first_available_acc + FIRST_ACC_ID);
    }
    else{
        printf("There are no accounts left to open \n");
    }
}

void balance(int account_number){
    if(account_number >= FIRST_ACC_ID && account_number < FIRST_ACC_ID + MAX_ACC){
        int account_number_index = account_number - FIRST_ACC_ID;
        if(accounts[1][account_number_index] == CLOSE_ACC){
            printf("This account is closed \n");
        }
        else{
            printf("The balance of account number %d is: %.2lf \n", account_number, accounts[0][account_number_index]);
        }
    }
    else{
        printf("This account is not existing \n");
    }
}

void deposit(int account_number, double amount){
    if(account_number >= FIRST_ACC_ID && account_number < FIRST_ACC_ID + MAX_ACC){
        if(amount < MIN_AMOUNT_TO_DEPOSIT){
            printf("Cannot deposit a negative amount \n");
        }
        else{
            int account_number_index = account_number - FIRST_ACC_ID;
            accounts[0][account_number_index] = accounts[0][account_number_index] + amount;
            printf("The new balance is: %.2lf \n", accounts[0][account_number_index]);
        }
    }
    else{
        printf("This account is not existing \n");
    }
}

void withdraw(int account_number, double amount){
    int account_number_index = account_number-FIRST_ACC_ID;
    if(amount > accounts[0][account_number_index]){
        printf("Cannot withdraw more than the balance \n");
    }
    else{
        accounts[0][account_number_index] = accounts[0][account_number_index] - amount;
        printf("The new balance is: %.2lf \n", accounts[0][account_number_index]);
    }        
}
    


void close(int account_number){
    if(account_number >= FIRST_ACC_ID && account_number < FIRST_ACC_ID + MAX_ACC){
        int account_number_index = account_number-FIRST_ACC_ID;
        if(accounts[1][account_number_index] == CLOSE_ACC){
            printf("This account is already closed \n");
        }
        else{
            accounts[1][account_number_index] = CLOSE_ACC;
            printf("Closed account number %d \n", account_number);
        }
    }
    else{
        printf("This account is not existing \n");
    }
}

void interest(int interest_rate){
    if(interest_rate >= 0 && interest_rate <= 100){
        if(interest_rate == 0 ){
            return;
        }
        else{
            for(int i = 0; i < MAX_ACC; i++){
                if(accounts[1][i] == OPEN_ACC){
                    double amountOfInterest = ((double)interest_rate*accounts[0][i])/100.0;
                    accounts[0][i] = accounts[0][i] + amountOfInterest; 
                    // accounts[0][i] += amountOfInterest;
               }
            }
        }
    }
    else{
        printf("Invalid interest rate \n");
    }
}

void print(){
    for(int i = 0; i< MAX_ACC; i++){
        if(accounts[1][i] == OPEN_ACC){
            printf("The balance of account number %d is: %.2lf \n", i+FIRST_ACC_ID, accounts[0][i]);
        }
    }
}

void exitAcc(){
    for(int i = 0; i< MAX_ACC; i++){
        if(accounts[1][i] == OPEN_ACC){
            accounts[1][i] = CLOSE_ACC;
        }
    }
}








