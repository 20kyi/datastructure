#ifndef __AVL_TREE_H__
#define __AVL_TREE_H__

#include "BinarySearchTree.h"

typedef BSTData AVLData;
typedef BSTCompareFunction AVLComapreFunction;
typedef BinarySearchTree AVLTree;

void AVLTMakeAndInit(AVLTree * pTree, AVLComapreFunction compare);

void AVLTDestroy(AVLTree * pTree);

void AVLTInsert(AVLTree * pTree, AVLData data);

int AVLTRemove(AVLTree * pTree, AVLData target);

int AVLTSearch(AVLTree * pTree, AVLData target);

void AVLTShowAll(AVLTree * pTree, TraversalFuctionPtr action);

int getHeight(BinaryTreeNode * pTree);

#endif