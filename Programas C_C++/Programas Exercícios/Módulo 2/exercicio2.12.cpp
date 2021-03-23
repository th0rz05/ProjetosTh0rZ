#include <iostream>

using namespace std;

int main(){

    //input
    int sign=1;
    double precision,aprox=0,denom=1,aprox_tmp;

    cout << "How much precision? ";
    cin >> precision;

    //compute series pi
    do{
        aprox_tmp = aprox;
        aprox= aprox + sign*(4/denom);
        denom+=2;
        sign*=-1;
    } while(abs(aprox_tmp-aprox)>=precision);
    cout << "The aproximation of pi with " << precision << " of precision is "<< aprox << endl;

    //input
    double aprox2=1,denom2=1,sum,denom_tmp=1,aprox_tmp2,precision2;
    const double numerator =1;

    cout << "How much precision? ";
    cin >> precision2;

    //compute series e
    do{
        aprox_tmp2 = aprox2;
        sum= denom_tmp*(numerator/denom2);
        aprox2+= sum;
        denom_tmp=sum;
        denom2+=1;
    }while(abs(aprox_tmp2-aprox2)>=precision2);
    cout << "The aproximation of e with " << precision2 << " of precision is "<< aprox2 << endl;
    
    //input
    double aprox3=1,denom3=1,sum2,denom_tmp2=1,x,sign2=-1,aprox_tmp3,precision3;
    
    cout << "x = ";
    cin >> x;
    cout << "How much precision? ";
    cin >> precision3;

    //compute series e^-x
    do{
        aprox_tmp3 = aprox3;
        sum2= sign2*denom_tmp2*(x/denom3);
        aprox3+= sum2;
        denom_tmp2=abs(sum2);
        denom3+=1;
        sign2*=-1;
    }while(abs(aprox_tmp3-aprox3)>=precision3);
    cout << "The aproximation of e^-"<< x <<" with " << precision3 << " of precision is "<< aprox3 << endl;
    
    return 0;
}