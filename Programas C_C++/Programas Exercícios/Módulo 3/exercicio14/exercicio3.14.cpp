/*  calculating an approximate value for the definite integral  */

#include <iostream>

using namespace std;

double func(double x){
    return sqrt(4*x*x + 2*x); 
}

double integrateTR(double f(double), double a, double b, int n){
    double width,sum;

    width = (b-a)/n;
    sum = 0;

    for(int i=1;i<=n;i++){
        sum += (width/2)*(f(a+(i-1)*width)+f(a+i*width));
    }

    return sum;
}

int main(){

    cout << integrateTR(func,0,30,100000) << endl;

    return 0;
}