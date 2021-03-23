#include <iostream>

using namespace std;

int main(){

    int sum = 0;
    for (int i=1; i<=5; i++) {
        int value; 
        cout << "Value no. " << i << " ? ";
        cin >> value;
        if (cin.fail()){
            if (cin.eof()){
                cerr <<endl<< " Fim do programa";
                return 0; 
            }
            else
            {   
                cerr << "input não valido"<<endl;
                i-=1;
                cin.clear();
                cin.ignore(10000,'\n');
            }
        }
        else{
            sum = sum + value;
        } 
    }

    cout << "Sum is " << sum;
    return 0;
}