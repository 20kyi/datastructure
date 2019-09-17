#include <stdio.h>

#include "Table.h"

int hashFunc(Key key) {
    int k = *((int *) key);
    return k % TABLE_LENGTH;
}

void showData(Table * pT) {
    for (int i=0; i<TABLE_LENGTH; i++) {
        Slot * slot = &(pT->table[i]);
        int * key = (int *)(slot->key);
        char ** value = (char **)(slot->value);

        if (slot->status == EMPTY) {
            printf("%d: { '', '', EMPTY}\n", i);
        } else if (slot->status == INUSE) {
            printf("%d: { %d, %s, INUSE}\n", i, *key, *value);
        } else {
            printf("%d: { %d, %s, DELETED}\n", i, *key, *value);
        }
    }
    printf("\n\n");
}

int main() {
    Table table;
    TBLInit(&table, hashFunc);

    int keys[] = { 900524, 900139, 900827, 800524 };
    char * values[] = { "Lee", "Jang", "Kang", "Han" }; 

    for (int i=0; i<3; i++) {
        int * key = &keys[i];
        char ** value = &values[i];
        TBLInsert(&table, key, value);
    }

    showData(&table);

    char * str = "TEST";

    TBLInsert(&table, &keys[3], &values[3]);
    TBLInsert(&table, &keys[0], &str);

    showData(&table);

    for (int i=0; i<4; i++) {
        int * key = &keys[i];
        char ** value = &values[i];

        if (TBLSearch(&table, &keys[i])) {
            printf("%d : %s\n", *key, *value);
        }
    }

    for (int i=0; i<4; i++) {
        int * key = &keys[i];

        Value deleted = TBLDelete(&table, key);
        char ** value = (char **) deleted;
        
        if (value == NULL) {
            continue;
        }

        printf("%s\n", *value);
    }

    showData(&table);

    TBLDestroy(&table);
    return 0;
}