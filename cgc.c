#include "cgc.h"
#include <stdlib.h>
#include <stdio.h>

static unsigned long int get_stackptr(cgc *gc) {
    unsigned long int rsp;
    asm volatile("mov %%rsp, %0" : "=r"(rsp));   
    if(rsp > (unsigned long int)gc->stack_init) {
        printf("invalid stack addr: rsp: 0x%08lx, stack_init: %p\n", rsp, gc->stack_init);
        exit(1);
    }
    return rsp;
}

static int cgc_sweep(cgc *gc) {
    for(int i = 0; i < gc->table_len; i++) {
        if (gc->tbl[i].marked_c < 2) {
            // debug
            printf("0x%08lx is used only by its own table(%d times). cgc will free.\n" ,gc->tbl[i].addr, gc->tbl->marked_c);
            free((void*)(gc->tbl[i].addr));
            gc->table_len--;
        }
    }
    return 0;
}

static int mark(cgc *gc, unsigned long int addr) {
    for(int i = 0; i < gc->table_len; i++) {
        if((*(unsigned long int*)addr) == gc->tbl[i].addr) {
            printf("addr: 0x%08lx, gc->tbl[i].addr; 0x%08lx\n", addr, gc->tbl[i].addr);
            printf("@@@@@@@@@@ 0x%08lx is in table (in address: 0x%08lx) @@@@@@@@@@@@\n", gc->tbl[i].addr, addr);
            // mark.
            gc->tbl[i].marked_c++;
            return 0;
        }
    }
    return 0;
}

static int cgc_mark(cgc *gc) {
    // get rsp.
    unsigned long int stack_ptr = get_stackptr(gc);

    // for debug.
    printf("mark stack ptr:            0x%08lx\n", stack_ptr);
    printf("initial(stack top) ptr   : 0x%08lx\n", (unsigned long int)gc->stack_init);

    for(unsigned long int i = stack_ptr; i < (unsigned long int)gc->stack_init; i++) {
        mark(gc, i);
    }
    return 0;
}

void cgc_start(cgc *gc, char *stack_init) {
    gc->stack_init = stack_init;
    gc->table_len = 0;
}

int cgc_end() {}

void cgc_run(cgc *gc) {
    cgc_mark(gc);
    cgc_sweep(gc);
}

void *cgc_alloc(cgc *gc, size_t size) {
    void *addr = calloc(1, size);
    // debug.
    printf("calloc adddr is 0x%08lx\n", (unsigned long int)(addr));
    table tbl = {
        addr: (unsigned long int)addr,
        size: size,
    };
    gc->tbl[gc->table_len] = tbl;
    gc->table_len++;
    return addr;
}