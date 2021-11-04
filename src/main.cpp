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

    printf("%d ret_val\n", pop_front_linker(list.free_data));
    printf("%d ret_val\n", pop_front_linker(list.free_data));
    printf("%d ret_val\n", pop_front_linker(list.free_data));
    for(size_t it = 0; it < list.capacity; ++it) {
        printf("%3d ", list.free_data->links[it]);
    }
    printf("\n");
    dtor_list(&list);
    
    return 0;
}