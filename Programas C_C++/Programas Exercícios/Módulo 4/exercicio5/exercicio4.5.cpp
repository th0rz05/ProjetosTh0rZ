#include <iostream>
#include <vector>

using namespace std;

void removeDuplicates(vector<int> &v){
    for(int i=0;i < v.size();i++){
        for(int j=i+1; j<v.size(); j++){
            if (v.at(i) == v.at(j)){
                for (int k=j; k<v.size()-1; k++){
                    v.at(k)=v.at(k+1);
                }
                v.resize(v.size()-1);
                j--;
            }
        }
    }
}

int main(){

    vector<int> v1(6);
    v1.at(0) = 20; 
    v1.at(1) = 20; 
    v1.at(2) = 20;
    v1.at(3) = 40; 
    v1.at(4) = 30;
    v1.at(5) = 20;

    removeDuplicates(v1);

    for (size_t i = 0; i < v1.size( ); i++){
        cout << v1[i] << endl;
    }

    return 0;
}
