/* Reads 3 integers and calculates their mean 
and the difference between them and the mean */

#include <iostream>

using namespace std;

int main()
{
    int a,b,c ;
    float mean, a_dif_mean, b_dif_mean, c_dif_mean;

    // input
    cout << "Please, input 3 integer numbers" << "\nA? ";
    cin >> a;
    cout << "B? ";
    cin >> b;
    cout << "C? ";
    cin >> c;

    // calculate 
    mean = (float(a + b + c)) / 3; 
    a_dif_mean = a - mean;
    b_dif_mean = b - mean;
    c_dif_mean = c - mean;

    // output
    cout << "Mean = " << mean << "\nA-mean = " << a_dif_mean <<
    "\nB-mean = " << b_dif_mean << "\nC-mean = " << c_dif_mean << " ";
    return 0;
}
