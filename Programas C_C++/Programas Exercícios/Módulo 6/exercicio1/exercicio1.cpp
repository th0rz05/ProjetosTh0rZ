#include <iostream>
#include "date.h"

using namespace std;

int main()
{
    int ano,mes,dia;
    string data;
    bool valido,igual,diferente;

    Date a("2009/12/31");
    Date b("2009/12/31");
    a.show();
    valido = a.isValid();
    cout << valido << endl;
    igual = a.isEqualTo(b);
    cout << igual << endl;
    diferente=a.isNotEqualTo(b);
    cout << diferente << endl;
    a.show();
    a.setYear(2021);
    a.show();
    a.setMonth(2);
    a.show();
    a.setDay(3);
    a.show();
    ano = a.getYear();
    mes = a.getMonth();
    dia = a.getDay();
    data = a.getDate();
    cout << ano << " " << mes << " " << dia << " " << data << endl;
}
