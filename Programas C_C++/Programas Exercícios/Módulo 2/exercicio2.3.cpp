/* Sees if the sum of two integers produces underflow or overflow */

#include <iostream> 

using namespace std;

int main(){
    
    int nr1,nr2,sum;

    cout << "Input two integers to sum ";
    cin >> nr1 >> nr2;

    sum = nr1 + nr2;
    
    if ((nr1>0)&&(nr1>0)&&(nr1+nr2<0)){
        cout << "Sum Overflow";
    }
    else if((nr1<0)&&(nr2<0)&&(nr1+nr2>0)){
        cout << "Sum Underflow";
    }
    else{
        cout << "The sum is " << sum << " ";
    }
    return 0;

}