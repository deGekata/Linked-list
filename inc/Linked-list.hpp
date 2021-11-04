#ifndef INC_LINKED_LIST
#define INC_LINKED_LIST

#include "Linker.hpp"
#include "stdio.h"
typedef int List_type;



struct Linked_list {
    size_t size, capacity;
    Linker* next;
    Linker* free_data;
    List_type* data;
};


void ctor_list(Linked_list* list);

void dtor_list(Linked_list* list);


void push_back_list(Linked_list* list, List_type val);

void push_front_list(Linked_list* list, List_type val);

List_type pop_back_list(Linked_list* list);

List_type pop_front_list(Linked_list* list);

List_type back_list(Linked_list* list);

List_type front_list(Linked_list* list);

#endif