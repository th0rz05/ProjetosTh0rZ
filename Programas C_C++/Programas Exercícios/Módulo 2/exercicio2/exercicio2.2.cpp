/* From 3 numbers inputed gives the bigger and the smaller. 
   Organizes them in descending order.
   And see if they can form a triangle */

#include <iostream>

using namespace std;

int main(){

    double nr1,nr2,nr3;

    cout << "Input 3 positive numbers seperated by spaces:";
    cin >> nr1 >> nr2 >> nr3 ;

    if (nr1<=0||nr2<=0||nr3<=0){
        cerr << "Found negative number or zero";
        cin.clear();
        cin.ignore(1000,'\n');
    }
    else {
        if(nr1>=nr2&&nr1>=nr3&&nr2>=nr3){
            cout << "The biggest number is " << nr1 << " the middle one is " << nr2 << " and the smallest is " << nr3 << endl;
        }
        else if(nr1>=nr2&&nr1>=nr3&&nr3>=nr2){
            cout << "The biggest number is " << nr1 << " the middle one is " << nr3 << " and the smallest is " << nr2 << endl;
        }
        else if(nr2>=nr1&&nr2>=nr3&&nr1>=nr3){
            cout << "The biggest number is " << nr2 << " the middle one is " << nr1 << " and the smallest is " << nr3 << endl;
        }
        else if(nr2>=nr1&&nr2>=nr3&&nr3>=nr1){
            cout << "The biggest number is " << nr2 << " the middle one is " << nr3 << " and the smallest is " << nr1 << endl;
        }
        else if(nr3>=nr1&&nr3>=nr2&&nr2>=nr1){
            cout << "The biggest number is " << nr3 << " the middle one is " << nr2 << " and the smallest is " << nr1 << endl;
        }
        else if(nr3>=nr1&&nr3>=nr2&&nr1>=nr2){
            cout << "The biggest number is " << nr3 << " the middle one is " << nr1 << " and the smallest is " << nr2 << endl;
        } 
        if (nr1+nr2<nr3||nr1+nr3<nr2||nr2+nr3<nr1){
            cout << "\nIt's impossible to build a triangle with these 3 side lengths." << endl;
        }
        else{
            cout << "\nIt's possible to build a triangle with these 3 side lengths." << endl;
        }
    }
    return 0;
}