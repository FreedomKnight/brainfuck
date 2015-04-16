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
    vm->data_head = vm->data_memory;
    vm->data_cur = vm->data_head;
    vm->data_size = DEFAULT_MEMSIZE;
    return true;
}

byte *vm_expend_data_mem(byte* memory) {
   byte *new_memory = realloc(memory, vm->data_size += DEFAULT_MEMSIZE); 
   if (new_memory != memory)
       free(memory);

   return new_memory;
}

unsigned int get_pos()
{
    return vm->data_cur - vm->data_head;
}


byte get_cur()
{
    return *(vm->data_cur);
}

bool vm_shift(int step)
{
    if (vm->data_cur + step < vm->data_head) {
        return false;
    } else if (vm->data_cur + step > vm->data_head + vm->data_size) {
        vm->data_memory = vm_expend_data_mem(vm->data_memory);
    }

    vm->data_cur += step;
    return true;
}

bool vm_execute(byte command)
{
    switch (command) {
    case LEFT:
        vm_shift(-1);
        break;
    case RIGHT:
        vm_shift(+1);
        break;
    case INC:
        (*(vm->data_cur))++;
        break;
    case SUB:
        (*(vm->data_cur))--;
        break;
    default:
        break;
    }

    return true;
}
