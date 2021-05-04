/* Rewrite the exercise 1.6 with functions */

#include <iostream>
#include <cmath>

using namespace std;

double distance(double x1, double y1, double x2, double y2){
    /* Calculate the distance between two points whose coordinates are (x1,y1) and (x2,y2) */
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

double area(double x1, double y1, double x2, double y2, double x3, double y3){
    /* Calculate the area of a triangle whose vertices have coordinates (x1,y1), (x2,y2) and (x3,y3) */
    float semiperimeter;
    semiperimeter = (distance(x1,y1,x2,y2) + distance(x2,y2,x3,y3) + distance(x1,y1,x3,y3))/2;
    return sqrt(semiperimeter*(semiperimeter-distance(x1,y1,x2,y2))*(semiperimeter-distance(x2,y2,x3,y3))
    *(semiperimeter-distance(x1,y1,x3,y3)));

}

int main()
{
    double ax,ay,bx,by,cx,cy,area_final;

    //input
    cout << "Point A (x/y)";
    cin >> ax >> ay;
    cout << "Point B (x/y)";
    cin >> bx >> by;
    cout << "Point C (x/y)";
    cin >> cx >> cy;

    //compute
    area_final = area(ax,ay,bx,by,cx,cy);

    //output
    cout << "Area = " << area_final << endl;

    return 0;
}