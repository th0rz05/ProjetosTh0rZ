/* Determines whether or not a number is a palindrome */

#include <iostream>

using namespace std;

int main(){

    //initialize
    int digit1,digit2,number,length,temp_len,num_temp;
    bool palindrome;

    palindrome = true;

    cout << "Input number: ";
    cin >> number;

    num_temp = number;

    //calculate length
    while (num_temp>0){
        num_temp = num_temp/10;
        length+=1;
    }

    temp_len=length;

    //see if is palindrome
    for(int i=1;i<=(length/2);i++){
        digit1= number % int(pow(10,1));
        digit2= number / pow(10,temp_len-1);
        if(digit1!=digit2){
            palindrome = false;
            break;
        }
        number=number-digit2*pow(10,temp_len-1);
        number=number/10;
        temp_len = temp_len-2; 
    }
    
    //output
    if (palindrome){
        cout << "It's a palindrome";
    }
    else {
        cout << "It isn't a palindrome";
    }


    return 0;
}