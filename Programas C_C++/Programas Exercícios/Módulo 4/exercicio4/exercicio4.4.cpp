#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int> &v, int value){

    int first = 0,last = v.size()-1,middle;
    bool found = false;

    while(found == false && first <= last){
        middle = (first + last)/ 2;

        if (v.at(middle)==value){
            found = true;
        }
        else if (v.at(middle)>value){
            last = middle -1;
        }
        else{
            first = middle +1;
        }  
    }
    if (found){
        return middle;
    }
    else{
        return -1;
    }

    
}

int main(){

    vector<int> v1(6);
    v1.at(0) = 10; 
    v1.at(1) = 20; 
    v1.at(2) = 30;
    v1.at(3) = 40; 
    v1.at(4) = 50;
    v1.at(5) = 60;

    cout << binarySearch(v1,10);

    return 0;
}



