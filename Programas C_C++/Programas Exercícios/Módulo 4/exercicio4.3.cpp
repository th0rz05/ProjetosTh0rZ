#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &v,char order){

    int tmp;
    if (order == 'a'){
        for (size_t i = 0; i < v.size()-2;i++){
            for (size_t j= 0;j<v.size()-(i+1);j++){
                if (v.at(j)>v.at(j+1)){
                    tmp = v.at(j);
                    v.at(j)=v.at(j+1);
                    v.at(j+1)= tmp;
                }
            }
        }
    }
    else{
        for (size_t i = 0; i < v.size()-2;i++){
            for (size_t j= 0;j<v.size()-(i+1);j++){
                if (v.at(j)<v.at(j+1)){
                    tmp = v.at(j);
                    v.at(j)=v.at(j+1);
                    v.at(j+1)= tmp;
                }
            }
        }
    }
    
}

int main(){

    vector<int> v1(6);
    v1.at(0) = 30; 
    v1.at(1) = 10; 
    v1.at(2) = 40;
    v1.at(3) = 20; 
    v1.at(4) = 5;
    v1.at(5) = 25;


    bubbleSort(v1,'d');

    for (size_t i = 0; i < v1.size( ); i++){
        cout << v1[i] << endl;
    }

    return 0;
}