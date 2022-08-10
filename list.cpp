#include<iostream>
struct list
{  
    int data;
    struct list *next;
};

struct list *search_tails(struct list *searched_list , int number){//最後尾のlistまでたどる
    struct list *tmp = NULL;
    for(int i=0;i<number;i++){
    tmp = searched_list->next;
    searched_list = tmp->next;
    }
    return searched_list;
}
void set_list(struct list *previous_list){//新しくlistを作る
    previous_list->next = new list;
}
void delete_list(struct list *delete_list){//listをけす
    delete delete_list;
}

int main(){
    int data_size;
    struct list *first_list , *main_list ;
    std::cin >> data_size ;
    //listを指定した数だけ呼び出す
    for(int i=0;i<data_size;i++){
        main_list = search_tails(first_list , data_size);
        set_list(main_list);
    }
    first_list->data = 1;//整数をセット
    for(int i=0;i<data_size;i++){
        main_list = search_tails(first_list);
        main_list->data = i+1;
    }
    for(int i=0;i<data_size;i++){//整数を表示
        main_list = search_tails(first_list);
        std::cout << main_list->data << std::endl;
    }
    for(int i=0;i<data_size;i++){//作ったlistを消す
        main_list = search_tails(first_list);
        delete_list(main_list);
    }
}