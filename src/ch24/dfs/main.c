#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Stack.h"

#define NUMBER_OF_VERTEX 6

void push(Stack * pStack, int data) {
    int * p = (int *) malloc(sizeof(int));
    *p = data;
    SPush(pStack, p);
}

int pop(Stack * pStack) {
    int data = *((int *) SPop(pStack));
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

void DFSWithStack(int (*graph)[NUMBER_OF_VERTEX], int * visitInfo, int start) {
    Stack stack;
    SInit(&stack);

    push(&stack, start);
    
    while (!SIsEmpty(&stack) && !isAllVisit(visitInfo)) {
        int visit = pop(&stack);

        if (visitInfo[visit]) {
            continue;
        }

        visitInfo[visit] = 1;
        printf("%d ", visit);
        
        for (int to=NUMBER_OF_VERTEX-1; to>=0; to--) {
            if (graph[visit][to] && !visitInfo[to]) {
                push(&stack, to);
            }
        }
    }

    printf("\n");
    SDestroy(&stack);
}

void DFSWithRecursion(int (*graph)[NUMBER_OF_VERTEX], int * visitInfo, int visit) {
    if (visitInfo[visit] || isAllVisit(visitInfo)) {
        printf("\n");
        return;
    }

    visitInfo[visit] = 1;
    printf("%d " , visit);

    for (int to=0; to<NUMBER_OF_VERTEX; to++) {
        if (graph[visit][to] && !visitInfo[to]) {
            DFSWithRecursion(graph, visitInfo, to);
        }
    }
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
    DFSWithStack(graph, visitInfo, 0);

    memset(visitInfo, 0, sizeof(int) * NUMBER_OF_VERTEX);
    DFSWithRecursion(graph, visitInfo, 0);
    return 0;
}