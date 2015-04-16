#include <stdlib.h>
#include "lexer.h"
#include "parser.h"
#include "vm.h"

int main(int argc, char** argv)
{
    int i = 0;
    byte *code = NULL;
    if (argc <= 1) {
        in = stdin;
        out = stdout;
    } else if (argc == 2) {
        in = fopen(argv[1], "r");
        out = stdout;
    }

    vm_init();
    code = parser();

    i = 0;
    for (i = 0; i < code_size(code); i++) {
        printf("instr: %d pos: %d data: %d\n", code[i], get_cur());
        vm_execute(code[i]);
    }
    exit(0);
}
