#ifndef VM_H
#define VM_H
#define DEFAULT_MEMSIZE 4096
#include "bf.h"
typedef enum Command {
    UNKNOWN, LEFT, RIGHT, INC, SUB, IN, OUT, LOOP_COND, LOOP_END
} Command;

typedef unsigned char byte;
typedef struct VM {
    byte *data_phy_head;
    byte *data_start;
    int data_cur;
    byte *code_phy_head;
    byte *code_start;
    byte *code_cur;
    unsigned int data_size;
    unsigned int data_phy_size;
    unsigned int code_size;
    unsigned int code_phy_size;
} VM;

VM *vm;
bool vm_init(void);
bool vm_execute(byte command);
byte get_data();
unsigned int get_pos();


#endif
