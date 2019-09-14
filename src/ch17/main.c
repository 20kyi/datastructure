#include <stdio.h>
#include <stdlib.h>

void Merge(int arr[], int start, int mid, int end) {
    int size = end - start + 1;
    int * sortedArr = (int *) malloc( sizeof(int) * size );
    int lStart = start, rStart = mid + 1;
    int idx = 0;

    while (lStart <= mid && rStart <= end) {

        if (arr[lStart] < arr[rStart]) {
            sortedArr[idx] = arr[lStart];
            lStart += 1;
        } else {
            sortedArr[idx] = arr[rStart];
            rStart += 1;
        }

        idx += 1;
    }

    while (lStart <= mid){
        sortedArr[idx] = arr[lStart];
        lStart += 1;
        idx += 1;
    }
    
    while (rStart <= end){
        sortedArr[idx] = arr[rStart];
        rStart += 1;
        idx += 1;
    }

    for (int i=0; i<size; i++) {
        arr[start + i] = sortedArr[i];
    }

    free(sortedArr);
}

void MergeSort(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }

    int mid = (start + end) / 2;
    
    MergeSort(arr, start, mid);
    MergeSort(arr, mid + 1, end);

    Merge(arr, start, mid, end);
}

int main() {

    int arr[] = { 8, 2, 3, 6, 5, 7, 4, 1 };
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("정렬 전 : ");
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    MergeSort(arr, 0, size-1);

    printf("정렬 후 : ");
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}