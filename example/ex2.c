// #include "../cgc.h"
// #include <stdio.h>
// cgc gc;

// long f(long a, long b) { 
//     long sum = a+b;
//     int *c = cgc_alloc(&gc, sizeof(int));
//     return sum;
// }

// void *h(long a, long b) { 
//     long sum = a+b;
//     int *c = cgc_alloc(&gc, sizeof(int));
//     return c;
// }

// long g(long a, long b) {
//     long ret = f(a, b);
//     return ret;
// }
// // for debug
// int main(int argc, char **argv) {
//     // gc start!
//     cgc_start(&gc, *argv);

//     // g(4,5);
//     void *ad = h(3,4);
//     cgc_run(&gc);
//     cgc_end();
// }
