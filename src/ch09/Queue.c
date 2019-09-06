#include <assert.h>
#include <stdio.h>

#include "Queue.h"

void QInit(Queue * pQueue){
    LInit(pQueue);
}

void QDestroy(Queue * pQueue){
    LDestroy(pQueue);
}

int QIsEmpty(Queue * pQueue){
    return (LSize(pQueue) == 0);
}

void Enqueue(Queue * pQueue, QData data){
    LInsertTail(pQueue, data);
}

QData QPeek(Queue * pQueue){
    if (QIsEmpty(pQueue)) {
        printf("Queue is Empty! ContainerEmptyException!");
        assert(!QIsEmpty(pQueue));
    }

    return LGet(pQueue, 0);
}

QData Dequeue(Queue * pQueue){
    if (QIsEmpty(pQueue)) {
        printf("Queue is Empty! ContainerEmptyException!");
        assert(!QIsEmpty(pQueue));
    }

    return LRemoveHeader(pQueue);
}