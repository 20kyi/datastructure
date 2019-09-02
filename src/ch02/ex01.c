/* 재귀 호출의 간단한 예제입니다. */

#include<stdio.h>

/** 
 * 재귀 함수입니다. 프로그램이 종료될 때까지 무한히 
 * Recursive!!
 * 라는 문구를 출력합니다.
 */
void Recursive(){
    printf("RECURSIVE!!\n");
    Recursive();
}

int main() {
    Recursive(); //무한 반복...
    return 0;
}