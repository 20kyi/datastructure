#include "Heap.h"

#include <assert.h>
#include <stdlib.h>

void HInit(Heap * ph, PriorityComp pc) {
    ph->comp = pc;
    ph->capacity = HEAP_INIT_CAPACITY;
    ph->numOfData = 0;
    ph->heapArr = (HData *) malloc( sizeof(HData) * (ph->capacity) );
}

void HDestroy(Heap * ph) {
    free(ph->heapArr);
    ph->comp = NULL;
    ph->numOfData = -1;
    ph->capacity = -1;
}

int HIsEmpty(Heap * ph) {
    return (ph->numOfData == 0);
}

int getParentIdx(int idx) {
    return idx / 2;
}

int getLeftChildIdx(int idx) {
    return idx * 2;
}

int getRightChildIdx(int idx) {
    return getLeftChildIdx(idx) + 1;
}

int getHighPriorityChildIdx(Heap * ph, int idx) {
    int left = getLeftChildIdx(idx);
    int right = getRightChildIdx(idx);

    if ( left > ph->numOfData ) {
        return 0;
    }

    if ( left == ph->numOfData ) {
        return left;
    }

    HData leftData = ph->heapArr[left];
    HData rightData = ph->heapArr[right];

    if ( ph->comp(leftData, rightData) >= 0 ) {
        return left;
    }

    return right;
}

void resize(Heap * ph) {
    ph->capacity *= 2;

    HData * del = ph->heapArr;
    ph->heapArr = (HData *) malloc (sizeof(HData) * ph->capacity);

    for (int i=0; i <= ph->numOfData; i++) {
        ph->heapArr[i] = del[i];
    }

    free(del);
}

void HInsert(Heap * ph, HData data) {
    int idx = ph->numOfData + 1;

    if (idx == ph->capacity) {
        resize(ph);
    }

    while (idx != 1) {

        int parentIdx =getParentIdx(idx);
        HData parentData = ph->heapArr[parentIdx];

        if (ph->comp(data, parentData) <= 0) {
            break;
        }

        ph->heapArr[idx] = parentData;
        idx = parentIdx;
    }

    ph->heapArr[idx] = data;
    ph->numOfData += 1;
}

HData HDelete(Heap * ph) {

    if (HIsEmpty(ph)) {
        assert("Heap Is Empty! ContainerEmptyException");
    }

    int idx = 1;
    HData root= ph->heapArr[idx];
    HData last = ph->heapArr[ph->numOfData];

    while (1) {
        int childIdx = getHighPriorityChildIdx(ph, idx);
        HData childData = ph->heapArr[childIdx];
        
        if ( childIdx == 0 || ph->comp(last, childData) >= 0 ) {
            break;
        }

        ph->heapArr[idx] = childData;
        idx = childIdx;
    }

    ph->heapArr[idx] = last;
    ph->numOfData -= 1;
    return root;
}

HData HGetRoot(Heap * ph) {
    if (HIsEmpty(ph)) {
        assert("Heap Is Empty! ContainerEmptyException");
    }

    int idx = 1;
    HData root= ph->heapArr[idx];
    return root;
}