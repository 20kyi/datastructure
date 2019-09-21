#ifndef __HEAP_H__
#define __HEAP_H__

#define HEAP_INIT_CAPACITY 8
// 힙에 저장될 데이터 타입
typedef void * HData;

// 힙의 데이터를 비교할 함수
typedef int PriorityComp(HData d1, HData d2);

typedef struct _heap {
    PriorityComp * comp;
    HData * heapArr;
    int numOfData;
    int capacity;
} Heap;

void HInit(Heap * ph, PriorityComp pc);
void HDestroy(Heap * ph);

int HIsEmpty(Heap * ph);
void HInsert(Heap * ph, HData data);
HData HDelete(Heap * ph);
HData HGetRoot(Heap * ph);

#endif // !__HEAP_H__