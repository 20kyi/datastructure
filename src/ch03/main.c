#include <stdio.h>

#include "account.h"

int main() {
    Account account = { 1000 };

    printf("balance: %d\n", GetBalance(&account));

    int saved = 2000;
    Deposit(&account, saved);
    printf("balance: %d\n", GetBalance(&account));

    for (int i=0; i<4; i++){
        int withDraw = Withdraw(&account, 1000);

        if (withDraw == -1) {
            printf("출금액이 현재 잔고보다 많습니다. balance: %d\n", GetBalance(&account));
        } else {
            printf("withDraw: %d balance: %d\n", withDraw, GetBalance(&account));
        }
    }
    
    return 0;
}

