/* Basic calculator */

#include <iostream>
#include <iomanip>

using namespace std;

int main() 
{
     const unsigned RESULT_PRECISION = 3;
     double operand1, operand2; // input operands
     char operation; // operation; possible values: + - * / 
     double result; // result of "operand1 operation operand2" 
     bool validOperation = true; // operation is + - * or /
     
     // input 2 numbers
     cout << "x op y ? ";
     cin >> operand1 >> operation >> operand2;

     // compute result if operation is valid
     switch(operation)
     {
     case '+':
          result = operand1 + operand2;
          break;
     case '-':
          result = operand1 - operand2;
          break;
     case '*':
          result = operand1 * operand2;
          break;
     case '/':
          result = operand1 / operand2;
          break;
     default:
          validOperation = false;
     }

     //show result or invalid input message
     if (validOperation)
     {
          cout << operand1 << ' ' << operation << ' ' << operand2 << " = "; 
          cout << fixed << setprecision(RESULT_PRECISION) << result << endl;
     }
          else
               cerr << "Invalid operation !\n";
     return 0;
}

