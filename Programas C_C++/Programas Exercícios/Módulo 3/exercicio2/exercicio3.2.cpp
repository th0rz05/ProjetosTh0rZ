/* Rewrite problem 2.7 using function IsPrime() */

#include <iostream>

using namespace std;

bool IsPrime(int num){
    /* Receives a number and tells if it is prime or not */

    if (num == 1){
        return false;
    }

    for (int i=2;i<=sqrt(num);i++){
        if(num%i==0)
            return false;
    }
    return true;
}

int main(){

    int number;

    cout << "Input a number: ";
    cin >> number;

    if(!IsPrime(number)){
        cout << number << " is not prime." << endl;
    }
    else {
        cout << number << " is prime." << endl;
    }

    return 0;
}