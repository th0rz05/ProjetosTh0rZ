/* Computes the solution of a system of linear equations with 2 variables(x , y):
                                a·x + b·y = c
                                d·x + e·y = f
   Gives error if system is impossible/inconsistent
 */

#include <iostream>

using namespace std;

int main()
{
    double a,b,c,d,e,f,x,y;

    // input
    cout << "\n\tax + by = c\n\tdx + ey = f\nInput the values of the letters:\na? ";
    cin >> a;
    cout << "b? ";
    cin >> b;
    cout << "c? ";
    cin >> c;
    cout << "d? ";
    cin >> d;
    cout << "e? ";
    cin >> e;
    cout << "f? ";
    cin >> f;

    // calculate
    x = (c*e - b*f) / (a*e - b*d);
    y = (a*f - c*d) / (a*e - b*d);

    // output
    if ((a*e - b*d)!= 0)
    {
        cout << "The solution of the system is:\n\tx = " << x << "\n\ty = " << y << "\n\n";
    }
    else{
        cout << "Impossible System";
    }
    return 0;
}