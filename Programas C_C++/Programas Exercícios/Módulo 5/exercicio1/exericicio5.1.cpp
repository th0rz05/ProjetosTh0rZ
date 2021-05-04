
#include <iostream>
#include <string>

using namespace std;

char encryptChar(char c, int key){
    char s;
    while (key < 0){
        key +=26;
    }
    if (isalpha(c)){
        if (isupper(c)){
            s = ((c-65 + key)%26 + 65 );
            return s;
        }
        else{
            s = ((c-97 + key)%26 + 97 );
            return s;
        }
    }
    return c;
}

int main(){

    string frase;
    string frase_final("");

    frase = "The quick brown fox JUMPS over the lazy dog";

    for (size_t i = 0; i<frase.length();i++){
        frase_final += encryptChar(frase.at(i),-10);
    }
    cout << frase_final << endl;
    cout << "Jxu gkysa rhemd ven ZKCFI eluh jxu bqpo tew" << endl;

    return 0;
}