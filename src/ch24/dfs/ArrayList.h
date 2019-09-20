#ifndef  ARRAY_LIST_H
#define ARRAY_LIST_H

/* ArrayList 헤더입니다. */

// 배열 리스트 생성 시 동적 배열의 크기
#define INIT_SIZE 8

// 배열 리스트가 저장할 데이터 int를 LData라는 이름으로 재지정
typedef void * LData;

// ArrayList 구조체 선언
typedef struct _array_list {
    LData * arr;    // 동적 배열
    int size;       // 순차 리스트 크기
    int capacity;   // 순차 리스트 용량
} ArrayList;

// ArrayList를 List로 타입 재지정
typedef ArrayList List;

// 아래 함수 원형들은 List ADT를 따른 것입니다.

void LInit(List * pList);

void LDestroy(List * pList);

LData LGet(List * pList, int index);

void LSet(List * pList, int index, LData data);

int LSize(List * pList);

void LInsertHeader(List * pList, LData data);

void LInsertIndex(List * pList, int index, LData data);

void LInsertTail(List * pList, LData data);

LData LRemoveHeader(List * pList);

LData LRemoveIndex(List * pList, int index);

LData LRemoveTail(List * pList);
    
#endif