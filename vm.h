#ifndef VM_H
#define VM_H
#define DEFAULT_MEMSIZE 4096 
#include "bf.h"
typedef enum Command {
    UNKNOWN, LEFT, RIGHT, INC, SUB, IN, OUT, LOOP_COND, LOOP_END
} Command;

typedef unsigned char byte;
typedef struct VM {
    byte *data_memory;
    byte *code_memory;
    byte *data_head;
    byte *data_cur;
    byte *code_head;
    byte *code_cur;
    unsigned int size;
} VM;

VM *vm;
bool vm_init(void);


#endif
