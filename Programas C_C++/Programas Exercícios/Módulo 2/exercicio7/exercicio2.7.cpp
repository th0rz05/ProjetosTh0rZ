/* Sees if a number is prime
Writes all the prime numbers lower than 1000 
Writes on the screen the first 100 prime numbers
Determines the largest prime number that can be stored in a varible of type unsigned long*/

#include <iostream>

using namespace std;

int main(){

    int number,number2=2,number3=2,number_of_primes=0;
    bool prime=true,prime1=true,prime2=true;
    

    cout << " Input a number: ";
    cin >> number;

    for (int i=2;i<=sqrt(number);i++){
        if(number%i==0){
            cout << "The number is not prime because is divisible by " << i << endl;
            prime = false;
            break;
        }
    }
    if(number==1){
        cout << "The number is not prime." << endl;
    }
    else if(prime==true){
        cout << "The number is prime." << endl;
    }

    while(number2<=1000){
        for (int i2=2;i2<=sqrt(number2);i2++){
            if(number2%i2==0){
                prime1 = false;
                break;
            }
        }
        if(prime1){
            cout << number2 << "\n";
        }
        number2++;
        prime1 = true;
    }

    while(number_of_primes<100){
        for (int i3=2;i3<=sqrt(number3);i3++){
            if(number3%i3==0){
                prime2 = false;
                break;
            }
        }
        if(prime2){
            cout << number3<< "\n";
            number_of_primes++;
        }
        number3++;
        prime2 = true;
    }


    return 0;
}