#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Queue.h"

#define NUMBER_OF_VERTEX 6

void enqueue(Queue * pQueue, int data) {
    int * p = (int *) malloc(sizeof(int));
    *p = data;
    Enqueue(pQueue, p);
}

int dequeue(Queue * pQueue) {
    int data = *((int *) Dequeue(pQueue));
    return data;
}

int isAllVisit(int * visitInfo) {
    for (int i=0; i<NUMBER_OF_VERTEX; i++) {
        if (visitInfo[i] != 1) {
            return 0;
        }
    }

    return 1;
}

void BFS(int (*graph)[NUMBER_OF_VERTEX], int * visitInfo, int start) {
    Queue queue;
    QInit(&queue);

    enqueue(&queue, start);
    
    while (!QIsEmpty(&queue) && !isAllVisit(visitInfo)) {
        int visit = dequeue(&queue);

        if (visitInfo[visit]) {
            continue;
        }

        visitInfo[visit] = 1;
        printf("%d ", visit);
        
        for (int to=0; to < NUMBER_OF_VERTEX; to++) {
            if (graph[visit][to] && !visitInfo[to]) {
                enqueue(&queue, to);
            }
        }
    }

    printf("\n");
    QDestroy(&queue);
}


int main () {
    
    int graph[NUMBER_OF_VERTEX][NUMBER_OF_VERTEX] = {
        { 0, 1, 0, 0, 0, 1 },
        { 1, 0, 1, 0, 0, 0 },
        { 0, 1, 0, 1, 1, 1 },
        { 0, 0, 1, 0, 1, 0 },
        { 0, 0, 1, 1, 0, 0 },
        { 1, 0, 1, 0, 0, 0 }
    };

    int visitInfo[NUMBER_OF_VERTEX] = { 0, 0, 0, 0, 0, 0 };    
    BFS(graph, visitInfo, 0);
    return 0;
}