#ifndef  ARRAY_LIST_H
#define ARRAY_LIST_H

/* ArrayList 헤더입니다. */

// 미리 타입들을 지정한 코드입니다.
typedef int LData;

typedef struct _array_list {
    LData * arr;    // 동적 배열
    int size;       // 순차 리스트 크기
    int capacity;   // 순차 리스트 용량
} ArrayList;

typedef ArrayList List;

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