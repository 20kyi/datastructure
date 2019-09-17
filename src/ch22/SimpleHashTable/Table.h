#ifndef __TABLE_H__
#define __TABLE_H__

#include "Slot.h"

#define TABLE_LENGTH 10

typedef int HashFunc(Key key);

typedef struct _table{
    Slot table[TABLE_LENGTH];
    HashFunc * hash;
} Table;

void TBLInit(Table * pT, HashFunc * hash);
void TBLInsert(Table *pT, Key k, Value v);
Value TBLDelete(Table * pT, Key k);
int TBLSearch(Table * pT, Key k); 
void TBLDestroy(Table * pT);

#endif // !__TABLE_H__