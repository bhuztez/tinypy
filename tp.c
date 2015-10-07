#ifndef TP_COMPILER
#define TP_COMPILER 1
#endif

#include "tp.h"
#include "list.c"
#include "dict.c"
#include "misc.c"
#include "string.c"
#include "builtins.c"
#include "gc.c"
#include "ops.c"
void tp_compiler(TP);
#include "vm.c"

tp_obj tp_None = {TP_NONE};

#if TP_COMPILER
extern char _binary_tokenize_tpc_start[];
extern char _binary_parse_tpc_start[];
extern char _binary_encode_tpc_start[];
extern char _binary_py2bc_tpc_start[];

void tp_compiler(TP) {
    tp_import(tp,0,"tokenize",_binary_tokenize_tpc_start);
    tp_import(tp,0,"parse",_binary_parse_tpc_start);
    tp_import(tp,0,"encode",_binary_encode_tpc_start);
    tp_import(tp,0,"py2bc",_binary_py2bc_tpc_start);
    tp_call(tp,"py2bc","_init",tp_None);
}
#else
void tp_compiler(TP) { }
#endif

/**/
