#include <stdlib.h>
#include "lexer.h"
#include "vm.h"

int main(int argc, char** argv)
{
    if (argc <= 1) {
        in = stdin;
        out = stdout;
    } else if (argc == 2) {
        in = fopen(argv[1], "r");
        out = stdout;
    }

    vm_init();
    printf("%c\n", get_instr_ch());
    exit(0);
}
