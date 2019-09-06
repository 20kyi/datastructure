#include<stdio.h>
#include<assert.h>

#include "Stack.h"

int main() {
    Stack stack;

    SInit(&stack);

    // 출력 empty: 1
    printf("Before insert data, isEmpty: %d\n", SIsEmpty(&stack)); 

    for (int i=0; i<5; i++){
        SPush(&stack, i+1);
    }

    // 출력 empty: 0
    printf("After push data, isEmpty: %d\n", SIsEmpty(&stack)); 

    // 출력 TOP: 5
    printf("TOP: %d\n", SPeek(&stack));


    // 출력 5 4 3 2 1
    while (!SIsEmpty(&stack)) {
        printf("%d ", SPop(&stack));
    }
    printf("\n");

    printf("After pop data, isEmpty: %d\n", SIsEmpty(&stack)); 

    SDestroy(&stack);
    return 0;
}