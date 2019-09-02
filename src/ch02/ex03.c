/* 팩토리얼을 표현한 예제입니다. */

#include<stdio.h>

/**
 * 팩토리얼을 재귀 함수로 표현한 코드입니다.
 * @ n = 자연수 n 입니다.
 * return n! 을 값을 나타냅니다.
 *        if n == 1: 1
 *        else: n * factorial(n-1)
 */ 
int factorial(int n) {
    if (n == 1)
        return n;

    return n * factorial(n-1);
}

int main() {
    int n = 3;
    int result = factorial(n); // 3 x 2 x 1 = 6
    printf("%d! = %d\n", n, result);
    return 0;
}