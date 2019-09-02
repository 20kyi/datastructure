#include "account.h"

void Deposit(Account * account, int money){
    account->balance += money;
}

int Withdraw(Account * account, int money) {
    if (account->balance < money) 
        return -1;

    account->balance -= money;
    return money;
}

int GetBalance(Account * account) {
    return account->balance;
}