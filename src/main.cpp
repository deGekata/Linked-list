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


    insert_list(&list, 0, 111);
    insert_list(&list, 0, 222);
    insert_list(&list, 0, 333);
    insert_list(&list, 0, 444);
    printlist(&list);
    printf("bef first list sort LINE:%d\n", __LINE__);
    sort_list(&list);
    printf("bef second list sort  LINE:%d\n", __LINE__);
    sort_list(&list);
    printf("after second list sort:%d\n", __LINE__);
    printlist(&list);
    sort_list(&list);

    printf("wtf\n");
    insert_list(&list, 2, 666);
    insert_list(&list, 2, 777);
    insert_list(&list, 2, 999);
    insert_list(&list, 2, 1000);
    insert_list(&list, 3, 993);
    insert_list(&list, 1, 191);
    printlist(&list);
    // sort_list(&list);
    listCreateGraph(&list);
    printlist(&list);
    sort_list(&list);
    listCreateGraph(&list);
    
    // printf("erase 222\n");

    // // erase_list(&list, 4);
    // sort_list(&list);
    // printf("%d log elem\n", get_item_by_ind_dont_use_it_super_duper_extra_slow_slow_slow_function_when_list_is_not_sorted_ur_mom_is_gay_try_use_is_only_after_sorting_list_and_many_times_to_get_maximum_benefit_from_this_func(&list, 3));
    // printlist(&list);
    // // erase_list(&list, 1);
    // // erase_list(&list, 2);
    // // erase_list(&list, 3);
    // // erase_list(&list, 4);
    
    // // printlist(&list);

    // // sort_list(&list);
    // // printlist(&list);
    // // realloc_list(&list);
    // printlist(&list);
    // printf("%zu capacity %zu size\n", list.capacity, list.size);
    // // listCreateGraph(&list);
    // // sort_list(&list);
    dtor_list(&list);
    
    return 0;
}