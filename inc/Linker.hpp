#ifndef INC_LINKER
#define INC_LINKER

struct Linker {
    int tail, head;
    int* links;
};

bool is_empty(Linker* linker);

#endif