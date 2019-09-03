#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#include "ArrayList.h"

#define INIT_SIZE 8

void LInit(List * pList){
    pList->arr = malloc(sizeof(LData) * INIT_SIZE);
    pList->size = 0;
    pList->capacity = INIT_SIZE;
}

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

LData LGet(List * pList, int index){
    if (index >= pList->size) {
        printf("Index Out of Bound Exception\n");
        assert(index < pList->size);
    }

    LData ret = pList->arr[index];
    return ret;
}

void LSet(List * pList, int index, LData data){
    if (index >= pList->size) {
        printf("Index Out of Bound Exception\n");
        assert(index < pList->size);
    }

    pList->arr[index] = data;
}

int LSize(List * pList){
    return pList->size;
}

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

void LInsertTail(List * pList, LData data){
    if (pList->size == pList->capacity){
        resize(pList);
    }

    pList->arr[pList->size] = data;
    pList->size += 1;
}

LData LRemoveHeader(List * pList){
    LData ret = pList->arr[0];

    for (int i=1; i<pList->size; i++) {
        pList->arr[i-1] = pList->arr[i];
    }

    pList->size -= 1;
    return ret;
}

LData LRemoveIndex(List * pList, int index){
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

LData LRemoveTail(List * pList){
    LData ret = pList->arr[pList->size-1];

    pList->size -= 1;

    return ret;
}