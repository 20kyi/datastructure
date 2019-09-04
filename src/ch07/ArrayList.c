// 동적 메모리 할당/해제를 위한 임포트
#include<stdlib.h>
//에러 및 출력을 위한 임포트
#include<stdio.h>
#include<assert.h>

#include "ArrayList.h"

/** 
 * 리스트 생성 함수
 * @ param pList List * 리스트의 주소.
 * 해당 리스트를 생성합니다. 동적 배열의 크기는 8입니다.
 */ 
void LInit(List * pList){
    pList->arr = malloc(sizeof(LData) * INIT_SIZE);
    pList->size = 0;
    pList->capacity = INIT_SIZE;
}

/**
 * 리스트 제거 함수
 * @ param pList List * 리스트의 주소.
 * 해당 리스트를 제거합니다. `arr`의 경우 동적 배열이기 때문에 주소가 들어 있다면, 해제해야 합니다.
 */
void LDestroy(List * pList){
    if (pList == NULL) {
        return;
    }

    if (pList->arr != NULL) {
        free(pList->arr);
        pList->arr = NULL;
    }

    pList->size = 0;
    pList->capacity = 0;
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

    LData ret = pList->arr[index];
    return ret;
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

    pList->arr[index] = data;
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
 * 리스트 리사이즈 함수
 * @ param pList List * 리스트의 주소. 
 * 
 * 현재 가진 배열보다, 2배 큰 동적 배열을 새로이 할당 받습니다.
 */
void resize(List * pList) {
    pList->capacity *= 2;

    LData * del = pList->arr;
    LData * tmp = malloc(sizeof(LData) * (pList->capacity));

    for (int i=0; i<pList->size; i++) {
        tmp[i] = pList->arr[i];
    }

    pList->arr = tmp;
    free(del);
}

/**
 * 리스트 머리 삽입 함수
 * @ param pList List * 리스트의 주소.
 * @ param data LData   삽입할 데이터 
 * 
 * 현재 리스트의 첫 부분에 데이터를 넣습니다.
 */
void LInsertHeader(List * pList, LData data){
    if (pList->size == pList->capacity){
        resize(pList);
    }

    for (int i=pList->size-1; i>=0; i--) {
        pList->arr[i+1] = pList->arr[i];
    }

    pList->arr[0] = data;
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

    if (pList->size == pList->capacity){
        resize(pList);
    }

    for (int i=pList->size-1; i>=index; i--) {
        pList->arr[i+1] = pList->arr[i];
    }

    pList->arr[index] = data;
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
    if (pList->size == pList->capacity){
        resize(pList);
    }

    pList->arr[pList->size] = data;
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

    LData ret = pList->arr[0];

    for (int i=1; i<pList->size; i++) {
        pList->arr[i-1] = pList->arr[i];
    }

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

    LData ret = pList->arr[index];

    for (int i=index + 1; i<pList->size; i++) {
        pList->arr[i-1] = pList->arr[i];
    }

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
    
    LData ret = pList->arr[pList->size-1];

    pList->size -= 1;

    return ret;
}