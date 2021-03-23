/* Reads an integer and breaks it down into prime factors */

#include <iostream>

using namespace std;

int main(){

    //input
    int number;
    bool prime=false;

    cout << "Input number: ";
    cin >> number;

    cout << number<< " prime factors are ";

    //see if is prime
    for (int i=2;i<=sqrt(number);i++){
        if(number%i==0){
            prime = false;
            break;
        }
    }

    if (prime==true){
        cout << number ;
        return 0;
    }
    
    //factorizes in 2
    while (number % 2 == 0)  
    {  
        cout << 2 << " ";  
        number = number/2;  
    }  
    
    //factorizes in the rest of primes
    for (int i = 3; i <= 100; i = i + 2)  
    {  
        
        while (number % i == 0)  
        {  
            cout << i << " ";  
            number = number/i;  
        }  
    }

    //last number if prime show
    if (number>1){
        cout << number << endl;
    }
    
    return 0;
}