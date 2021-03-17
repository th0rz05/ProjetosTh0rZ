/* Determines the amount that a depositor can withdraw from the bank,
 after n years of depositing an amount q, 
 where j% is the annual interest rate. */

#include <iostream>

using namespace std;

int main(){

    double amount,n_years,q_amount,j_interest;

    cout << "Input the inicial amount: ";
    cin >> q_amount;
    cout << "Input the number of years: ";
    cin >> n_years;
    cout << "Input the annual interest rate(%): ";
    cin >> j_interest;

    amount = q_amount*pow((1+(j_interest/100)),n_years);

    cout << "The user can withdraw " << amount << " euros.";

    return 0;
}