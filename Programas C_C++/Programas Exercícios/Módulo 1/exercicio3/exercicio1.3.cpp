/* Calculate the mass of a sphere in kg */

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const float PI = 3.14159;
    float mass_material,radius,mass_sphere;

    // input
    cout << "What is the mass of the material of the sphere in Kg/m^3? ";
    cin >> mass_material;
    cout << "What is the radius of the sphere in meters? ";
    cin >> radius;

    // calculate and output
    mass_sphere = (4* PI * mass_material * pow(radius,3))/3;
    cout << "The mass of the sphere is " << mass_sphere << " Kg. ";

    return 0;
}