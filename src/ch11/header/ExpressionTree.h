#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__

#include "BinaryTree.h"

BinaryTreeNode * MaekExpTree(char exp[]);
int EvaluateExpTree(BinaryTreeNode * bt);

void ShowPrefixTypeExp(BinaryTreeNode * bt);
void ShowInfixTypeExp(BinaryTreeNode * bt);
void ShowPostfixTypeExp(BinaryTreeNode * bt);

void DestroyExpressionTree(BinaryTreeNode * bt);

#endif
