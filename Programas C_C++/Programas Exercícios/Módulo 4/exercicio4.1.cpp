

#include <iostream>

using namespace std;

void readArray(int a[], size_t nElem){
    // reads an array

    for (size_t i = 0 ; i < nElem;i++){
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

int findValueInArray(const int a[], size_t nElem, int value, size_t pos1 , size_t pos2 ){
    //finds a value between 2 index

    for (size_t i = pos1; i <= pos2;i++){
        if (a[i]==value){
            return i;
        }
        if (i==nElem){
            break;
        }
    }
    return -1;
}

size_t findMultValuesInArray(const int a[], size_t nElem, int value, size_t pos1, size_t pos2, size_t index[]){
    //finds a value between 2 index and returns the nr of ocurrences

    int ix=0;

    for (size_t i = pos1; i <= pos2;i++){
        if (a[i]==value){
            index[ix]=value;
            ix++;
        }
        if (i==nElem){
            break;
        }
    }

    return ix;
}

int main(){

    int NumElem,value;
    int* a;
    size_t* ix;

    cout << "Number of elements? ";
    cin >> NumElem;

    a = (int *) malloc(NumElem*sizeof(int));
    ix = (size_t *) malloc(NumElem*sizeof(int));
    

    readArray(a,NumElem);

    cout << "Value to find? ";
    cin >> value;

    cout << endl << findMultValuesInArray(a,NumElem,value,0,20,ix);

    return 0;

}