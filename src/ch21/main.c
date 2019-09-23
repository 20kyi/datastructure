#include <stdio.h>
#include <stdlib.h>

#include "BinaryTree.h"
#include "AVLTree.h"

#define space 5

typedef BinaryTreeNode node;
//secondary function
void draw_tree_hor2(node *tree, int distance)
{
    // stopping condition
    if (tree== NULL)
        return;

    // increase spacing
    distance += space;

    // start with right node
    draw_tree_hor2(tree->right, distance);

    // print root after spacing

    printf("\n");

    for (int i = space; i < distance; i++)
        printf(" ");

    printf("%d\n", *( (int *) tree->data));

    // go to left node
    draw_tree_hor2(tree->left, distance);
}

//primary fuction
void draw_tree_hor(node *tree)
{
    draw_tree_hor2(tree, 0);
}


int compareIntData(void * pData1, void * pData2) {
    int data1 = *( (int *) pData1);
    int data2 = *( (int *) pData2);
    return data1-data2;
}

void ShowData(AVLData pData) {
    int data = *( (int *) pData);
    printf("%d ", data);
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

        printf("트리 상태 : ");
        printf("루트 (%p %d) ", avlTree.root, *((int *)avlTree.root->data));
        AVLTShowAll(&avlTree, ShowData);
        printf("\n");
        draw_tree_hor(avlTree.root);
        printf("\n\n");
    }

    printf("height: %d ", getHeight(avlTree.root));
    int leftData = *((int *) avlTree.root->left->left->data);
    printf("left: %d  %d ", getHeight(avlTree.root->left), leftData);

    int rightData = *((int *) avlTree.root->right->right->data);
    printf("right: %d %d\n\n", getHeight(avlTree.root->right), rightData);
    
    for (int i=0; i<targetSize; i++) {
        int searchResult = AVLTSearch(&avlTree, &target[i]);

        if (searchResult == 0) {
            printf("탐색 실패\n");
        } else {
            printf("탐색 성공 : %d\n", target[i]);
        }
    }
    printf("\n\n");

    for (int i=0; i<targetSize; i++) {
        printf("트리 상태 : ");
        printf("루트 (%p %d) ", avlTree.root, *((int *)avlTree.root->data));
        AVLTShowAll(&avlTree, ShowData);
        printf("\n");
        draw_tree_hor(avlTree.root);
        printf("\n\n");

        int removeResult = AVLTRemove(&avlTree, &target[i]);

        if (removeResult == 0) {
            printf("삭제 실패\n");
        } else {
            printf("삭제 성공 : %d\n", target[i]);
        }
    }

    AVLTDestroy(&avlTree);
    return 0;
}