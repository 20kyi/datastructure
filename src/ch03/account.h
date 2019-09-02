#ifndef  ACCOUNT_H
#define ACCOUNT_H

typedef struct _account {
    int balance;
} Account;

void Deposit(Account * account, int money);

int Withdraw(Account * account, int money);

int GetBalance(Account * account);

#endif