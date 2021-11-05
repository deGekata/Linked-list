#include "../inc/Linker.hpp"


bool is_empty(Linker* linker);

void ctor_linker(Linker* linker) {
    assert(linker && "Linker ptr must not be NULL");

    linker->links = (int*) safe_calloc(base_list_size, sizeof(int));
    linker->tail = linker->head = 0;

    return;
}

void dtor_linker(Linker* linker) {
    assert(linker && "Linker must not be NULL");
    assert(linker->links && "Linker links must not be empty");

    free(linker->links);
    return;
}

int pop_front_linker(Linker* linker) {
    assert(linker && "Linker must not be NULL");

    int ret_val;

    if (linker->tail == 0) {
        return -1;
    }
    
    ret_val = linker->tail;

    linker->head = linker->head == linker->tail ? 0 : linker->head;
    linker->tail = linker->links[linker->tail];
    linker->links[ret_val] = -1;

    return ret_val;
}

