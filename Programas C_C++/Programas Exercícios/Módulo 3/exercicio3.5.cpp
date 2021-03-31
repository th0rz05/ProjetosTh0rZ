/* Euclid's iterative algorithm for determining the greatest common divisor (GCD) of two numbers */

#include <iostream>

using namespace std;

int gcd(int n1,int n2){
    /* returns the GDC between two numbers */

    
    if (n1==0){
        return n2;
    }
    else if (n2==0){
        return n1;
    }

    while(n1!=n2){
    if (n1>n2){
        n1-=n2;
    }
    else if (n2>n1){
        n2-=n1;
    }

    }

    return n1;
}

int main(){

    int number1,number2,result;

    cout << "Input two numbers to determine the greatest common divisor: ";
    cin >> number1 >> number2;

    result = gcd(number1,number2);

    cout << "The GCD between " << number1 << " and " << number2 << " is " << result << endl;

    return 0;
}