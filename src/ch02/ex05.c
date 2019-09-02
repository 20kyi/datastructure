/* 이진 탐색을 재귀 호출 방식으로 바꾼 예제입니다. */
#include<stdio.h>

/**
 * 이진 탐색을 위한 함수입니다.
 * 
 * @ arr int [] 순차 탐색을 하는 공간, 배열입니다.
 * @ first int  검색 공간의 첫 번째 위치입니다.
 * @ last int   검색 공간의 마지막 위치입니다.
 * @ target int 찾는 숫자입니다.
 * 
 * return 찾았으면, 배열에서 해당 숫자가 위치하는 인덱스, 없으면 -1
 */
int BinarySearch(int arr[], int first, int last, int target){
    if (first > last)
        return -1;

    int mid = (first + last) / 2;
    int search = arr[mid];

    if (search == target){
        return mid;
    } else if (search > target) {
        return BinarySearch(arr, first, mid-1, target);
    } else {
        return BinarySearch(arr, mid + 1, last, target);
    }   
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int start = 0;
    int last = sizeof(arr) / sizeof(int) - 1;
    int target = 4;

    int result = BinarySearch(arr, start, last, target);
    printf("탐색 성공! result: %d\n", result);      // 4가 위치한 인덱스 3이 나와야 합니다.

    target = 10;
    result = BinarySearch(arr, start, last, target);
    printf("탐색 실패! result: %d\n", result);      // 존재하지 않으니 -1이 나와야 합니다.

    return 0;
}