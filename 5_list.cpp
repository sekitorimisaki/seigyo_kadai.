#include <iostream>
struct list
{
    int data;
    struct list *next;
    struct list *previous;
};
struct list *create_list(struct list *create ,int value){
    struct list *tmp = new list;
    tmp->data = value;
    tmp->next = nullptr;
    tmp->previous = create;
    create->next = tmp;
    return create->next;
}
void print_list(struct list *print_list , struct list *tail_list){
    while (print_list!=tail_list)
    {
        std::cout << print_list->data;
        print_list = print_list->next;
    }
}
void delete_list(struct list *delete_list , struct list *tail_list){
    struct list *tmp;
    while(delete_list!=tail_list){
        tmp = delete_list->next;
        delete delete_list;  
        delete_list = tmp;
    }
}
int main(){
    int data_size = 0;
    std::cin>>data_size;
    struct list *tmp;
    struct list *main_list;
    struct list *first_list = new list;
    first_list->data =1;
    main_list = first_list;
    for(int i=0;i<data_size;i++){
        tmp = create_list(main_list ,i+2);
        main_list = tmp;
    }
    print_list(first_list , main_list);
    delete_list(first_list,tmp);
}