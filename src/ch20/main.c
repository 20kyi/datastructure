#include <stdio.h>

#include "BinarySearchTree.h"

int compareIntData(void * pData1, void * pData2) {
    int data1 = *( (int *) pData1);
    int data2 = *( (int *) pData2);
    return data1-data2;
}

void ShowData(BSTData pData) {
    int data = *( (int *) pData);
    printf("%d ", data);
}

int main() {

    int insert[] = { 5, 8, 1, 6, 4, 9, 3, 2, 7 };
    int target[] = { 5, 2, 9, 3, 8, 1, 6, 4, 7 };
    int insertSize = sizeof(insert) / sizeof(insert[0]);
    int targetSize = sizeof(target) / sizeof(target[0]);

    BinarySearchTree bst;
    BSTMakeAndInit(&bst, compareIntData);
    
    for (int i=0; i<insertSize; i++) {
        BSTInsert(&bst, &insert[i]);
    }
    
    for (int i=0; i<targetSize; i++) {
        int searchResult = BSTSearch(&bst, &target[i]);

        if (searchResult == 0) {
            printf("탐색 실패\n");
        } else {
            printf("탐색 성공 : %d\n", target[i]);
        }
    }

    printf("트리 상태 : ");
    BSTShowAll(&bst, ShowData);
    printf("\n");

    for (int i=0; i<targetSize; i++) {
        int removeResult = BSTRemove(&bst, &target[i]);

        if (removeResult == 0) {
            printf("삭제 실패\n");
        } else {
            printf("삭제 성공 : %d\n", target[i]);
        }

        printf("트리 상태 : ");
        BSTShowAll(&bst, ShowData);
        printf("\n");
    }

    BSTDestroy(&bst);
    return 0;
}