#include<stdio.h>
#include<assert.h>

#include "Queue.h"

int main() {
    Queue queue;

    QInit(&queue);

    // 출력 empty: 1(true)
    printf("Before insert data, isEmpty: %d\n", QIsEmpty(&queue)); 

    for (int i=0; i<5; i++){
        Enqueue(&queue, i+1);
    }

    // 출력 empty: 0(false)
    printf("After push data, isEmpty: %d\n", QIsEmpty(&queue)); 

    // 출력 Front: 1
    printf("Front: %d\n", QPeek(&queue));

    // 출력 Front: 1
    printf("Front: %d\n", QPeek(&queue));

    // 출력 1 2 3 4 5
    while (!QIsEmpty(&queue)) {
        printf("%d ", Dequeue(&queue));
    }
    printf("\n");

    // 출력 empty: 1(true)
    printf("After pop data, isEmpty: %d\n", QIsEmpty(&queue)); 

    QDestroy(&queue);
    return 0;
}