#ifndef  QUEUE_H
#define QUEUE_H

#include "DoubleLinkedList.h"

typedef LData QData;
typedef DoubleLinkedList Queue;

void QInit(Queue * pQueue);
void QDestroy(Queue * pQueue);
int QIsEmpty(Queue * pQueue);
void Enqueue(Queue * pQueue, QData data);
QData QPeek(Queue * pQueue);
QData Dequeue(Queue * pQueue);

#endif