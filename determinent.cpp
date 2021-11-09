#include <bits/stdc++.h>

double residual_factors(std::vector<std::vector<double>> &value){
    double answer=0;
    int count1=0 , size_2=value.size();
    std::vector<std::vector<double>> residual(size_2-1,std::vector<double>(size_2-1));
    if(size_2==2){//２×２
        answer=value.at(0).at(0)*value.at(1).at(1)-value.at(0).at(1)*value.at(1).at(0);
    }else{
        for(int count=0;count<size_2;count++){//(count,1の余因子）
            for(int i=0;i<size_2;i++){//余因子を作る
                if(i==count){
                    continue;
                }else{
                    for(int j=0;j<size_2-1;j++){
                        residual.at(count1).at(j)=value.at(i).at(j+1);
                    }
                    count1++;
                }//余因子の行
            }
        count1=0;
        if(count%2==0){
        answer+=value.at(count).at(0)*residual_factors(residual);//余因子渡して受け取った値足す
        }else{
        answer-=value.at(count).at(0)*residual_factors(residual);//余因子渡して受け取った値足す
        }
        }
        }
    return answer;
}
int main(){
    int size_1 , i ,j ;
    std::cin >> size_1 ;
    std::vector<std::vector<double>>gyouretu(size_1,std::vector<double>(size_1,0));
    for(i=0;i<size_1;i++){
       for(j=0;j<size_1;j++){
           std::cin >> gyouretu.at(i).at(j);
       }
       std::cout << i+1 << "行目終了" << std::endl;
    }//入力終了 
    std::cout << "答え" << residual_factors(gyouretu) << std::endl;
    }