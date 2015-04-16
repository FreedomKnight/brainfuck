#include <stdlib.h>
#include <string.h>
#include "bf.h"
#include "vm.h"
#include "lexer.h"

byte ch2instr(char ch)
{
    Command instr = UNKNOWN; 
    switch (ch) {
    case '<':
        instr = LEFT;
        break;
    case '>':
        instr = RIGHT;
        break;
    case '+':
        instr = INC;
        break;
    case '-':
        instr = SUB;
        break;
    case ',':
        instr = IN;
        break;
    case '.':
        instr = OUT;
        break;
    case '[':
        instr = LOOP_COND;
        break;
    case ']':
        instr = LOOP_END;
        break;
    default:
        instr = UNKNOWN;
        break;
    }

    return (byte) instr;
}
    
unsigned int code_size(byte *code)
{
    unsigned int i = 0;
    while (code[i])
        i++;

    return i;
}

byte *parser() {
    byte *code = (byte *) malloc(sizeof(byte) * DEFAULT_MEMSIZE);
    char ch = '\0';
    int i = 0;
    memset(code, 0, sizeof(byte) * DEFAULT_MEMSIZE);
    while ((ch = get_instr_ch()) != EOF) {
        code[i] = ch2instr(ch);
        i++;
    }

    return code;
}

