#include<iostream>

class stack{
    public:
        stack(){
        for(int i=0 ; i<10 ; i++){
            num[i]=-1;
        }
    }
        void command(char);
        void push(void);
        void pop(void);
        int kazoeru(void);
    private:
        int num[10];
        int i=0;
        int a;
        int count = 0;
};
    void stack::command(char command){
    if(command == 'u'){
        push();  
    }else if(command == 'o'){
        pop();
    }
    }
    void stack::push(void){
        i++;
        std::cin >> num[i];
    }
    void stack::pop(void){
        std::cout << num[i] << std::endl;
        num[i] = -1;
        i--;
    }
    int stack::kazoeru(void){
        return i;
    }

int main(){
    stack sta;
    char command;
    int kaisuu=0;
    while(kaisuu<11){
    std::cin >> command;
    sta.command(command);
    kaisuu=sta.kazoeru();
    }
    std::cout << "stack出来ません" << std::endl;
}