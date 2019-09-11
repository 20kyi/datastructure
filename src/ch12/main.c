#include "PriorityQueue.h"

#include <stdio.h>

int DataPrioirtyComp(void * pc1, void * pc2) {
    char c1 = *( (char *) pc1 );
    char c2 = *( (char *) pc2);
    return c2 - c1;
}

void enqueue(PriorityQueue * pq, char * data) {
    Enqueue(pq, data);
}

char dequeue(PriorityQueue * pq) {
    char ret = *( (char *) Dequeue(pq) );
    return ret;
}

int main () {
    PriorityQueue pq;
    QInit(&pq, DataPrioirtyComp);

    char input[] = "ABCDEFHI";

    for (int i=0; i<8; i++) {
        enqueue(&pq, input + i);
    }

    printf("%c\n", dequeue(&pq));

    for (int i=0; i<8; i++) {
        enqueue(&pq, input + i);
    }

    printf("%c\n", dequeue(&pq));

    while (!QIsEmpty(&pq)){
        printf("%c\n", dequeue(&pq));
    }

    QDestory(&pq);
    return 0;
}