#include "../inc/Linked-list.hpp"


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
    printf("data: ");
    for(size_t it = 0; it < list.capacity; ++it) {
        printf("%3d ", list.data[it]);
    }
    printf("\n");
    for(size_t it = 0; it < list.capacity; ++it) {
        printf("%7d %3d %3d \n", list.data[it].elem, list.data[it].next, list.data[it].prev);
    }
    printf("\n");
    printf("\n");
    printf(" tail :%d  head: %d  free_tail %d \n\n", list.tail, list.head, list.free_tail);


    // pop_front_list(&list);
    // for(size_t it = 0; it < list.capacity; ++it) {
    //     printf("%7d %3d %3d \n", list.data[it].elem, list.data[it].next, list.data[it].prev);
    // }
    // printf("\n");
    // printf("\n");
    // printf(" tail :%d  head: %d  free_tail %d \n\n", list.tail, list.head, list.free_tail);

    // pop_front_list(&list);
    // for(size_t it = 0; it < list.capacity; ++it) {
    //     printf("%7d %3d %3d \n", list.data[it].elem, list.data[it].next, list.data[it].prev);
    // }
    // printf("\n");
    // printf("\n");
    // printf(" tail :%d  head: %d  free_tail %d \n\n", list.tail, list.head, list.free_tail);


    // pop_back_list(&list);
    // for(size_t it = 0; it < list.capacity; ++it) {
    //     printf("%7d %3d %3d \n", list.data[it].elem, list.data[it].next, list.data[it].prev);
    // }
    // printf("\n");
    // printf("\n");
    // printf(" tail :%d  head: %d  free_tail %d \n\n", list.tail, list.head, list.free_tail);


    dtor_list(&list);
    
    return 0;
}