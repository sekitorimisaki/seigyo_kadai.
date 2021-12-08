#include<iostream>

class test
{
    public:
        std::string set(int num);
        void FizzBuzz(void);
    private:
        int num , fizzbuzz;
        std::string result ;
        
};

std::string test::set(int set){
    num = set;
    FizzBuzz();
    return result;
}
void test::FizzBuzz(void){
    if(num % 3 == 0){
        result += "Fizz";
    }
    if(num % 5 == 0){
        result += "Buzz";
    }
}

int main(){
    int a;
    std::string result;
    std::cin >> a;
    test obj;
    std::cout << obj.set(a) << std::endl;
    return 0;
}