#include<stdio.h>
#include<assert.h>

#include "ArrayList.h"

# define TEST_NUM 8

int main() {
    List list;

    LInit(&list);
    //출력 0 8 0
    printf("INIT %d %d %d\n", list.size, list.capacity, (list.arr == NULL));

    // 리스트 저장된 데이터 8 7 6 5 4 3 2 1 
    for (int i=0; i<TEST_NUM; i++) {
        LInsertHeader(&list, i + 1);
    }
    int size = LSize(&list);
    // 출력 8 7 6 5 4 3 2 1
    for (int i=0; i<size; i++) {
        printf("%d ", LGet(&list, i));
    }
    printf("\n");

    // 출력 8 7 6 5 4 3 2 1
    for (int i=0; i<size; i++) {
        printf("%d ", LRemoveHeader(&list));
    }
    printf("\n");

    //출력 0 8 0
    printf("INSERT-REMOVE HEADER %d %d %d\n", list.size, list.capacity, (list.arr == NULL));
    
    // 리스트 저장된 데이터 1 2 3 4 5 6 7 8 
    for (int i=0; i<TEST_NUM; i++) {
        LInsertTail(&list, i + 1);
    }

    // 리스트 저장된 데이터 5 2 3 4 5 6 7 8
    LSet(&list, 0, 5);

    // 리스트 저장된 데이터 5 2 3 99 4 5 6 7 8
    LInsertIndex(&list, 3, 99);
    // 리스트 저장된 데이터 5 2 3 100 99 4 5 6 7 8
    LInsertIndex(&list, 3, 100);
    // 리스트 저장된 데이터 5 2 3 100 99 5 6 7 8
    LRemoveIndex(&list, 5);

    // 출력 5 2 3 100 99 5 6 7 8
    size = LSize(&list);

    for (int i=0; i<size; i++) {
        printf("%d ", LGet(&list, i));
    }
    printf("\n");

    // 출력 8 7 6 5 99 100 3 2 5
    for (int i=0; i<size; i++) {
        printf("%d ", LRemoveTail(&list));
    }
    printf("\n");

    //출력 0 16 0
    printf("INSERT-REMOVE TAIL %d %d %d\n", list.size, list.capacity, (list.arr == NULL));

    LDestroy(&list);
    //출력 0 0 1
    printf("DESTROY %d %d %d\n", list.size, list.capacity, (list.arr == NULL));
    return 0;
}