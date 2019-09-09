#include <stdio.h>

#include "BinaryTree.h"

void ShowData(BTData data) {
    printf("%d ", data);
}

int main() {

    BinaryTreeNode * bt1 = MakeBinaryTreeNode();
    SetData(bt1, 1);

    BinaryTreeNode * bt2 = MakeBinaryTreeNode();
    SetData(bt2, 2);

    BinaryTreeNode * bt3 = MakeBinaryTreeNode();
    SetData(bt3, 3);

    BinaryTreeNode * bt4 = MakeBinaryTreeNode();
    SetData(bt4, 4);

    BinaryTreeNode * bt5 = MakeBinaryTreeNode();
    SetData(bt5, 5);

    BinaryTreeNode * bt6 = MakeBinaryTreeNode();
    SetData(bt6, 6);

    BinaryTreeNode * bt7 = MakeBinaryTreeNode();
    SetData(bt7, 7);

    MakeLeftSubTree(bt2, bt3);   
    MakeRightSubTree(bt2, bt4);

    MakeLeftSubTree(bt5, bt6);   
    MakeRightSubTree(bt5, bt7);

    MakeLeftSubTree(bt1, bt2);   
    MakeRightSubTree(bt1, bt5);

    // 출력 1 2 3 4 5 6 7
    PreOrderTraverse(bt1, ShowData);
    printf("\n");

    // 출력 3 2 4 1 6 5 7
    InOrderTraverse(bt1, ShowData);
    printf("\n");

    // 출력 3 4 2 6 7 5 1
    PostOrderTraverse(bt1, ShowData);
    printf("\n");

    RemoveTreeNode(bt1);

    return 0;
}