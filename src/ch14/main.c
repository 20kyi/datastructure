#include <stdio.h>

void SelectionSort(int arr[], int n) {

    for (int i=0; i<n-1; i++) { 

        int minIdx = i;

        for (int j=i+1; j<n; j++) {
            if (arr[j] < arr[i]) {
                minIdx = j;
            }
        }

        if (minIdx != i) {
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
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

    SelectionSort(arr, size);

    printf("정렬 후 : ");
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}