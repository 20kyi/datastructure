#include <stdio.h>

void BubbleSort(int arr[], int n) {
    for (int i=0; i<n-1; i++) { 

        for (int j=0; j< (n-1-i); j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
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

    BubbleSort(arr, size);

    printf("정렬 후 : ");
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}