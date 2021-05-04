/* Determine the roots of a quadratic equation Ax2+Bx+C=0*/

#include <iostream>

using namespace std;

int main(){

    double a,b,c,root1,root2,root_complex1,root_complex2,discriminant;

    cout << "Solution of Ax^2 + Bx + C = 0" << endl << "Insert the coefficients (A B C): ";
    cin >> a >> b >> c;

    discriminant = pow(b,2)-4*a*c;

    if (discriminant>0){
        root1 = (-b + sqrt(discriminant))/(2*a);
        root2 = (-b - sqrt(discriminant))/(2*a);
        cout << "The equation has 2 real roots: " << roundf(root1* 1000) / 1000 << " and " << roundf(root2* 1000) / 1000;
    }
    else if (discriminant==0){
        root1 = (-b)/(2*a);
        cout << "The equation has 1 real root: " << roundf(root1* 1000) / 1000;
    }
    else {
        root1 = (-b)/(2*a);
        root_complex1 = sqrt(-discriminant)/(2*a);
        cout << "The equation has 2 complex roots: " << roundf(root1* 1000) / 1000 << "+" << roundf(root_complex1* 1000) / 1000 << "i   and   " << roundf(root1* 1000) / 1000 << "-" << roundf(root_complex1* 1000) / 1000 << "i";
    }

    return 0;
}