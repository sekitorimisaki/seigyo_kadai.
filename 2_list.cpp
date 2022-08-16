#include <iostream>
struct list
{
    int data;
    struct list *next;
    // struct list *previous;
};
struct list *search_tails(struct list *searched_list)
{ //最後尾のlistまでたどる
    struct list *tmp ;
            int i = 0;
    while (1){
        if(searched_list->next == NULL)break;
        tmp = searched_list->next;
        searched_list = tmp;
        i++;
        std::cout<<"aa";
    }
    return searched_list;
}
struct list *tukuru(struct list *tukuru_list , int count){
    struct list *tmp;
    tukuru_list->next = new list;
    tmp = tukuru_list->next;
    tmp->data = count;
    tmp->next = NULL;
    std::cout<<"tukutta";
    return tmp;
}
void kesu(struct list *kesu_list)
{
    std::cout << "delete";
    delete kesu_list;
}
int main()
{
    int data_size = 2;
    struct list *first_list;
    struct list *main_list;
    struct list *tmp;
    // first_list->next = new list;
    // main_list = first_list;
    // delete main_list;
    first_list->next = NULL;
    // listを指定した数だけ呼び出す
    for (int i = 0; i < data_size; i++){
        tmp = search_tails(first_list);
        tmp = tukuru(tmp, i);
        std::cout <<i <<"愁";
    }
    for (int i = 0; i < data_size; i++){ //作ったlistを消す
        tmp = search_tails(first_list);
        kesu(tmp);
    }
}
