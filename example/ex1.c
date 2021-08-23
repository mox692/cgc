#include "../cgc.h"
#include <stdio.h>

void f(cgc *gc) { 
    int *b = cgc_alloc(gc, sizeof(int));
}

// To make rsp lower at cgc_alloc call, use g() in this example.
int g(cgc *gc, long a, long b) {
    f(gc);
    return a + b;
}

int main(int argc, char **argv) {
    cgc gc;
    // gc start.
    cgc_start(&gc, *argv);

    g(&gc,4,5);

    // Run cgc, and this operation will free f()'s local variable b,
    // because b's address is no longer refered by any address.
    cgc_run(&gc);

    cgc_end();
}
