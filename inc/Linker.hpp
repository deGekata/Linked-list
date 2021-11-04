#ifndef INC_LINKER
#define INC_LINKER

#include "../inc/tools.hpp"

size_t const base_list_size = 30; 

struct Linker {
    int tail, head;
    int* links;
};

bool is_empty_linker(Linker* linker);

void ctor_linker(Linker* linker);

void dtor_linker(Linker* linker);

int pop_front_linker(Linker* linker);


#endif