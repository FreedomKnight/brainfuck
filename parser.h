#ifndef PARSER_H
#define PARSER_H
#ifdef __cplusplus
extern "C" {
#endif

#define TOTAL_INSTR 8
#include "vm.h"

unsigned int code_size(byte *code);
byte *parser(void);

#ifdef __cplusplus
}
#endif
#endif


