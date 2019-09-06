#include <assert.h>
#include <stdio.h>

#include "Queue.h"

/**
 * 큐 생성 함수
 * 
 * @param pQueue Queue * 큐의 주소입니다.
 * 
 * 큐를 생성합니다.
 */ 
void QInit(Queue * pQueue){
    LInit(pQueue);
}

/**
 * 큐 파괴 함수
 * 
 * @param pQueue Queue * 큐의 주소입니다.
 * 
 * 큐를 파괴합니다.
 */ 
void QDestroy(Queue * pQueue){
    LDestroy(pQueue);
}

/**
 * 빈 큐인지 검사 함수
 * 
 * @param pQueue Queue * 큐의 주소입니다.
 * 
 * return int (1, 0)
 * 
 * 큐가 비어있는지 검사합니다. 비어있으면 1(true), 아니라면 0(false)를 반환합니다.
 */ 
int QIsEmpty(Queue * pQueue){
    return (LSize(pQueue) == 0);
}

/**
 * 데이터 삽입 함수
 * 
 * @param pQueue Queue * 큐의 주소입니다.
 * @param data QData     큐에 삽입될 데이터입니다.
 * 
 * 큐에 데이터를 삽입합니다. 만약 "1, 2, 3, 4, 5" 순서대로 데이터의 삽입이 이루어지면, 큐 역시 "1, 2, 3, 4, 5"를 담고 있어야 합니다.
 */ 
void Enqueue(Queue * pQueue, QData data){
    LInsertTail(pQueue, data);
}

/**
 * 큐의 가장 앞에 데이터 반환 함수
 * 
 * @param pQueue Queue * 큐의 주소입니다.
 * 
 * return QData 큐의 가장 앞의 데이터
 * 
 * 큐가 비어 있을 때, 이 함수가 호출되면 안됩니다. 큐의 가장 앞의 데이터를 반환합니다.
 */ 
QData QPeek(Queue * pQueue){
    if (QIsEmpty(pQueue)) {
        printf("Queue is Empty! ContainerEmptyException!");
        assert(!QIsEmpty(pQueue));
    }

    return LGet(pQueue, 0);
}

/**
 * 큐의 가장 앞에 데이터 삭제 함수
 * 
 * @param pQueue Queue * 큐의 주소입니다.
 * 
 * return QData 큐에서 삭제된 가장 앞의 데이터
 * 
 * 큐가 비어 있을 때, 이 함수가 호출되면 안됩니다. 큐의 가장 앞의 데이터를 큐에서 삭제한 후, 반환합니다.
 */ 
QData Dequeue(Queue * pQueue){
    if (QIsEmpty(pQueue)) {
        printf("Queue is Empty! ContainerEmptyException!");
        assert(!QIsEmpty(pQueue));
    }

    return LRemoveHeader(pQueue);
}