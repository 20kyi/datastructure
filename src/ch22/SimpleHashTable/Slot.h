#ifndef __SLOT_H__
#define __SLOT_H__

typedef void * Key;
typedef void * Value;

enum SlotStatus {EMPTY, DELETED, INUSE};

typedef struct _slot {
    Key key;
    Value value;
    enum SlotStatus status;
}Slot;


#endif // !__SLOT_H__
