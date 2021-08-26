# cgc
A toy garbage collector for C.  
(Under experiment

### feature
* Using mark and sweep like algorithm.
* Manuel GC(start, alloc, run).
* Store object by `cgc_alloc()`, then scan all stack, heap and data segment  
pointer that pointing to object.

### TODO
* heap search.
* impl `cgc_end()`.
* optimisation of search loop.
* data segment search.

### Example
See `/example` directory.

### Reference
* [tgc](https://github.com/orangeduck/tgc)
* [gc](https://github.com/mkirchner/gc)
