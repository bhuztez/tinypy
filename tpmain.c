#include "tp.c"
/* INCLUDE */

extern char _binary_example_py_start[];
extern char _binary_example_py_size[];

int main(int argc, char *argv[]) {
    tp_vm *tp = tp_init(argc,argv);
    /* INIT */
    tp_string_ s = {TP_STRING, 0, _binary_example_py_start, 0};
    s.len = (int)_binary_example_py_size;
    tp_obj val = {.string = s};
    tp_call(tp,"py2bc","tinypy", tp_params_v(tp,1, val));

    tp_deinit(tp);
    return(0);
}

/**/
