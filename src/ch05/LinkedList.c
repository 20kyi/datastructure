// 동적 메모리 할당/해제를 위한 임포트
#include<stdlib.h>
//에러 및 출력을 위한 임포트
#include<stdio.h>
#include<assert.h>

#include "LinkedList.h"

/** 
 * 리스트 생성 함수
 * @ param pList List * 리스트의 주소.
 * 해당 리스트를 생성합니다. 동적 배열의 크기는 8입니다.
 */ 
void LInit(List * pList){
    pList->head = (Node *) malloc(sizeof(Node));
    pList->head->data = -123456;

    pList->tail = (Node *) malloc(sizeof(Node));
    pList->tail->data = -123456;

    pList->tail->next = NULL;
    pList->head->next = pList->tail;

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
    newNode->next = pList->head->next;
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

    Node * curr = pList->head->next;

    for (int i=0; i<index-1; i++) {
        curr = curr->next;
    }

    Node * newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = curr->next;
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
    Node * curr = pList->head->next;

    while (curr != pList->tail && curr->next != pList->tail) {
        curr = curr->next;
    }

    Node * newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = pList->tail;

    if (curr == pList->tail) {
        pList->head->next = newNode;
    } else {
        curr->next = newNode;
    }
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
    pList->head->next = del->next;

    LData ret = del->data;
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

    Node * curr = pList->head->next;

    for (int i=0; i<index-1; i++) {
        curr = curr->next;
    }

    Node * del = curr->next;
    curr->next = curr->next->next;

    LData ret = del->data;
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
    
    Node * curr = pList->head->next;
    Node * prev = NULL;

    while (curr != pList->tail && curr->next != pList->tail) {
        prev = curr;
        curr = curr->next;
    }

    Node * del = curr;
    LData ret = del->data;

    if (prev == NULL) {
        pList->head->next = pList->tail;
    } else {
        prev->next = curr->next;
    }
    
    free(del);
    pList->size -= 1;
    return ret;
}