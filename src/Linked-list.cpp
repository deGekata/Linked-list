#include "../inc/Linked-list.hpp"

void ctor_list(LinkedList* list) {
    assert(list && "list must not be NULL");
    
    if (list->data != NULL) {
        free(list->data);
    }
    
    list->data = (ListNode*) safe_calloc(base_list_size, sizeof(*list->data));

    list->size = 0;
    list->capacity = base_list_size;
    list->head = list->tail = 0;
    list->free_tail = 1;

    for (size_t it = 1; it < list->capacity - 1; ++it) {
    list->data[it].next = it + 1;
        
    }

    list->data[list->capacity - 1].next = 0;

    return;
}


void dtor_list(LinkedList* list) {
    assert(list && "list must not be NULL");

    safe_free(list->data);
    list->head = list->tail = list->free_tail = list->size = list->capacity = -1;

    return;
}


void push_back_list(LinkedList* list, List_type val) {
    assert(list && "List must not be NULL");

    if (list->free_tail == 0) {
        //realloc
    }

    int n_elem_pos = list->free_tail;
    list->free_tail = list->data[n_elem_pos].next;
    list->data[n_elem_pos].elem = val;
    
    if (list->size >= 1) {
        list->data[ list->tail ].prev = n_elem_pos;
    }

    list->data[n_elem_pos].prev = 0;
    list->data[n_elem_pos].next = list->tail;
    list->tail = n_elem_pos;

    if (list->head == 0) list->head = n_elem_pos;
    
    list->size += 1;

    return;
}


List_type pop_back_list(LinkedList* list) {
    assert(list && "List must not be NULL");
    assert(list->size && "List is empty");

    if(list->data[ list->tail ].next != 0) {
        list->data[ list->data[ list->tail ].next ].prev = 0;
    }

    List_type ret_val;
    ret_val = list->data[ list->tail ].elem;
    list->data [ list->tail ].elem = 0;
    int prev_pos = list->tail;
    if (list->tail != list->head) {
        list->tail = list->data[ list->tail ].next;
    } else {
        list->tail = list->head = 0;
    }
    list->data[ prev_pos ].next = list->free_tail;
    list->free_tail = prev_pos;

    list->size -= 1;

    return ret_val;
}

List_type pop_front_list(LinkedList* list) {
    assert(list && "List must not be NULL");
    assert(list->size && "List is empty");

    if (list->data[list->head].prev != 0) {
        list->data[ list->data[ list->head ].prev ].next = 0;
    }

    List_type ret_val;
    ret_val = list->data[list->head].elem;
    list->data [ list->head ].elem = 0;
    int prev_pos = list->head;

    if (list->tail != list->head) {
        list->head = list->data[ list->head ].prev;
    } else {
        list->head = list->tail = 0;
    }

    list->data[ prev_pos ].next = list->free_tail;
    list->free_tail = prev_pos;

    list->size -= 1;

    return ret_val;
    

}

void push_front_list(LinkedList* list, List_type val) {
    assert(list && "List must not be NULL");

    if (list->free_tail == 0) {
        //realloc
    }

    int n_elem_pos = list->free_tail;
    list->free_tail = list->data[n_elem_pos].next;
    list->data[n_elem_pos].elem = val;
    
    if (list->size >= 1) {
        list->data[ list->head ].next = n_elem_pos;
    }

    list->data[n_elem_pos].next = 0;
    list->data[n_elem_pos].prev = list->head;
    list->head = n_elem_pos;

    if (list->tail == 0) list->tail = n_elem_pos;
    
    list->size += 1;

    return;
}


// List_type back_list(Linked_list* list);

// List_type front_list(Linked_list* list);
