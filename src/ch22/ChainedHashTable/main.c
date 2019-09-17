#include <stdio.h>

#include "Table.h"

int hashFunc(Key key) {
    int k = *((int *) key);
    return k % TABLE_LENGTH;
}

int keyCompareFunc(Key key1, Key key2) {
    int k1 = *((int *) key1);
    int k2 = *((int *) key2);
    return k1-k2;
}


void showData(Table * pT) {
    for (int i=0; i<TABLE_LENGTH; i++) {
        List * chain = &(pT->table[i]);
        int size = LSize(chain);

        if (size <= 0) {
            continue;
        }

        printf("%d: ", i);
        for (int j=0; j<size; j++) {
            Slot * data = LGet(chain, j);
            int k = *((int *) data->key);
            char * v = *((char **) data->value);
            printf("{%d : %s} ", k, v);
        }
        printf("\n");
    }
}

int main() {
    Table table;
    TBLInit(&table, hashFunc, keyCompareFunc);

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
        printf("%s\n", *value);
    }

    showData(&table);

    TBLDestroy(&table);
    return 0;
}