#include <bits/stdc++.h>
using namespace std;

int main(){
    double b , irekae ;
    int i , n , j , size , fg=0 ;
    cin >> size ;
    vector<vector<double>> gausu(size,vector<double>(size+1,1));
    vector<double>ire(size,0);
    for( i=0 ; i<size ; i++ ){
        for( j=0 ; j<size+1 ; j++){
            cin >> gausu.at(i).at(j) ;
        }
        cout << i+1 << "行目終了" << endl;
    }
    for( n=0 ; n < size-1 ; n++){//ｎ番目の列を０にする
        for( i=n+1 ; i<size ; i++){//i番目の行を０にする
            b=gausu.at(i).at(n)/gausu.at(n).at(n);
            for(j=0 ; j<size+1 ; j++){//一つの行を引き算する
                gausu.at(i).at(j)=gausu.at(i).at(j)-b*gausu.at(n).at(j);
            }
            if(gausu.at(i).at(i)==0){
                ire.at(i)=1;
                for(int a=0;a<size;a++){
                    irekae=gausu.at(a).at(i);
                    gausu.at(a).at(i)=gausu.at(a).at(i+1);
                    gausu.at(a).at(i+1)=irekae;
                }
            }
        }
    }
    for(n=size-1 ; n >= 0 ; n--){//ｎ番目の列を０にする
        for(i=n-1 ; i >= 0 ; i--){//i番目の行を０にする
            b=gausu.at(i).at(n)/gausu.at(n).at(n);
            for(j=0 ; j<size+1 ; j++){//一つの行を引き算する
                gausu.at(i).at(j)=gausu.at(i).at(j)-b*gausu.at(n).at(j);
            }
        }
    }
    
        for(i=0;i<size;i++){
            b=gausu.at(i).at(i);
            for(j=0;j<size+1;j++){
                gausu.at(i).at(j)=gausu.at(i).at(j)/b;
            }
        }
    for(i=0 ; i<size ; i++){
        if(ire.at(i)==1){
            irekae=gausu.at(i).at(size);
            gausu.at(i).at(size)=gausu.at(i+1).at(size);
            gausu.at(i+1).at(size)=irekae;
        }
        cout << '\n' << 'x' << i+1 << '=' << gausu.at(i).at(size) ;
    }
    
}