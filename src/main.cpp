#include "../inc/Linked-list.hpp"


int main() {
    Linked_list list = {0};
    ctor_list(&list);

    for(size_t it = 0; it < list.capacity; ++it) {
        printf("%3d ", list.next->links[it]);
    }
    printf("\n");
    for(size_t it = 0; it < list.capacity; ++it) {
        printf("%3d ", list.free_data->links[it]);
    }
    printf("\n");

    printf("\n");
    printf("\n");
    printf("\n");
    push_back_list(&list, 510);
    push_back_list(&list, 103230);
    push_back_list(&list, 1053520);
    push_back_list(&list, 123);
    printf("data: ");
    for(size_t it = 0; it < list.capacity; ++it) {
        printf("%3d ", list.data[it]);
    }
    printf("\n");
    printf("next: ");
    for(size_t it = 0; it < list.capacity; ++it) {
        printf("%3d ", list.next->links[it]);
    }
    printf("\n");
    printf("prev: ");
    for(size_t it = 0; it < list.capacity; ++it) {
        printf("%3d ", list.prev->links[it]);
    }
    printf("\n");
    printf("free: ");
    for(size_t it = 0; it < list.capacity; ++it) {
        printf("%3d ", list.free_data->links[it]);
    }
    printf("\n");
    printf("next tail :%d  head: %d\n\n", list.next->tail, list.next->head);
    printf("free tail :%d  head: %d\n\n", list.free_data->tail, list.free_data->head);
    dtor_list(&list);
    
    return 0;
}