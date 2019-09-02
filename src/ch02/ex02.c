/* 재귀 함수 방식으로 합계를 표현한 예제입니다. */
#include<stdio.h>

/**
 * n int 자연수 n입니다.
 * return 1~n까지의 합입니다.
 */ 
int RecursiveSum(unsigned int n) {
    if (n == 0)
        return n;

    return n + RecursiveSum(n-1);
}

int main()
{
    int result = RecursiveSum(5); // 15
    printf("result %d\n", result);
    return 0;
}
