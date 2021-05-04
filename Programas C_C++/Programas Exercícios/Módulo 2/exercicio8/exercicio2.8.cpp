/* Displays on the screen a table of sines, cosines and tangents */

#include <cmath>
#include <iostream> 

using namespace std;

int main(){

    double angle,sine,cossine,tangent,increment,range_min,range_max;
    
    cout << "Input range minimum: ";
    cin >> range_min;
    cout << "Input range maximum: ";
    cin >> range_max;
    cout << "Input increment: ";
    cin >> increment;

    angle = range_min;
    
    cout << "ang\tsin\tcos\ttan\n";

    for(;angle<=range_max;angle+=increment){
        sine = roundf(sin(angle*3.14159/180)* 100000) / 100000;
        cossine = roundf(cos(angle*3.14159/180)* 100000) / 100000;
        tangent =roundf(tan(angle*3.14159/180)* 100000) / 100000;

        if(angle==90){
            cout << angle << "\t" << sine << "\t" << cossine << "\t" << "infinite" << endl;
        }
        else{
            cout << angle << "\t" << sine << "\t" << cossine << "\t" << tangent << endl;
        }
    }
        

    return 0;
}