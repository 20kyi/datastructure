/**
 * 순차 탐색에 대한 예제입니다.
 */

#include<stdio.h>

/**
 * 순차 탐색을 위한 함수입니다.
 * 
 * @ arr int [] 순차 탐색을 하는 공간, 배열입니다.
 * @ len int    배열의 길이 입니다.
 * @ target int 찾는 숫자입니다.
 * 
 * return 찾았으면, 배열에서 해당 숫자가 위치하는 인덱스, 없으면 -1
 */
int LinearSearch(int arr[], int len, int target){
    for (int i=0; i<len; i++){
        if (arr[i] == target) {
            return i;
        }
    }

    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int len = sizeof(arr) / sizeof(int);
    int target = 4;

    int result = LinearSearch(arr, len, target);
    printf("탐색 성공! result: %d\n", result);      // 4가 위치한 인덱스 3이 나와야 합니다.

    target = 10;
    result =  LinearSearch(arr, len, target);
    printf("탐색 실패! result: %d\n", result);      // 존재하지 않으니 -1이 나와야 합니다.

    return 0;
}