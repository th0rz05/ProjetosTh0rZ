#include <iostream>
#include "date.h"

using namespace std;

int main()
{
    int ano,mes,dia;
    string data;

    Date a("2009/10/2");
    a.show();
    a.setDate(2002,8,5);
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
