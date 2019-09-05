#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
int compareOperation(char op1, char op2) {
    int op1Priority = getOperationPriority(op1);
    int op2Priority = getOperationPriority(op2);
    return op1Priority >= op2Priority;
}

/**
 * data를 후위 표현식 문자열에 옮기는 함수
 * 
 * @param data char     저장될 문자
 * @param dest char[]   data가 저장된 문자열 (후위 표현식)
 * @param pOffset int * 문자가 저장될 offset의 주소
 * 
 * data를 문자열 dest의 offset 위치에 저장한다. 그 후 offset 1 증가시킨다.
 */ 
void moveDataToDest(char data, char dest[], int * pOffset) {
    dest[*pOffset] = data;
    (*pOffset) += 1;
}

/**
 * 연산자가 ')' 일 때, 쓰이는 함수
 * 
 * @param pStack Stack * 연산자가 저장되는 스택의 주소
 * @param dest char[]    후위 표현식을 저장하는 문자열
 * @param pOffset int *  dest에 저장될 offset의 주소
 * 
 * 스택에서 '(' 연산자가 나올때까지 스택의 저장된 연산자를 dest에 옮긴다.
 * 그 후 '('는 버린다.
 */
void convertExpressionWhenOperatorIsClose(Stack * pStack, char dest[], int * pOffset) {
    while( SPeek(pStack) != '(' ) {
        moveDataToDest(SPop(pStack), dest, pOffset);
    }

    SPop(pStack);
}

/**
 * 연산자가 산술 연산자의 경우 쓰이는 함수
 * 
 * @param operator char  현재 연산자
 * @param pStack Stack * 연산자가 저장되는 스택의 주소
 * @param dest char[]    후위 표현식을 저장하는 문자열
 * @param pOffset int *  dest에 저장될 offset의 주소
 * 
 * 스택이 비지 않고, 스택에 맨 위의 저장된 연산자가 현재 연산자보다 우선 순위가 같거나 높을 때까지, 스택에 저장된 연산자를 `dest`에 옮긴다.
 * 그리고 현재 연산자를 스택에 저장한다.
 */ 
void convertExpressionWhenOperatorIsArithmetic(char operator, Stack * pStack, char dest[], int * pOffset) {
    while (!SIsEmpty(pStack) && compareOperation(SPeek(pStack), operator)){
        moveDataToDest(SPop(pStack), dest, pOffset);
    }
    
    SPush(pStack, operator);
}

/**
 * 연산자의 경우 후위 표현식으로 바꾸는 함수
 * 
 * @param operator char  현재 연산자
 * @param pStack Stack * 연산자가 저장되는 스택의 주소
 * @param dest char[]    후위 표현식을 저장하는 문자열
 * @param pOffset int *  dest에 저장될 offset의 주소
 * 
 * '(' 연산자일 경우 묻지도 따지지도 않고 스택에 저장한다.
 * ')' 연산자일 경우 스택의 맨 위의 저장된 데이터가 '('일 때까지 저장된 연산자를 dest에 옮긴다.
 * 산술 연산자일 경우, 스택에 데이터가 있고, 스택 맨 위의 저장된 데터가 현재 연산자보다 우선순위가 높을 때까지 저장된 연산자를 dest에 옮긴다.
 */ 
void convertExpressionIsOperator(char op, Stack * pStack, char dest[], int * pOffset) {
    if (op == '(') {
        SPush(pStack, op);
        return;
    }

    if (op == ')') {
        convertExpressionWhenOperatorIsClose(pStack, dest, pOffset);
        return;
    }

    convertExpressionWhenOperatorIsArithmetic(op, pStack, dest, pOffset);
}

/**
 * 후위 표현식으로 바꿀 때 호출되는 함수
 * 
 * @param data char      중위 표현식의 문자 1개
 * @param pStack Stack * 연산자를 저장할 스택
 * @param dest char[]    후위 표현식을 표현할 문자열
 * @param pOffset int *  data 가 dest 에 저장될 offset의 주소
 * 
 * data가 만약 숫자라면, 후위 표현식 dest로 옮긴다. 연산자라면, 연산자에 맞게 데이터를 처리한 후 dest로 옮긴다.
 */ 
void processDataWhenConvertExpression(char data, Stack *pStack, char dest[], int * pOffset) {
    if (isdigit(data)) {
        moveDataToDest(data, dest, pOffset);
        return;
    } 

    convertExpressionIsOperator(data, pStack, dest, pOffset);
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
        char data = infixExp[i];
        processDataWhenConvertExpression(data, &stack, postfixExp, &offset);
    }

    while (!SIsEmpty(&stack)){
        moveDataToDest(SPop(&stack), postfixExp, &offset);
    }
    
    SDestroy(&stack);
    return postfixExp;
}