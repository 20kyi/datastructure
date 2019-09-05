#include <stdlib.h>

#include "../header/ExpressionConverter.h"
#include "../header/PostfixCalculator.h"
#include "../header/Calculator.h"

/**
 *  사용자의 입력을 계산합니다.
 *  @param exp char[] 사용자가 입력한 중위 표현식
 * 
 *  return int 사용자가 입력한 표현식에 대한 결과 값입니다.
 */ 
int Calculate(char exp[]){
    char * postfixExp = ConvertExpressionInfixToPostfix(exp);
    int result = CalculatePostfixExpression(postfixExp);
    free(postfixExp);
    return result; 
}
