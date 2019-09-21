#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

#include "Heap.h"

typedef HData PQData;
typedef Heap PriorityQueue;

void QInit(PriorityQueue * pq, PriorityComp pc);
void QDestory(PriorityQueue * pq);

int QIsEmpty(PriorityQueue * pq);
void Enqueue(PriorityQueue * pq, PQData data);
HData Dequeue(PriorityQueue * pq);
HData QPeek(PriorityQueue * pq);

#endif // !__PRIORITY_QUEUE_H__