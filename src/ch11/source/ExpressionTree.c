#include "../header/ExpressionTree.h"
#include "../header/Stack.h"

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

BinaryTreeNode * MaekExpTree(char exp[]) {
    Stack stack;
    SInit(&stack);

    int expLen = strlen(exp);
    for (int i=0; i<expLen; i++) {
        BinaryTreeNode * node = MakeBinaryTreeNode();
        char data = exp[i];
        
        if (isdigit(data)) {
            SetData(node, data - '0');
        } else {
            BinaryTreeNode * right = (BinaryTreeNode *) SPop(&stack);
            BinaryTreeNode * left = (BinaryTreeNode *) SPop(&stack);

            MakeLeftSubTree(node, left);
            MakeRightSubTree(node, right);
            SetData(node, data);
        }

        SPush(&stack, node);
    }

    BinaryTreeNode * expTree = (BinaryTreeNode *) SPop(&stack);
    SDestroy(&stack);
    return expTree;
}

int EvaluateExpTree(BinaryTreeNode * bt) {

    BinaryTreeNode * left = GetLeftSubTree(bt);
    BinaryTreeNode * right = GetRightSubTree(bt);

    if (left == NULL && right == NULL) {
        return GetData(bt);
    }

    int op1 = EvaluateExpTree(left);
    int op2 = EvaluateExpTree(right);
    char operator = GetData(bt);

    switch (operator)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    
    default:
        assert("Operator Error! You should input +, -, * /");
        return -1;
    }
}

void ShowData(BTData data) {
    if (0 <= data && data <= 9) {
        printf("%d ", data);
    } else {
        printf("%c ", data);
    }
}

void ShowPrefixTypeExp(BinaryTreeNode * bt) {
    PreOrderTraverse(bt, ShowData);
}

void ShowInfixTypeExp(BinaryTreeNode * bt) {
    if (bt == NULL) 
        return;
    
    BinaryTreeNode * left = GetLeftSubTree(bt);
    BinaryTreeNode * right = GetRightSubTree(bt);

    if (left != NULL && right != NULL) {
        printf("( ");
    }

    ShowInfixTypeExp(left);
    ShowData(GetData(bt));
    ShowInfixTypeExp(right);

    if (left != NULL && right != NULL) {
        printf(") ");
    }
}

void ShowPostfixTypeExp(BinaryTreeNode * bt) {
    PostOrderTraverse(bt, ShowData);
}

void DestroyExpressionTree(BinaryTreeNode * bt) {
    RemoveTreeNode(bt);
}