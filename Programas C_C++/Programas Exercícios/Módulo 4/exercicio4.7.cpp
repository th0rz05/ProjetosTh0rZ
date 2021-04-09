#include <iostream>

using namespace std;

const int NE = 5;

int main(){

    int a[NE][NE] = {{7,3,4,1,3},{2,9,6,2,1},{1,3,5,1,4},{6,5,2,7,5},{4,2,1,3,6}};


    for(int i = 0;i<NE;i++){
        for (int j = 0;j<NE;j++){
            if (0<i && i< NE-1 && 0<j && j<NE-1 ){
                bool max = true;
                for(int x = -1;x < 1;x++){
                    if (a[i][j] < a[i+x][j-1]){
                        max = false;
                        break;
                    }
                    if (a[i][j] < a[i+x][j]){
                        max = false;
                        break;
                    }
                    if (a[i][j] < a[i+x][j+1]){
                        max = false;
                        break;
                    }
                }
                if (max){
                    cout << a[i][j] << " is a local max." << endl;                
                }  
            }
        }
    }

    return 0;
}