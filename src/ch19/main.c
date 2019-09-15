#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

#define BUCKET_NUM 10

void enqueue(Queue * pq, int * pData) {
    Enqueue(pq, pData);
}

int dequeue(Queue * pq) {
    int * pData = (int *) Dequeue(pq);
    return *pData;
}

void RadixSort(int arr[], int size, int limit) {
    int factor = 1;
    int * sortedArr = (int *) malloc( sizeof(int) * size );
    Queue buckets[BUCKET_NUM];

    for (int bucket_idx=0; bucket_idx<BUCKET_NUM; bucket_idx++) {
        QInit( &buckets[bucket_idx] );
    }

    for (int pos=0; pos < limit; pos++) {

        for (int i=0; i<size; i++) {
            int radix = (arr[i] / factor) % 10;
            enqueue(&buckets[radix], arr + i);
        }

        for(int bucket_idx=0, i=0; bucket_idx<BUCKET_NUM; bucket_idx++) {
            while (!QIsEmpty(&buckets[bucket_idx])){
                sortedArr[i] = dequeue(&buckets[bucket_idx]);
                i += 1;
            }
        }

        for (int i=0; i<size; i++) {
            arr[i] = sortedArr[i];
        }

        factor *= 10;
    }

    for (int bucket_idx=0; bucket_idx<BUCKET_NUM; bucket_idx++) {
        QDestroy( &buckets[bucket_idx] );
    }
    free(sortedArr);
}

int main() {
    int arr[] = {13, 212, 14, 7141, 10987, 6, 15};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("정렬 전 : ");
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    RadixSort(arr, size, 5);

    printf("정렬 후 : ");
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}