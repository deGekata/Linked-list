#include "../inc/Linked-list.hpp"

const size_t Max_out_file_len = 50;
const size_t Max_cmd_len  = 150;

const char* Img_dump_dir = "./dump/";

const char* Next_link_color = "blue";
const char* Prev_link_color = "red";
const char* Free_link_color = "orange";

void ctor_list(LinkedList* list) {
    assert(list && "list must not be NULL");
    
    if (list->data != NULL) {
        free(list->data);
    }
    
    list->data = (ListNode*) safe_calloc(Base_list_size, sizeof(ListNode));

    list->size = 0;
    list->capacity = Base_list_size;
    list->head = list->tail = 0;
    list->free_tail = 1;
    

    for (size_t it = 1; it < list->capacity - 1; ++it) {
        list->data[it].next = int(it + 1);
        list->data[it].prev = -1;
    }
    list->data[list->capacity - 1].prev = -1;

    list->data[list->capacity - 1].next = 0;

    list->is_sorted = false;

    return;
}

void dtor_list(LinkedList* list) {
    assert(list && "list must not be NULL");

    safe_free(list->data);
    list->head = list->tail = list->free_tail = -1;
    list->size = list->capacity = size_t(0);
    list->is_sorted = false;

    return;
}

void insert_list(LinkedList* list, int ind, List_type val) {
    assert(list && "List must not be NULL");
    assert(0 <= ind && size_t(ind) < list->capacity && "index out of range");
    assert(list->data[ind].prev != -1 && "item should be inserted after existing item");
    
    int n_elem_pos = pop_free_elem(list);
    list->data[n_elem_pos].elem = val;

    list->data[list->data[ind].next].prev = n_elem_pos;
    list->data[n_elem_pos].prev = ind;
    list->data[n_elem_pos].next = list->data[ind].next;
    list->data[ind].next = n_elem_pos;

    ++list->size;

    return;
} 

void erase_list(LinkedList* list, int ind) {
    assert(list && "List must not be NULL");
    assert(0 < ind && size_t(ind) < list->capacity && "index out of range");
    assert(list->data[ind].prev != -1 && "item must exist");

    list->data[ list->data[ind].prev ].next = list->data[ind].next;
    list->data[ list->data[ind].next ].prev = list->data[ind].prev;

    add_free_elem(list, ind);

    --list->size;
    
    return;
}

void sort_list(LinkedList* list) {
    assert(list);

    ListNode* buff = (ListNode*) safe_calloc(list->capacity, sizeof(ListNode));

    int item_ind = list->data[0].next;
    int offset = 1;
    
    while (item_ind != 0) {
        buff[offset].elem = list->data[item_ind].elem;
        buff[offset].prev = offset - 1;
        buff[offset].next = offset + 1;

        item_ind = list->data[item_ind].next;
        offset += 1;
    }

    buff[offset - 1].next = 0;
    buff[0].next = list->size > 0;
    buff[0].prev = offset - 1;
    
    if (list->size < (list->capacity - 1)) {
        item_ind = list->free_tail;
        list->free_tail = offset;

        while (item_ind != 0) {
            buff[offset].next = offset + 1;
            buff[offset].prev = -1;
            ++offset;
            item_ind = list->data[item_ind].next;
        }

        buff[list->capacity - 1].next = 0;
    }

    ListNode* temp = list->data;
    list->data = buff;
    free(temp);

    list->is_sorted = true;

    return;
}

List_type get_item_by_ind_dont_use_it_super_duper_extra_slow_slow_slow_function_when_list_is_not_sorted_ur_mom_is_gay_try_use_is_only_after_sorting_list_and_many_times_to_get_maximum_benefit_from_this_func(LinkedList* list, int ind) {
    assert(list && "List must not be NULL");
    assert(1 <= ind && size_t(ind) < list->size && "Index out of range");

    if (list->is_sorted) {
        return list->data[ind].elem;
    }

    int cur_ind = 0;

    for(int it = 0; it < ind; ++it) {
        cur_ind =  list->data[cur_ind].next;
    }

    return list->data[cur_ind].elem;
}

void realloc_list(LinkedList* list) {
    assert(list && "list ptr must not be null");

    safe_realloc((void**)&list->data, (list->capacity * Base_realloc_coeff)*sizeof(ListNode) );

    size_t prev_capacity = list->capacity;
    list->capacity = list->capacity * 2;
    for (size_t it = prev_capacity; it < list->capacity; ++it) {
        add_free_elem(list, int(it));
    }    

    return;
}

void printlist(LinkedList* list) {
    printf("   data: next:   :prev");
    printf("\n");
    for(size_t it = 0; it < list->capacity; ++it) {
        printf("%2zu %7d %3d %3d \n", it, list->data[it].elem, list->data[it].next, list->data[it].prev);
    }
    printf("\n");
    printf("\n");
    printf(" tail :%d  head: %d  free_tail %d \n\n", list->tail, list->head, list->free_tail);

}


void add_free_elem(LinkedList* list, int ind) {
    assert(list && "List must not be NULL");
    assert(0 < ind && size_t(ind) < list->capacity && "index out of range");

    list->data[ind].elem = 0;
    list->data[ind].prev = -1;

    if (list->free_tail == 0) {
        list->data[ind].next = 0; 
    } else {
        list->data[ind].next = list->free_tail;
    }

    list->free_tail = ind;

    return;
}

int pop_free_elem(LinkedList* list) {
    assert(list && "List must not be NULL");
    
    if (list->free_tail == 0) {
        realloc_list(list);
    }

    int n_elem_pos = list->free_tail;
    list->free_tail = list->data[n_elem_pos].next;
    return n_elem_pos;
}




int listCreateGraph(LinkedList* list) {
    
    static int nDump = 0;

    char filename[Max_out_file_len] = {};
    sprintf(filename, "%sLIST_DUMP_%d.dot", Img_dump_dir, nDump);

    FILE* file = fopen(filename, "w");

    fprintf(file,   "digraph G{\n");
    fprintf(file,   "   rankdir=LR;\n");
    fprintf(file,   "   splines=ortho;\n");
    fprintf(file,   "   nodesep=1;\n");
    fprintf(file,   "   F[shape=\"circle\", color=\"blue\", label=\"Free\"];\n");


    for(size_t node = 0; node < list->capacity; ++node){
        fprintf(file, "   L%lu[shape=\"record\", label=\" %lu | %d | {<lp%lu> %d | <ln%lu> %d}\"];\n", node, node, list->data[node].elem, node, list->data[node].prev, node, list->data[node].next);
    }

    for(size_t node = 0; node < list->capacity - 1; ++node){
        fprintf(file, "L%lu->L%lu[color=\"black\", weight=1000, style=\"invis\"];\n", node, node+1);
    }

    for(size_t node = 0; node < list->capacity; ++node){
        fprintf(file, "L%lu->L%d[color=\"%s\", constraint=false];\n", node,list->data[node].next, ((list->data[node].prev == -1) ? Free_link_color : Next_link_color ));
        if(list->data[node].prev != -1){
            fprintf(file, "L%lu->L%d[color=\"%s\", constraint=false];\n", node, list->data[node].prev, Prev_link_color);
        }
    }

    fprintf(file, "F->L%d[color=\"%s\"]", list->free_tail, Free_link_color);


    fprintf(file, "}");
    fclose(file);

    char command[Max_cmd_len] = {};

    sprintf(command, "dot %sLIST_DUMP_%d.dot -T png -o %sLIST_DUMP_%d.png", Img_dump_dir, nDump, Img_dump_dir, nDump);
    system(command);

    return nDump++;
}