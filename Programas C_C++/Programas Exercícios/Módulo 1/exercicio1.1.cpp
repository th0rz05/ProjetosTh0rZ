/* What is the ASCII code of that character*/

#include <iostream>

using namespace std;

int main() 
{   
    char letter;
    cout << "Which is the ASCII code of ";
    cin >> letter;
    cout << "The ASCII code of " << letter << " is " << int(letter) << ".";
    return 0;
}
