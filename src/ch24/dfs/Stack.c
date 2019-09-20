#include<stdio.h>
#include<assert.h>

#include "Stack.h"

/**
 * 스택 생성 함수입니다.
 * @param pStack Stack * 스택의 주소를 받습니다.
 * 
 * 기존 배열 리스트를 이용하기 때문에, 배열 리스트의 생성 함수 LInit을 호출합니다.
 */
void SInit(Stack * pStack){
    LInit(pStack);
}

/**
 * 스택 파괴 함수입니다.
 * @param pStack Stack * 스택의 주소를 받습니다.
 * 
 * 기존 배열 리스트를 이용하기 때문에, 배열 리스트의 파괴 함수 LDestroy을 호출합니다.
 */
void SDestroy(Stack * pStack){
    LDestroy(pStack);
}

/**
 * 스택이 비어있는지 여부를 확인하는 함수입니다.
 * @param pStack Stack * 스택의 주소를 받습니다.
 * 
 * 기존 배열 리스트를 이용하기 때문에, 배열 크기를 반환하는 함수 LSize를 호출합니다.
 * 그 값이 0이라면 참(1)을, 아니라면 거짓(1)을 반환합니다.
 */
int SIsEmpty(Stack * pStack){
    return ( LSize(pStack) == 0 );
}

/**
 * 스택에 데이터를 넣습니다.
 * @param pStack Stack * 스택의 주소를 받습니다.
 * @param data SData     스택에 넣을 데이터입니다.
 * 
 * 배열리스트 꼬리 삽입 함수를 이용합니다.
 */
void SPush(Stack * pStack, SData data){
    LInsertTail(pStack, data);
}

/**
 * 스택에서 가장 위의 데이터를 삭제합니다.
 * @param pStack Stack * 스택의 주소를 받습니다.
 * 
 * return SData 스택의 맨 위의 데이터가 반한됩니다.
 * 
 * 배열리스트 꼬리 삭제 함수를 이용합니다.
 */
SData SPop(Stack * pStack){

    if (SIsEmpty(pStack)) {
        printf("Stack is Empty! ContainerEmptyException!");
        assert(! SIsEmpty(pStack));
    }

    SData ret = LRemoveTail(pStack);
    return ret;
}

/**
 * 스택에서 가장 위의 데이터를 확인합니다.
 * @param pStack Stack * 스택의 주소를 받습니다.
 * 
 * return SData 스택의 맨 위의 데이터가 반한됩니다. 삭제가 아닙니다.
 * 
 * 배열리스트에서 크기-1 요소를 반환하면 됩니다.
 */
SData SPeek(Stack * pStack){

    if (SIsEmpty(pStack)) {
        printf("Stack is Empty! ContainerEmptyException!");
        assert(! SIsEmpty(pStack));
    }

    int size = LSize(pStack);
    SData ret = LGet(pStack, size-1);
    return ret;
}


