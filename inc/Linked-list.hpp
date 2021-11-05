#ifndef INC_LINKED_LIST
#define INC_LINKED_LIST

#include "stdio.h"
#include <assert.h>
#include <stdlib.h>
#include "tools.hpp"

size_t const base_list_size = 8; 

typedef int List_type;

struct ListNode {
    List_type elem;
    int next, prev;
};

struct LinkedList {
    size_t size, capacity;
    int head, tail, free_tail;
    ListNode* data;
};


void ctor_list(LinkedList* list);

void dtor_list(LinkedList* list);


void push_back_list(LinkedList* list, List_type val);

void push_front_list(LinkedList* list, List_type val);

List_type pop_back_list(LinkedList* list);

List_type pop_front_list(LinkedList* list);

List_type back_list(LinkedList* list);

List_type front_list(LinkedList* list);

#endif