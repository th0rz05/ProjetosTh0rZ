/* Function that reads a fraction and makes some operations */

#include <iostream>

using namespace std;

int gcd(int n1,int n2){
    /* returns the GDC between two numbers */

    
    if (n1==0){
        return n2;
    }
    else if (n2==0){
        return n1;
    }

    while(n1!=n2){
    if (n1>n2){
        n1-=n2;
    }
    else if (n2>n1){
        n2-=n1;
    }

    }

    return n1;
}

bool readFraction(int &numerator, int &denominator){
    /* reads a fractions and see if it is valid */

    int x,y;
    char sep;

    cin >> x;
    if (cin.fail()){
        cin.clear();
        cin.ignore(1000,'\n');
        numerator = 0;
        denominator = 0;
        return false;
    }
    if (cin.peek()=='/'){
        cin.get();
    }
    else{
        numerator = 0;
        denominator = 0;
        return false;
    }
    cin >> y;
    if (cin.fail()){
        cin.clear();
        cin.ignore(1000,'\n');
        numerator = 0;
        denominator = 0;
        return false; 
    }
    if (y==0){
        cin.clear();
        cin.ignore(1000,'\n');
        numerator = 0;
        denominator = 0;
        return false; 
    }
    if (cin.peek()!= '\n'){
        cin.clear();
        cin.ignore(1000,'\n');
        numerator = 0;
        denominator = 0;
        return false;
    }
    numerator = x;
    denominator = y;
    return true;
}

void reduceFraction(int &numerator, int &denominator){
    /* reduces a fraction */

    int div;

    div = gcd(abs(numerator),abs(denominator));

    numerator /= div;
    denominator /= div;
}

void AddFractions(int num1,int denom1,int num2,int denom2){
    /* Adds 2 functions */

    int numf,denomf,tmpdenom;

    tmpdenom = denom1;

    num1 *= denom2;
    denom1 *= denom2;
    num2 *= tmpdenom;
    denom2 *= tmpdenom;

    numf = num1 +num2;
    denomf = denom1;

    reduceFraction(numf,denomf);

    cout << "Result: " << numf << "/" << denomf << endl;

}


void SubFractions(int num1,int denom1,int num2,int denom2){
    /* Subtracts 2 functions */

    int numf,denomf,tmpdenom;

    tmpdenom = denom1;

    num1 *= denom2;
    denom1 *= denom2;
    num2 *= tmpdenom;
    denom2 *= tmpdenom;

    numf = num1 - num2;
    denomf = denom1;

    reduceFraction(numf,denomf);

    cout << "Result: " << numf << "/" << denomf << endl;

}


void MultFractions(int num1,int denom1,int num2,int denom2){
    /* Multiplies 2 functions */

    int numf,denomf;

    numf = num1 * num2;
    denomf = denom1 * denom2;

    reduceFraction(numf,denomf);

    cout << "Result: " << numf << "/" << denomf << endl;

}

void DivFractions(int num1,int denom1,int num2,int denom2){
    /* Divides 2 functions */

    int tmp;

    tmp= num2;

    num2 = denom2;
    denom2 = tmp;

    MultFractions(num1,denom1,num2,denom2);

}

int main(){

    int numerator,denominator,numerator2,denominator2;
    char oper;

    cout << "Input first fraction in format N/D: ";
    if (readFraction(numerator,denominator)){
        reduceFraction(numerator,denominator);
    }
    else{
        cerr << "Invalid input." << endl;
        return 1;
    }



    cout << "Operation? (+,-,*,/)";
    cin >> oper;



    cout << "Input second fraction in format N/D: ";
    if(readFraction(numerator2,denominator2)){
        reduceFraction(numerator2,denominator2);
    }
    else{
        cerr << "Invalid input." << endl;
        return 1;
    }

    switch (oper) {
        case '+':
            AddFractions(numerator,denominator,numerator2,denominator2);
            break;
        case '-':
            SubFractions(numerator,denominator,numerator2,denominator2);
            break;
        case '*':
            MultFractions(numerator,denominator,numerator2,denominator2);
            break;
        case '/':
            DivFractions(numerator,denominator,numerator2,denominator2);
            break;
        default:
            // operator is doesn't match any case constant (+, -, *, /)
            cerr << "Error! The operator is not correct";
            return 1;
    }

    return 0;
}