/* Series giving the value of the mathematical constant pi,e and e^-x */

#include <iostream>

using namespace std;

int main(){

    //input
    int n,sign=1;
    double aprox=0,denom=1;

    cout << "How many terms? ";
    cin >> n;

    //compute series pi
    for (int i = 1; i<=n;i++){
        aprox= aprox + sign*(4/denom);
        denom+=2;
        sign*=-1;
    }
    cout << "The aproximation of pi by " << n << " terms is "<< aprox << endl;

    //input
    int n2;
    double aprox2=1,denom2=1,sum,denom_tmp=1;
    const double numerator =1;

    cout << "How many terms? ";
    cin >> n2;

    //compute series e
    for (int i2 = 1; i2<=n2;i2++){
        sum= denom_tmp*(numerator/denom2);
        aprox2+= sum;
        denom_tmp=sum;
        denom2+=1;
    }
    cout << "The aproximation of e by " << n2 << " terms is "<< aprox2 << endl;
    
    //input
    int n3;
    double aprox3=1,denom3=1,sum2,denom_tmp2=1,x,sign2=-1;
    

    cout << "How many terms? ";
    cin >> n3;
    cout << "x = ";
    cin >> x;

    //compute series e^-x
    for (int i3 = 1; i3<=n3;i3++){
        sum2= sign2*denom_tmp2*(x/denom3);
        aprox3+= sum2;
        denom_tmp2=abs(sum2);
        denom3+=1;
        sign2*=-1;
    }
    cout << "The aproximation of e^-"<< x <<" by " << n3 << " terms is "<< aprox3;

    return 0;
}