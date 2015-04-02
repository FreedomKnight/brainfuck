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

    while (code && *code) {
        printf("%d\n", code[i]);
        i++;
    }
    exit(0);
}
