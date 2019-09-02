/* 피보나츠 수열을 재귀 호출 방식으로 표현한 예제입니다. */
#include<stdio.h>

/**
 *  @n int 자연수 n입니다.
 * return 0                                [n == 1]
 *        1                                [n == 2]
 *        Fibonacci(n-1) + Fibonacci(n-2)  [else]
 */ 
int Fibonacci(int n) {
    if (n == 1)
        return 0;
    else if (n == 2)
        return 1;
    else 
        return Fibonacci(n-1) + Fibonacci(n-2);
}

int main() {
    int n = 7;
    int result = Fibonacci(n);
    printf("Fibonacci(%d): %d\n", n, result);
    return 0;
}