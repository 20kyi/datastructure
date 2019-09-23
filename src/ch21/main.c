#include <stdio.h>
#include <stdlib.h>

#include "BinaryTree.h"
#include "AVLTree.h"

#define space 5

typedef BinaryTreeNode node;

void draw_tree_hor2(node *tree, int distance){
    if (tree== NULL) {
        return;
    }

    distance += space;
    draw_tree_hor2(tree->right, distance);

    printf("\n");
    for (int i = space; i < distance; i++)
        printf(" ");

    printf("%d\n", *( (int *) tree->data));

    draw_tree_hor2(tree->left, distance);
}

void draw_tree_hor(node *tree){
    draw_tree_hor2(tree, 0);
}


void showData(AVLData pData) {
    int data = *( (int *) pData);
    printf("%d ", data);
}

void showTree(AVLTree * pTree) {
    if (pTree->root == NULL) {
        return;
    }

    printf("트리 상태 : ");
    printf("루트 (%p %d) ", pTree->root, *( (int *) GetData(pTree->root)));
    AVLTShowAll(pTree, showData);
    printf("\n");
    draw_tree_hor(pTree->root);
    printf("\n\n");
}

int compareIntData(void * pData1, void * pData2) {
    int data1 = *( (int *) pData1);
    int data2 = *( (int *) pData2);
    return data1-data2;
}

int main() {

    int insert[] = { 1, 2, 3, 4, 5, 6, 0 };
    int target[] = { 3, 4, 5, 1, 2, 6, 0 };
    int insertSize = sizeof(insert) / sizeof(insert[0]);
    int targetSize = sizeof(target) / sizeof(target[0]);

    AVLTree avlTree;
    AVLTMakeAndInit(&avlTree, compareIntData);
    
    for (int i=0; i<insertSize; i++) {
        AVLTInsert(&avlTree, &insert[i]);
        showTree(&avlTree);
    }

    for (int i=0; i<targetSize; i++) {
        int removeResult = AVLTRemove(&avlTree, &target[i]);

        if (removeResult == 0) {
            printf("삭제 실패\n");
        } else {
            printf("삭제 성공 : %d\n", target[i]);
        }

        showTree(&avlTree);
    }

    AVLTDestroy(&avlTree);
    return 0;
}