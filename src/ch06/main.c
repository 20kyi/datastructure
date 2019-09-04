#include<stdio.h>
#include<assert.h>

#include "DoubleLinkedList.h"

# define TEST_NUM 8

int main() {
    List list;

    LInit(&list);

    // 리스트 저장된 데이터 8 7 6 5 4 3 2 1 
    for (int i=0; i<TEST_NUM; i++) {
        LInsertHeader(&list, i + 1);
    }
    int size = LSize(&list);
    // 출력 8 7 6 5 4 3 2 1
    printf("LInsertHeader: ");
    for (int i=0; i<size; i++) {
        printf("%d ", LGet(&list, i));
    }
    printf("\n");

    // 출력 8 7 6 5 4 3 2 1
    printf("LRemoveHeader: ");
    for (int i=0; i<size; i++) {
        printf("%d ", LRemoveHeader(&list));
    }
    printf("\n");
    
    // 리스트 저장된 데이터 1 2 3 4 5 6 7 8 
    for (int i=0; i<TEST_NUM; i++) {
        LInsertTail(&list, i + 1);
    }

    printf("LInsertTail: ");
    for (int i=0; i<list.size; i++) {
        printf("%d ", LGet(&list, i));
    }
    printf("\n");

    // 리스트 저장된 데이터 5 2 3 4 5 6 7 8
    LSet(&list, 0, 5);
    printf("LSet: ");
    for (int i=0; i<list.size; i++) {
        printf("%d ", LGet(&list, i));
    }
    printf("\n");

    // 리스트 저장된 데이터 5 2 3 99 4 5 6 7 8
    LInsertIndex(&list, 3, 99);
    printf("LInsertIndex: ");
    for (int i=0; i<list.size; i++) {
        printf("%d ", LGet(&list, i));
    }
    printf("\n");

    // 리스트 저장된 데이터 5 2 3 100 99 4 5 6 7 8
    LInsertIndex(&list, 3, 100);
    printf("LInsertIndex: ");
    for (int i=0; i<list.size; i++) {
        printf("%d ", LGet(&list, i));
    }
    printf("\n");

    // 리스트 저장된 데이터 5 2 3 100 99 5 6 7 8
    LRemoveIndex(&list, 5);
    printf("LRemoveIndex: ");
    for (int i=0; i<list.size; i++) {
        printf("%d ", LGet(&list, i));
    }
    printf("\n");

    size = LSize(&list);

    // 출력 5 2 3 100 99 5 6 7 8
    printf("LGet LAST: ");
    for (int i=0; i<size; i++) {
        printf("%d ", LGet(&list, i));
    }
    printf("\n");

    // 출력 8 7 6 5 99 100 3 2 5
    printf("LRemoveTail: ");
    for (int i=0; i<size; i++) {
        printf("%d ", LRemoveTail(&list));
    }
    printf("\n");

    LDestroy(&list);
    return 0;
}