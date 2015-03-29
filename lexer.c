#include <stdio.h>
#include <ctype.h>
#include "lexer.h"
#include "bf.h"

char instr_set[] = {
    '<', '>', '+', '-', ',', '.', '[', ']'
};

bool is_instr(char ch) {
    int i = 0;
    for (i = 0; i < TOTAL_INSTR; i++) {
        if (ch ==  instr_set[i])
            return true;
    } 

    return false;
}

char get_instr_ch() {
    char ch = '\0';
    do {
        ch = getc(in);
        if (ch == EOF)
            break;
    } while (isspace(ch) || !is_instr(ch));
    
    return ch;
}
    
