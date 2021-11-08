#include "../inc/Linked-list.hpp"
void printlist(LinkedList* list);

void printlist(LinkedList* list) {
    printf("data:   next: :prev");
    printf("\n");
    for(size_t it = 0; it < list->capacity; ++it) {
        printf("%2zu %7d %3d %3d \n", it, list->data[it].elem, list->data[it].next, list->data[it].prev);
    }
    printf("\n");
    printf("\n");
    printf(" tail :%d  head: %d  free_tail %d \n\n", list->tail, list->head, list->free_tail);

}

int main() {
    LinkedList list = {0};
    ctor_list(&list);

    for(size_t it = 0; it < list.capacity; ++it) {
        printf("%3d %3d %3d \n", list.data[it].elem, list.data[it].next, list.data[it].prev);
    }
    printf("\n");
    printf("\n");

    printf("\n");
    printf("\n");
    printf("\n");
    push_back_list(&list, 510);
    push_back_list(&list, 103230);
    push_back_list(&list, 1053520);
    push_back_list(&list, 123);
    push_back_list(&list, 1236);
    push_front_list(&list, 111);
    // push_front_list(&list, 122);
    printlist(&list);

    pop_front_list(&list);
    pop_front_list(&list);
    pop_front_list(&list);
    
    printlist(&list);

    sort_list(&list);

    push_front_list(&list, 1);
    push_front_list(&list, 2);
    push_front_list(&list, 3);
    push_front_list(&list, 4);
    push_front_list(&list, 11);

    printlist(&list);

    

    printf("%d capacity %d size\n", list.capacity, list.size);
    
    dtor_list(&list);
    
    return 0;
}