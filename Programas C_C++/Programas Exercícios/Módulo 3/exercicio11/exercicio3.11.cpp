/*  Euclid's recursive algorithm for determining the greatest common divisor (GCD) of two numbers, m and n  */

#include <iostream>

using namespace std;

int gcd(int x, int y){
    /* determines the greatest common divisor */

    int temp;

    while (x%y!=0){
        temp = y;
        y = x % y;
        x = temp;
    }
    return y;
}

int main(){

    int num1,num2;

    cout << "N1: ";
    cin >> num1;
    cout << "N2: ";
    cin >> num2;

    cout << "Gcd = " << gcd(num1,num2)<< endl;
    
    return 0;
}