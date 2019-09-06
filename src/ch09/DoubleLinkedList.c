// 동적 메모리 할당/해제를 위한 임포트
#include<stdlib.h>
//에러 및 출력을 위한 임포트
#include<stdio.h>
#include<assert.h>

#include "DoubleLinkedList.h"

/** 
 * 리스트 생성 함수
 * @ param pList List * 리스트의 주소.
 * 해당 리스트를 생성합니다. 
 */ 
void LInit(List * pList){
    // head 더미 노드 생성
    Node * head = (Node *) malloc(sizeof(Node));
    head->data = -123456;
    head->prev = NULL;
    head->next = NULL;
    // tail 더미 노드 생성
    Node * tail = (Node *) malloc(sizeof(Node));
    tail->data = -123456;
    tail->prev = NULL;
    tail->next = NULL;
    // head <-> tail 연결
    head->next = tail;
    tail->prev = head;
    // 연결 리스트의 해당 노드들 연결
    pList->head = head;
    pList->tail = tail;

    pList->size = 0;
}

/**
 * 리스트 제거 함수
 * @ param pList List * 리스트의 주소.
 * 해당 리스트를 제거합니다. 
 */
void LDestroy(List * pList){

    while (pList->size > 0) {
        LRemoveHeader(pList);
    }

    if (pList->head != NULL) {
        free(pList->head);
        pList->head = NULL;
    }
    
    if (pList->tail != NULL) {
        free(pList->tail);
        pList->tail = NULL;
    }
    
    pList->size = 0;
}

/**
 * 리스트 인덱스 요소 얻기
 * @ param pList List * 리스트의 주소. 
 * @ param index int    접근할 인덱스
 * 
 * index < size, 함수 실행, 해당 인덱스 요소를 반환합니다.
 * return LData
 */
LData LGet(List * pList, int index){
    if (index >= pList->size) {
        printf("Index Out of Bound Exception\n");
        assert(index < pList->size);
    }

    Node * curr = pList->head->next;

    for (int i=0; i<index; i++) {
        curr = curr->next;
    }

    return curr->data;
}

/**
 * 리스트 인덱스 요소 수정
 * @ param pList List * 리스트의 주소. 
 * @ param index int    접근할 인덱스
 * @ param data LData   수정할 데이터
 * 
 * index < size, 함수 실행, 해당 인덱스 요소를 데이터로 수정합니다.
 */
void LSet(List * pList, int index, LData data){
    if (index >= pList->size) {
        printf("Index Out of Bound Exception\n");
        assert(index < pList->size);
    }

    Node * curr = pList->head->next;

    for (int i=0; i<index; i++) {
        curr = curr->next;
    }

    curr->data = data;
}

/**
 * 리스트 크기 
 * @ param pList List * 리스트의 주소. 
 * 
 * 해당 리스트의 크기를 반환합니다.
 * return int
 */
int LSize(List * pList){
    return pList->size;
}


/**
 * 리스트 머리 삽입 함수
 * @ param pList List * 리스트의 주소.
 * @ param data LData   삽입할 데이터 
 * 
 * 현재 리스트의 첫 부분에 데이터를 넣습니다.
 */
void LInsertHeader(List * pList, LData data){
    Node * newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = pList->head;
    newNode->next = pList->head->next;

    pList->head->next->prev = newNode;
    pList->head->next = newNode;

    pList->size += 1;
}

/**
 * 리스트 인덱스 삽입 함수
 * @ param pList List * 리스트의 주소.
 * @ param index int    삽입할 인덱스
 * @ param data LData   삽입할 데이터 
 * 
 * 현재 리스트의 인덱스 위치에 데이터를 넣습니다.
 */
void LInsertIndex(List * pList, int index, LData data){
    if (index >= pList->size) {
        printf("Index Out of Bound Exception\n");
        assert(index < pList->size);
    }

    if (index == 0) {
        return LInsertHeader(pList, data);
    }

    if (index == pList->size - 1) {
        return LInsertTail(pList, data);
    }

    Node * curr = pList->head->next;

    for (int i=0; i<index-1; i++) {
        curr = curr->next;
    }

    Node * newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = curr;
    newNode->next = curr->next;

    curr->next->prev = newNode;
    curr->next = newNode;

    pList->size += 1;
}

/**
 * 리스트 꼬리 삽입 함수
 * @ param pList List * 리스트의 주소.
 * @ param data LData   삽입할 데이터 
 * 
 * 현재 리스트의 마지막 부분에 데이터를 넣습니다.
 */
void LInsertTail(List * pList, LData data){
    
    Node * newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = pList->tail->prev;
    newNode->next = pList->tail;

    pList->tail->prev->next = newNode;
    pList->tail->prev = newNode;
    
    pList->size += 1;
}

/**
 * 리스트 머리 삭제 함수
 * @ param pList List * 리스트의 주소.
 * 
 * 현재 리스트의 첫 부분에 데이터를 삭제합니다.
 * 
 * return LData 머리 부분에 데이터
 */
LData LRemoveHeader(List * pList){
    if (pList->size <= 0) {
        printf("List Empty Exception\n");
        assert(pList->size > 0);
    }

    Node * del = pList->head->next;
    LData ret = del->data;
    // 삭제 노드 전 후로, 노드 연결
    del->prev->next = del->next;
    del->next->prev = del->prev;
    del->prev = NULL;
    del->next = NULL;
    // 노드 삭제
    free(del);

    pList->size -= 1;
    return ret;
}

/**
 * 리스트 인덱스 삭제 함수
 * @ param pList List * 리스트의 주소.
 * @ param index int    삭제할 인덱스
 * 
 * 현재 리스트의 인덱스 위치에 데이터를 삭제합니다.
 * 
 * return LData 인덱스 부분에 데이터
 */
LData LRemoveIndex(List * pList, int index){
    if (pList->size <= 0) {
        printf("List Empty Exception\n");
        assert(pList->size > 0);
    }

    if (index >= pList->size) {
        printf("Index Out of Bound Exception\n");
        assert(index < pList->size);
    }

    if (index == 0) {
        return LRemoveHeader(pList);
    }

    if (index == pList->size - 1) {
        return LRemoveTail(pList);
    }

    Node * curr = pList->head->next;

    for (int i=0; i<index-1; i++) {
        curr = curr->next;
    }

    Node * del = curr->next;
    LData ret = del->data;

    del->prev->next = del->next;
    del->next->prev = del->prev;
    del->prev = NULL;
    del->next = NULL;

    free(del);

    pList->size -= 1;
    return ret;
}

/**
 * 리스트 꼬리 삭제 함수
 * @ param pList List * 리스트의 주소.
 * 
 * 현재 리스트의 마지막 부분에 데이터를 삭제합니다.
 * 
 * return LData 마지막 부분에 데이터
 */
LData LRemoveTail(List * pList){
    if (pList->size <= 0) {
        printf("List Empty Exception\n");
        assert(pList->size > 0);
    }
    
    Node * del = pList->tail->prev;
    LData ret = del->data;

    del->prev->next = del->next;
    del->next->prev = del->prev;
    del->prev = NULL;
    del->next = NULL;

    free(del);

    pList->size -= 1;
    return ret;
}