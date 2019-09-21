#include "PriorityQueue.h"

#include <assert.h>

void QInit(PriorityQueue * pq, PriorityComp pc) {
    HInit(pq, pc);
}

void QDestory(PriorityQueue * pq) {
    HDestroy(pq);
}

int QIsEmpty(PriorityQueue * pq) {
    return HIsEmpty(pq);
}

void Enqueue(PriorityQueue * pq, PQData data) {
    HInsert(pq, data);
}

HData Dequeue(PriorityQueue * pq) {
    if (QIsEmpty(pq)) {
        assert("Queue is Empty! ContainerEmptyException");
    }

    return HDelete(pq);
}

HData QPeek(PriorityQueue * pq) {
    if (QIsEmpty(pq)) {
        assert("Queue is Empty! ContainerEmptyException");
    }

    return HGetRoot(pq);
}