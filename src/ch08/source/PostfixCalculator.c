#include <assert.h>
#include <ctype.h>
#include <string.h>

#include "../header/Stack.h"
#include "../header/PostfixCalculator.h"

/**
 * 산술 연산자에 따른 피 연산자 결과 값을 나타냅니다.
 * 산술 연산자가 아니면 에러를 뱉습니다.
 * 
 * @param op1 int 피연산자1
 * @param op2 int 피연산자2
 * @param opeeartor char 연산자
 * 
 * return int 수식 "피연산자1 연산자 피연산자2"에 대한 결과 값
 */ 
int calculateOperandsByOperator(int op1, int op2, char opearator) {
    if (opearator == '+')
        return op1 + op2;
    
    if (opearator == '-')
        return op1 - op2;

    if (opearator == '*')
        return op1 * op2;

    if (opearator == '/') 
        return op1 / op2;

    assert("Error: NotDefiendOperatorError");
}

/** 
 * data 가 연산자의 경우, 데이터 처리 함수.
 * @param operator char  산술 연산자
 * @param pStack Stack * 피연산자를 저장하는 스택의 주소
 * 
 * 1. 피연산자2 = 스택에서 첫 번째로 꺼낸 수
 * 2. 피연산자1 = 스택에서 두 번째로 꺼낸 수
 * 3. 연산
 * 4. 그 결과를 스택에 다시 저장
 */ 
void processDataIsOperator(char operator, Stack * pStack) {
    int op2 = SPop(pStack);
    int op1 = SPop(pStack);
    int res = calculateOperandsByOperator(op1, op2, operator);
    SPush(pStack, res);
}

/**
 * 후위 표현식을 계산을 위해 반복 호출되는 함수
 * 
 * @param data char      후위 표현식 문자열에 저장된 문자
 * @param pStack Stack * 피 연산자를 저장하는 스택
 * 
 * 만약 데이터가 숫자라면, 스택에 피연산자 저장,
 * 만약 데이터가 연산자라면, 스택에서 2개의 피 연산자를 꺼내온 후 연산자에 대한 연산 후 그 값을 다시 스택에 저장
 */
void processDataWhenCalculatePostfix(char data, Stack * pStack) {
    if (isdigit(data)) {
        SPush(pStack, (data-'0'));
        return;
    }

    processDataIsOperator(data, pStack);
}

/**
 * 후위 표현식 계산 함수.
 * 
 * @param postfixExp char[] 후휘 표현식이 저장된 문자열.
 * 
 * 스택을 이용해서, 후위 표현식을 계산한다.
 * 
 * return int 계산된 결과 값.
 */ 
int CalculatePostfixExpression(char postfixExp[]){
    Stack stack;
    SInit(&stack);
    int size = strlen(postfixExp);

    for (int i=0; i<size; i++) {
        char data = postfixExp[i];
        processDataWhenCalculatePostfix(data, &stack);
    }

    int result = SPop(&stack);
    SDestroy(&stack);
    return result;
}