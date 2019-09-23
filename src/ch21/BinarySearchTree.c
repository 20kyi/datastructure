#include <stdlib.h>

#include "BinarySearchTree.h"

void BSTMakeAndInit(BinarySearchTree * pBst, BSTCompareFunction compare) {
    pBst->root = NULL;
    pBst->compare = compare;
}

void BSTDestroy(BinarySearchTree * pBst) {
    if (pBst->root != NULL) {
        RemoveTreeNode(pBst->root);
    }
}

void BSTInsert(BinarySearchTree * pBst, BSTData data) {
    BinaryTreeNode * new = MakeBinaryTreeNode();
    SetData(new, data);
    BinaryTreeNode * curr = pBst->root;
    BinaryTreeNode * parent = NULL;
    
    while (curr != NULL) {

        if ( pBst->compare(data, GetData(curr)) == 0 ) {
            return;
        }

        parent = curr;
        curr = ( pBst->compare( GetData(curr), data ) > 0 ) ? GetLeftSubTree(curr) : GetRightSubTree(curr);
    }

    if (parent == NULL) {
        pBst->root = new;
        return;
    }

    if ( pBst->compare(data, GetData(parent)) < 0 ) {
        MakeLeftSubTree(parent, new);
        return;
    } 
    
    MakeRightSubTree(parent, new);
}

int BSTRemove(BinarySearchTree * pBst, BSTData target) {
    BinaryTreeNode * pVRoot = MakeBinaryTreeNode();
    BinaryTreeNode * parent = pVRoot;
    BinaryTreeNode * curr = pBst->root;
    ChangeRightSubTree(pVRoot, pBst->root);
    
    while ( (curr != NULL) && (pBst->compare(GetData(curr), target) != 0) ){
        parent = curr;
        curr = (pBst->compare(target, GetData(curr)) < 0) ? GetLeftSubTree(curr) : GetRightSubTree(curr);
    }
    
    if (curr == NULL) {
        return 0;
    }

    BinaryTreeNode * del = curr;

    if (GetLeftSubTree(del) == NULL && GetRightSubTree(del) == NULL) {
        
        if (GetLeftSubTree(parent) == del) {
            RemoveLeftSubTree(parent);
        } else {
            RemoveRightSubTree(parent);
        }
    } else if ( GetLeftSubTree(del) == NULL || GetRightSubTree(del) == NULL ) {
        BinaryTreeNode * childOfDelete = (GetLeftSubTree(del) != NULL) ? GetLeftSubTree(del) : GetRightSubTree(del);

        if (GetLeftSubTree(parent) == del) {
            ChangeLeftSubTree(parent, childOfDelete);
        } else {
            ChangeRightSubTree(parent, childOfDelete);
        }
    } else {
        BinaryTreeNode * alternateNode = GetRightSubTree(del);
        BinaryTreeNode * parentOfAlternate = del;

        while (GetLeftSubTree(alternateNode) != NULL){
            parentOfAlternate = alternateNode;
            alternateNode = GetLeftSubTree(alternateNode);
        }
        
        BSTData delData = GetData(del);
        SetData(del, GetData(alternateNode));

        if (GetLeftSubTree(parentOfAlternate) == alternateNode) {
            ChangeLeftSubTree(parentOfAlternate, GetRightSubTree(alternateNode));
        } else {
            ChangeRightSubTree(parentOfAlternate, GetRightSubTree(alternateNode));
        }

        del = alternateNode;
        SetData(del, delData);
    }
    
    if (GetRightSubTree(pVRoot) != pBst->root) {
        pBst->root = GetRightSubTree(pVRoot);
    }

    free(pVRoot);
    free(del);    
    return 1;
}

int BSTSearch(BinarySearchTree * pBst, BSTData target) {
    BinaryTreeNode * curr = pBst->root;

    while (curr != NULL) {
        BSTData data = GetData(curr);
        int compareResult = pBst->compare(target, data);
        
        if ( compareResult == 0 ) {
            return 1;
        } 

        curr = ( compareResult < 0 ) ? GetLeftSubTree(curr) : GetRightSubTree(curr);
    }

    return 0;
}

void BSTShowAll(BinarySearchTree * pBst, TraversalFuctionPtr action) {
    InOrderTraverse(pBst->root, action);
}
