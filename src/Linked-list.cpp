#include "../inc/Linked-list.hpp"

void ctor_list(Linked_list* list) {
    assert(list && "list must not be NULL");
    
    list->capacity = base_list_size;
    list->size = 0;
    list->data = (List_type*) safe_calloc(list->capacity, sizeof(*list->data));
    printf("Line %d\n", __LINE__);

    list->next = (Linker*) safe_calloc(1, sizeof(*list->next));
    ctor_linker(list->next);

    list->free_data = (Linker*) safe_calloc(1, sizeof(*list->free_data));
    ctor_linker(list->free_data);

    printf("Line %d\n", __LINE__);

    for(size_t it = 1; it < list->capacity; ++it) {
        list->next->links[it] = -1;
        list->free_data->links[it] = it + 1;
    }
    list->free_data->links[list->capacity - 1] = 0;

    printf("Line %d\n", __LINE__);

    list->next->tail = list->next->head = 0;    
    list->free_data->tail = 1;
    list->free_data->head =  list->capacity - 1;
    
    printf("Line %d\n", __LINE__);

    return;
}


void dtor_list(Linked_list* list) {
    assert(list && "List must not be empty");

    dtor_linker(list->next);
    dtor_linker(list->free_data);
    
    free(list->data);

    list->size = list->capacity = 0;

    return;
}


void push_front_list(Linked_list* list, List_type val) {
    assert(list && "List must not be NULL");

    if (list->size == list->capacity) {
        //realloc
    }

    int n_elem_pos = pop_front_linker(list->free_data);
    
    

    return;
}

// void push_back_list(Linked_list* list, List_type val);

// List_type pop_front_list(Linked_list* list);

// List_type pop_back_list(Linked_list* list);

// List_type back_list(Linked_list* list);

// List_type front_list(Linked_list* list);
