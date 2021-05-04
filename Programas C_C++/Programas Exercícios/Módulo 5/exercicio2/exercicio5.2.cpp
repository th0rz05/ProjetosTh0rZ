#include <iostream>
#include <vector>
#include <string>

using namespace std;

void bubbleSort(vector<string> &v,char order){

    string tmp;
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

    vector<string> v1(6);
    v1.at(0) = "ola"; 
    v1.at(1) = "adeus"; 
    v1.at(2) = "fui";
    v1.at(3) = "Ola"; 
    v1.at(4) = "OVA";
    v1.at(5) = "adEus";


    bubbleSort(v1,'a');

    for (size_t i = 0; i < v1.size( ); i++){
        cout << v1.at(i) << endl;
    }

    return 0;
}