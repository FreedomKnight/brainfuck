#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "vm.h"

#define CUR_DATA vm->data_start[vm->data_cur]

bool vm_init(void)
{
    vm = (VM *) calloc(1, sizeof(VM));
    vm->data_phy_head = (byte *) calloc(DEFAULT_MEMSIZE, sizeof(byte));
    vm->data_phy_size = DEFAULT_MEMSIZE;
    vm->data_start = vm->data_phy_head + (DEFAULT_MEMSIZE * 1 / 4);
    vm->data_size = DEFAULT_MEMSIZE / 2;
    vm->data_cur = 0;
    return true;
}

bool vm_expend_data_mem(byte** memory) {
    int i = 0, j = 0;
    unsigned int old_size = vm->data_phy_size;
    byte *old_memory = *memory;
    byte *new_memory = NULL;
    vm->data_phy_size *= 2;
    new_memory = (byte *) calloc(vm->data_phy_size, sizeof(byte));
    vm->data_size = vm->data_phy_size / 2;
    for (i = vm->data_phy_size * 1 / 4, j = old_size * 1 / 4; j < old_size; i++, j++)
        new_memory[i] = old_memory[j];

    for (i = vm->data_phy_size * 1 / 4, j = old_size * 1 / 4; old_memory + j < vm->data_start; i--, j--)
        new_memory[i] = old_memory[j];
        
    vm->data_start = new_memory + (vm->data_phy_size * 1 / 4);
    free(old_memory);
    *memory = new_memory;

    return true;
}

byte get_data()
{
    return vm->data_start[vm->data_cur];
}

unsigned int get_pos()
{
    return vm->data_cur;
}

bool vm_shift(int step)
{
    if (vm->data_start + vm->data_cur + step < vm->data_phy_head) {
        vm_expend_data_mem(&vm->data_phy_head);
    } else if (vm->data_cur + step > (int) vm->data_phy_size) {
        vm_expend_data_mem(&vm->data_phy_head);
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
        CUR_DATA++;
        break;
    case SUB:
        CUR_DATA--;
        break;
    case IN:
        CUR_DATA = getc(in);
        break;
    case OUT:
        putc(CUR_DATA, out);
        break;
    default:
        break;
    }

    return true;
}
