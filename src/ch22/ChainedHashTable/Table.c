#include <stdlib.h>
#include <stdio.h>

#include "Table.h"

void TBLInit(Table * pT, HashFunc * hash, KeyCompareFunc * compare) {
    for (int i=0; i<TABLE_LENGTH; i++) {
        LInit( &(pT->table[i]) );
    }

    pT->hash = hash;
    pT->compare = compare;
}

void TBLDestroy(Table * pT) {
    for (int i=0; i<TABLE_LENGTH; i++) {
        LDestroy( &(pT->table[i]) );
    }

    pT->hash = NULL;
    pT->compare = NULL;
}

void TBLInsert(Table *pT, Key k, Value v) {
    Slot * new = (Slot *) malloc( sizeof(Slot) );
    new->key = k;
    new->value = v;

    int hash = pT->hash(k);
    List * chain = &(pT->table[hash]);
    int size = LSize(chain);

    // 해당 키를 가지고 있지 않다면, 추가
    if (!TBLSearch(pT, k)) {
        LInsertTail(chain, new);  
        return;
    } 

    //해당 키를 가지고 있으면, 업데이트
    for (int i=0; i<size; i++) {
        Slot * data = (Slot *) LGet(chain, i);
        
        if (pT->compare(k, data->key) == 0) {
            data->value = v;
            return;
        }
    }
}

Value TBLDelete(Table * pT, Key k) {
    if (!TBLSearch(pT, k)) {
        return NULL;
    }

    Value ret = NULL;
    int hash = pT->hash(k);
    List * chain = &(pT->table[hash]);
    int size = LSize(chain);
    
    for (int i=0; i<size; i++) {
        Slot * data = (Slot *) LGet(chain, i);
        
        if (pT->compare(k, data->key) == 0) {
            Slot * remove = (Slot *) LRemoveIndex(chain, i);
            ret = remove->value;
            free(remove);
            break;
        }
    }

    return ret;
}

int TBLSearch(Table * pT, Key k) {
    int hash = pT->hash(k);
    List * chain = &(pT->table[hash]);
    int size = LSize(chain);

    for (int i=0; i<size; i++) {
        
        Slot * data = (Slot *) LGet(chain, i);
        
        if (pT->compare(k, data->key) == 0) {
            return 1;
        }
    }
    
    return 0;
}
