#ifndef __TABLE_H__
#define __TABLE_H__

#include "Slot.h"
#include "DoubleLinkedList.h"

#define TABLE_LENGTH 100

typedef int HashFunc(Key key);
typedef int KeyCompareFunc(Key k1, Key k2);

typedef struct _table{
    List table[TABLE_LENGTH];
    HashFunc * hash;
    KeyCompareFunc * compare;
} Table;

void TBLInit(Table * pT, HashFunc * hash, KeyCompareFunc * compare);
void TBLInsert(Table *pT, Key k, Value v);
Value TBLDelete(Table * pT, Key k);
int TBLSearch(Table * pT, Key k); 
void TBLDestroy(Table * pT);

#endif // !__TABLE_H__