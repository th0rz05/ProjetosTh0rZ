/* Create a function to round a number */

#include <iostream>
#include <iomanip>

using namespace std;

double round(double x, unsigned n){
    /* Rounds a number x to n decimal places */
    return (floor(x * pow((double)10,n) + 0.5) / pow((double)10,n));
}

int main(){

    double x;
    int n;

    cout << "Num: ";
    cin >> x;
    cout << "Round to how many decimal places: ";
    cin >> n;

    cout << "Number rounded to " << n << " decimal places equals " << round(x,n);

    return 0;
}