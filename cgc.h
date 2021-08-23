#include <stdlib.h>

typedef struct table table;
typedef struct cgc cgc;

struct table {
    unsigned long int addr;
    size_t size; 
    int marked_c;
};

struct cgc {
    char *stack_init;
    table tbl[10000]; // TODO: データ構造工夫する
    int table_len;
};

void cgc_start();
void cgc_run();
void *cgc_alloc();
int cgc_end();

