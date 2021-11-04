#include "../inc/tools.hpp"

void* safe_calloc(size_t _Count, size_t _Size) {
    void* ret_ptr = calloc(_Count, _Size);
    assert(ret_ptr && "Not enough memory to allocate data");
    return ret_ptr;
}

void safe_realloc(void** _Block, size_t _Size) {
    void* ret_ptr = realloc(*_Block, _Size);
    assert(ret_ptr && "Not enough memory to reallocate data");
    *_Block = ret_ptr;
}

