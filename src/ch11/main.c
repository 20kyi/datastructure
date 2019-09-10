#include<stdio.h>
#include <stdlib.h>

#include "header/ExpressionConverter.h"
#include "header/ExpressionTree.h"

#define BUFFER_SIZE 10000

int main() {    
    char input[BUFFER_SIZE];
    scanf("%s", input);
    
    char * postfixExp = ConvertExpressionInfixToPostfix(input);
    BinaryTreeNode * expTree = MaekExpTree(postfixExp);
    
    printf("Show Prefix : ");
    ShowPrefixTypeExp(expTree);
    printf("\n");

    printf("Show Infix : ");
    ShowInfixTypeExp(expTree);
    printf("\n");

    printf("Show Postfix : ");
    ShowPostfixTypeExp(expTree);
    printf("\n");

    int result = EvaluateExpTree(expTree);
    printf("result: %d\n", result);

    DestroyExpressionTree(expTree);
    free(postfixExp);

    return 0;
}
