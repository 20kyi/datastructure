#include <stdlib.h>
#include <stdio.h>

#include "Table.h"

void TBLInit(Table * pT, HashFunc * hash) {
    for (int i=0; i<TABLE_LENGTH; i++) {
        (pT->table[i]).status = EMPTY;
    }

    pT->hash = hash;
}

void TBLDestroy(Table * pT) {
    for (int i=0; i<TABLE_LENGTH; i++) {
        (pT->table[i]).status = DELETED;
    }

    pT->hash = NULL;
}

void TBLInsert(Table *pT, Key k, Value v) {
    int hash = pT->hash(k);
    Slot * slot = &(pT->table[hash]);
    slot->key = k;
    slot->value = v;
    slot->status = INUSE;
}

Value TBLDelete(Table * pT, Key k) {
    if (!TBLSearch(pT, k)) {
        return NULL;
    }

    int hash = pT->hash(k);
    Slot * slot = &(pT->table[hash]);

    if (slot->status != INUSE) {
        return NULL;
    }

    slot->status = DELETED;
    return slot->value;
}

int TBLSearch(Table * pT, Key k) {
    int hash = pT->hash(k);
    Slot * slot = &(pT->table[hash]);
    return (slot->status == INUSE);
}
