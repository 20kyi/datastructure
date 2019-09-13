#include <stdio.h>

void InsertionSort(int arr[], int n) {

    for (int i=1; i<n; i++) { 

        int insertion = arr[i];
        int j = i-1;

        while ( j >= 0 && arr[j] > insertion ) {
            arr[j + 1] = arr[j];
            j -= 1;
        }

        arr[j + 1] = insertion;
    }
}

int main() {

    int arr[] = { 8, 2, 3, 6, 5, 7, 4, 1 };
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("정렬 전 : ");
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    InsertionSort(arr, size);

    printf("정렬 후 : ");
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}