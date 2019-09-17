#ifndef __SLOT_H__
#define __SLOT_H__

typedef void * Key;
typedef void * Value;

typedef struct _slot {
    Key key;
    Value value;
}Slot;


#endif // !__SLOT_H__
