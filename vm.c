#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "vm.h"

bool vm_init(void)
{
    vm = (VM *) malloc(sizeof(VM));
    memset(vm, 0, sizeof(VM));
    vm->data_memory = (byte *) malloc(sizeof(byte) * DEFAULT_MEMSIZE);
    memset(vm->data_memory, 0, sizeof(byte) * DEFAULT_MEMSIZE);
    vm->head = vm->data_memory;
    vm->cur = vm->head;
    vm->size = DEFAULT_MEMSIZE;
    return true;
}

byte *vm_expend_memory(byte* memory, unsigned int size) {
   byte *new_memory = realloc(memory, size); 
}

bool vm_shift(int step)
{
    if (vm->cur + step < 0) {
        return false;
    } else if (vm->cur + step 
    return true;
}

bool vm_execute(byte command) {
    switch (command) {
    case LEFT:
        vm_shift(-1);
        break;
    default:
        break;
    }
    return true;
}
