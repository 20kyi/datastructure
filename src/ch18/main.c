#include <stdio.h>
#include <stdlib.h>

void Swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int Partition(int arr[], int left, int right) {
    int pivot = arr[left];
    int low = left + 1;
    int high = right;

    while (low <= high) {
        while (pivot > arr[low]){
            low += 1;
        }

        while(pivot < arr[high]) {
            high -= 1;
        }

        if (low <= high) {
            Swap(arr, low, high);
        }
    }

    Swap(arr, left, high);
    return high;
}

void QuickSort(int arr[], int start, int end) {

    if (start > end) {
        return;
    }
    
    int pivot = Partition(arr, start, end);
    QuickSort(arr, start, pivot-1);
    QuickSort(arr, pivot + 1, end);
}

int main() {

    int arr[] = { 8, 2, 3, 6, 5, 7, 4, 1 };
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("정렬 전 : ");
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    QuickSort(arr, 0, size-1);

    printf("정렬 후 : ");
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}