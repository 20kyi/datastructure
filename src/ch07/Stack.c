#include<stdio.h>
#include<assert.h>

#include "Stack.h"

void SInit(Stack * pStack){
    LInit(pStack);
}

void SDestroy(Stack * pStack){
    LDestroy(pStack);
}

int SIsEmpty(Stack * pStack){
    return ( LSize(pStack) == 0 );
}

void SPush(Stack * pStack, SData data){
    LInsertTail(pStack, data);
}

SData SPop(Stack * pStack){

    if (SIsEmpty(pStack)) {
        printf("Stack is Empty! ContainerEmptyException!");
        assert(! SIsEmpty(pStack));
    }

    SData ret = LRemoveTail(pStack);
    return ret;
}

SData SPeek(Stack * pStack){
    int size = LSize(pStack);
    SData ret = LGet(pStack, size-1);
    return ret;
}


