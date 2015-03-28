#include <string.h>
#include <stdlib.h>
#include "vm.h"

bool vm_init(void)
{
    vm->memory = (byte *) malloc(sizeof(bypt) * MEMSIZE);
    memset(vm->memory, 0, sizeof(VM));
    vm->head = vm->memory;
    vm->cur = vm->head;
}

bool vm_shift(int step)
{
    if (
}

int vm_execute(byte command) {
    switch (command) {
    case LEFT:
        vm_shift(-1);
        break;
    default:
        break;
    }
}
