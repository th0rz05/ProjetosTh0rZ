/* Function that reads a integer from the keyboard and returns if it is valid or not */

#include <iostream>

using namespace std;

bool readInt(int &x){
    /*reads a integer from the keyboard and returns if it is valid or not */
    
    int num ;

    //try read
    cout << "Input number: ";
    cin >> num;

    if (cin.eof()){
        return false;// end of program
        }
    if (cin.fail()){
        cin.clear();
        cin.ignore(1000,'\n');
        return false;   //not integer
    }
    if (cin.peek()!='\n'){
        cin.clear();
        cin.ignore(1000,'\n');
        return false;    // not integer
    }


    x = num;
    return true; //valid
}

int main(){

    int y;

    while(true){

        if (readInt(y)==true){       //try read integer
            cout << "The number was " << y << endl << endl;
            }
            else{
                if (cin.eof()){
                    cout << endl << "END!"<< endl << endl;
                    break;// end of program
                }
                else{
                    cout << "The number was invalid. " << endl << endl;
                }
        }
    }

    return 0;
}