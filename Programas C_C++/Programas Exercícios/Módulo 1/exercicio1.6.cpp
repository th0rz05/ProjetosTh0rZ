/* Computes the area of a triangle with the coordinates of the 3 vertices */

#include <iostream>
#include <cmath>

using namespace std;


int main()
{
    float ax,ay,bx,by,cx,cy,abside,bcside,acside,semiperimeter,area;

    //input
    cout << "Point A (x/y)";
    cin >> ax >> ay;
    cout << "Point B (x/y)";
    cin >> bx >> by;
    cout << "Point C (x/y)";
    cin >> cx >> cy;

    //compute
    abside = sqrt(pow(bx-ax,2)+pow(by-ay,2));
    bcside = sqrt(pow(cx-bx,2)+pow(cy-by,2));
    acside = sqrt(pow(cx-ax,2)+pow(cy-ay,2));
    semiperimeter = (abside + bcside + acside)/2;
    area = sqrt(semiperimeter*(semiperimeter-abside)*(semiperimeter-bcside)*(semiperimeter-acside));

    //output
    cout << "Area = " << area << endl;

    return 0;
}