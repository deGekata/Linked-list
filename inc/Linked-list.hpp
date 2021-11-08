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
    bool is_sorted;
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

void sort_list(LinkedList* list);

// void get_item_by_ind(LinkedList* list, int ind);
List_type get_item_by_ind_dont_use_it_super_duper_extra_slow_slow_slow_function_when_list_is_not_sorted_ur_mom_is_gay_try_use_is_only_after_sorting_list_and_many_times_to_get_maximum_benefit_from_this_func(LinkedList* list, int ind);

void realloc_list(LinkedList* list, size_t n_capacity);


#endif