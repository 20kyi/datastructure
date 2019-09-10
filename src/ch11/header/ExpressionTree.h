#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__

#include "BinaryTree.h"

BinaryTreeNode * MakeExpressionTree(char exp[]);
int EvaluateExpressionTree(BinaryTreeNode * bt);

void ShowPrefixTypeExp(BinaryTreeNode * bt);
void ShowInfixTypeExp(BinaryTreeNode * bt);
void ShowPostfixTypeExp(BinaryTreeNode * bt);

void DestroyExpressionTree(BinaryTreeNode * bt);

#endif
