/* Determines the cost of transportation depending on the weight */

#include <iostream>

using namespace std;

int main(){

    double weight,cost;

    cout << "Input the weight of merchandise in grams: ";
    cin >> weight;

    if (weight<=500){
        cost = 5;
    }
    else if (weight <= 1000){
        cost = 5 + (weight-500)*(1.5/100);
    }
    else{
        cost = 12.5 + ((weight-1000)*5)/250;
    }

    cout << "The cost of transportation is " << cost << " euros.";

    return 0;
}