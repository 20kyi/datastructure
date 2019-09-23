#include <stdlib.h>
#include <stdio.h>
#include "AVLTree.h"

BinaryTreeNode * rebalance(BinaryTreeNode * pTree);

//public
void AVLTMakeAndInit(AVLTree * pTree, AVLComapreFunction compare) {
    BSTMakeAndInit(pTree, compare);
}

void AVLTDestroy(AVLTree * pTree) {
    BSTDestroy(pTree);
}

void AVLTInsert(AVLTree * pTree, AVLData data){
    BSTInsert(pTree, data);
    pTree->root = rebalance(pTree->root);
}

int AVLTRemove(AVLTree * pTree, AVLData target) {
    int result = BSTRemove(pTree, target);

    if (result) {
        pTree->root = rebalance(pTree->root);
    }

    return result;
}

int AVLTSearch(AVLTree * pTree, AVLData target) {
    return BSTSearch(pTree, target);
}

void AVLTShowAll(AVLTree * pTree, TraversalFuctionPtr action) {
    BSTShowAll(pTree, action);
}

//private

int getHeight(BinaryTreeNode * pTree) {
    if (pTree == NULL) {
        return 0;
    }

    int left = getHeight(GetLeftSubTree(pTree));
    int right = getHeight(GetRightSubTree(pTree));    
    return ( (left > right) ? left : right ) + 1;
}

int getHeightDifferent(BinaryTreeNode * pTree) {
    if (pTree == NULL) {
        return 0;
    }

    int left = getHeight(GetLeftSubTree(pTree));
    int right = getHeight(GetRightSubTree(pTree));    
    return left - right;
}

BinaryTreeNode * rotateLL (BinaryTreeNode * pTree) {
    BinaryTreeNode * parent = pTree;
    BinaryTreeNode * child = GetLeftSubTree(parent);
    ChangeLeftSubTree(parent, GetRightSubTree(child));
    ChangeRightSubTree(child, parent);
    return child;   
}

BinaryTreeNode * rotateRR (BinaryTreeNode * pTree) {
    BinaryTreeNode * parent = pTree;
    BinaryTreeNode * child = GetRightSubTree(parent);
    ChangeRightSubTree(parent, GetLeftSubTree(child));
    ChangeLeftSubTree(child, parent);
    return child;  
}

BinaryTreeNode * rotateLR (BinaryTreeNode * pTree) {
    BinaryTreeNode * parent = pTree;
    BinaryTreeNode * child = GetLeftSubTree(parent);
    ChangeLeftSubTree(parent, rotateRR(child)); //부분 RR회전
    return rotateLL(child); //LL회전     
}

BinaryTreeNode * rotateRL (BinaryTreeNode * pTree) {
    BinaryTreeNode * parent = pTree;
    BinaryTreeNode * child = GetLeftSubTree(parent);
    ChangeRightSubTree(parent, rotateLL(child)); //부분 LL회전
    return rotateRR(child); //RR 회전
}

BinaryTreeNode * rebalance(BinaryTreeNode * root) {
    if (root == NULL) {
        return NULL;
    }

    root->left = rebalance(root->left);
    root->right = rebalance(root->right);

    int heightDiff = getHeightDifferent(root);

    if (heightDiff > 1) {
        if (getHeightDifferent(GetLeftSubTree(root)) > 0) {
            root = rotateLL(root);
        } else {
            root = rotateLR(root);
        }
    }

    if (heightDiff < -1) {
        if (getHeightDifferent(GetRightSubTree(root)) < 0) {
            root = rotateRR(root);
        } else {
            root = rotateRL(root);
        }
    }

    return root;
}

