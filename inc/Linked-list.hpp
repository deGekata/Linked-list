#ifndef INC_LINKED_LIST
#define INC_LINKED_LIST

#include "stdio.h"
typedef int List_type;

struct ListNode {
    List_type elem;
    int next, prev;
};

struct LinkedList {
    size_t size, capacity;
    ListNode* data;
};


void ctor_list(LinkedList* list);

void dtor_list(LinkedList* list);


void push_back_list(LinkedList* list, LinkedList val);

void push_back_list(LinkedList* list, LinkedList val);

List_type pop_back_list(LinkedList* list);

List_type pop_front_list(LinkedList* list);

List_type back_list(LinkedList* list);

List_type front_list(LinkedList* list);

#endif