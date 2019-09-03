#ifndef  LINKED_LIST_H
#define LINKED_LIST_H

/* LinkedList 헤더입니다. */

// 연결 리스트가 저장할 데이터 int를 LData라는 이름으로 재지정
typedef int LData;

typedef struct _node {
    LData data;          // 노드의 데이터
    struct _node * next; // 자기 참조 포인터. 다음 노드를 가리킵니다.
} Node;

// LinkedList 구조체 선언
typedef struct _linked_list {
    Node * head;    // 연결 리스트의 헤더
    Node * tail;    // 연결 리스트의 꼬리
    int size;       // 연결 리스트의 크기
} LinkedList;

// LinkedList List로 타입 재지정
typedef LinkedList List;

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