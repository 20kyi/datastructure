#ifndef  STACK_H
#define STACK_H

#include "ArrayList.h"

//배열 리스트의 데이터 타입을 스택의 데이터 타입으로 지정
typedef LData SData;

//배열 리스트를 스택으로 지정
typedef ArrayList Stack;

void SInit(Stack * pStack);
void SDestroy(Stack * pStack);

int SIsEmpty(Stack * pStack);
void SPush(Stack * pStack, SData data);
SData SPop(Stack * pStack);
SData SPeek(Stack * pStack);


#endif