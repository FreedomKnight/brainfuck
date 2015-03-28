#ifndef VM_H
#define VM_H
#define MEMSIZE 1024000
#include "bf.h"
typedef enum Command {
    UNKNOWN, LEFT, RIGHT, INC, SUB, IN, OUT, LOOP_COND, LOOP_END
} Command;

typedef unsigned char byte;
typedef struct VM {
    byte *memory;
    byte *head;
    byte *cur;
} VM;

VM vm;
bool vm_init(void);


#endif
