#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include "BinaryTree.h"

typedef BTData BSTData;
typedef int BSTCompareFunction(BSTData d1, BSTData d2);

typedef struct _binary_search_tree {
    BinaryTreeNode * root;
    BSTCompareFunction * compare;
} BinarySearchTree;


void BSTMakeAndInit(BinarySearchTree * pBst, BSTCompareFunction compare);

void BSTDestroy(BinarySearchTree * pBst);

void BSTInsert(BinarySearchTree * pBst, BSTData data);

int BSTRemove(BinarySearchTree * pBst, BSTData target);

int BSTSearch(BinarySearchTree * pBst, BSTData target);

void BSTShowAll(BinarySearchTree * pBst, TraversalFuctionPtr action);

#endif // !