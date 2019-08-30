/**
 * 주어진 배열의 합을 더하는 프로그램 예제입니다.
 */

#include<stdio.h>

/**
 * 배열의 합을 구하는 함수입니다.
 * 
 * @ arr int [] 합을 구하는 공간, 배열입니다.
 * @ len int    배열의 길이 입니다.
 * 
 * return 배열안의 모든 수를 더한 합입니다.
 */
int Sum(int arr[], int len){
    int result = 0;

    for (int i=0; i<len; i++){
        result += arr[i];
    }

    return result;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int len = sizeof(arr) / sizeof(int);

    int result = Sum(arr, len);
    printf("합계 result: %d\n", result);      // 1 + 2 + 3 + 4 + 5 = 15
    
    return 0;
}