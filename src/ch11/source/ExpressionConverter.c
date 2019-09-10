#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

#include "../header/Stack.h"
#include "../header/ExpressionConverter.h"

/**
 * 산술 연산자에 대해서 우선 순위를 반환하는 함수.
 * 
 * @param operator char 연산자를 표현하는 문자
 * 
 * 연산자 우선순위는 다음과 같다.
 * 1. *, / 
 * 2. +, -
 * 3. (
 * 
 * return int 연산자에 따른 우선 순위
 */ 
int getOperationPriority(char operator) {
    switch (operator){

    case '*':
    case '/':
        return 3;
    case '+':
    case '-':
        return 2;
    case '(':
        return 1;
    default:
        return -1;
    }
}


/**
 * 연산자 비교 함수
 * 
 * @param op1 char 연산자1
 * @param op2 char 연산자2
 * 
 * return int 연산자1이 연산자2의 우선순위보다 높거나 같으면 1 아니면 0
 */ 
int isPrioirty(char op1, char op2) {
    int op1Priority = getOperationPriority(op1);
    int op2Priority = getOperationPriority(op2);
    return op1Priority >= op2Priority;
}


/**
 * 사용자가 입력한 중위 표현식을 후위 표현식으로 바꿔주는 함수
 * 
 * @param infixExp char[] 중위 표현식을 나타내는 문자열
 * 
 * return char * 후위 표현식으로 바꿔진 문자열
 * 
 * 스택을 이용하여 입력한 중위 표현식을 후위 표현식으로 바꾼다. 반환된 문자열은 heap 영역에 할당된 메모리이기 때문에 꼭 해제가 필요하다.
 */
char * ConvertExpressionInfixToPostfix(char infixExp[]){
    Stack stack;
    SInit(&stack);

    int size = strlen(infixExp);
    char * postfixExp = (char *) malloc( sizeof(char) * (size + 1) ); 
    int offset = 0;

    for (int i=0; i<size; i++) {
        char * pData = infixExp+i;
        char data = *pData;

        if (isdigit(data)) {
            postfixExp[offset] = data;
            offset += 1;
        } else if (data == '(') {
            SPush(&stack, pData);
        } else if ( data == ')') {
            while(1) {
                char peek = *((char *) SPeek(&stack));

                if (peek == '(') {
                    break;
                }

                char * pop = (char *) SPop(&stack);
                postfixExp[offset] = *pop;
                offset += 1;
            }

            SPop(&stack);
        } else {
            while (!SIsEmpty(&stack)){
                char peek = *((char *) SPeek(&stack));

                if (!isPrioirty(peek, data) ) {
                    break;
                }

                char * pop = (char *) SPop(&stack);
                postfixExp[offset] = *pop;
                offset += 1;
            }
            
            SPush(&stack, pData);
        }            
    }

    while (!SIsEmpty(&stack)){
        char * pop = (char *) SPop(&stack);
        postfixExp[offset] = *pop;
        offset += 1;
    }
    
    SDestroy(&stack);
    return postfixExp;
}