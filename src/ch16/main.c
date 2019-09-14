#include <stdio.h>
#include <stdlib.h>

#include "Heap.h"

int compare(void * pData1, void * pData2) {
    int d1 = *((int *) pData1);
    int d2 = *((int *) pData2);
    return d2 - d1;
}

void insert(Heap * pHeap, int * element) {
    HInsert(pHeap, element);
}

int delete(Heap * pHeap) {
    int data = *((int *)HDelete(pHeap));
    return data;
}

void HeapSort(int arr[], int n) {

    int * sortedArr = (int *) malloc(sizeof(int) * n);
    Heap heap;
    HInit(&heap, compare);

    for (int i=0; i<n; i++){
        insert(&heap, arr + i);
    }

    for (int i=0; i<n; i++) {
        sortedArr[i] = delete(&heap);
    }

    for (int i=0; i<n; i++) {
        arr[i] = sortedArr[i];
    }

    HDestroy(&heap);
    free(sortedArr);
}

int main() {

    int arr[] = { 8, 2, 3, 6, 5, 7, 4, 1 };
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("정렬 전 : ");
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    HeapSort(arr, size);

    printf("정렬 후 : ");
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}