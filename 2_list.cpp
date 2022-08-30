#include <iostream>
struct list
{
    int data;
    struct list *next;
    struct list *previous;
};
struct list *search_tails(struct list *searched_list)
{ //最後尾のlistまでたどる
    struct list *tmp = nullptr;
    int i = 0;
    while (searched_list->next != nullptr){
        searched_list = searched_list->next;
        std::cout << searched_list->data;
    }
    return searched_list;
}
void next_tukuru(struct list *tukuru_list , int count){
    struct list *tmp = new list;
    tmp->data = count+1;
    tmp->next = nullptr;
    tmp->previous = tukuru_list;
    tukuru_list->next = tmp;
}//データ入れられてない？
void list_print(struct list *print_list){
    struct list *tmp = nullptr;
    while (print_list!=nullptr)
    {
        std::cout<<"print"<<print_list->data;
        tmp = print_list->next;
        print_list = tmp;
    }
    
}
void kesu(struct list *kesu_list)
{
    delete kesu_list;
}
int main()
{
    int data_size = 3;
    struct list *main_list;
    struct list *tmp;
    // first_list->next = new list;
    // main_list = first_list;
    // delete main_list;
    struct  list *first_list = new list;
    first_list->next = nullptr;
    first_list->data = 0;
    first_list->previous = nullptr;
    // listを指定した数だけ呼び出す
    for (int i = 0; i < data_size; i++){
        next_tukuru(tmp, i);
        tmp = search_tails(first_list);
    }
    list_print(first_list);
    for (int i = 0; i < data_size; i++){ //作ったlistを消す
        tmp = search_tails(first_list);
        kesu(tmp);
    }
}
