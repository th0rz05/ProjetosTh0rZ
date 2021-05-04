/* Program to show, on the screen, the calendar of a given year */

#include <iostream>

using namespace std;

bool IsLeapYear(int num){
    /* returns if a year is a leap year */

   if (num%400==0){
       return true;
   }
   if ((num%4==0) and !(num%100==0)){
       return true;
   }
   return false;
}

int NumberDays(int month, int year){
    /* returns the number of days of a certain month */

    if (month==1||month==3||month==5||month==7||month==8||month==10||month==12){
        return 31;
    }
    if (month==4||month==6||month==9||month==11){
        return 30;
    }
    if (IsLeapYear(year)){
        return 29;
    }
    return 28;
}

int DayOfWeek(int day, int month, int year){
    /* Returns day of the week of certain day */

    int s,c,ds;
    double x,a;

    s = year / 100;
    a = year - s*100;

    if (month==3||month==11){
        c = 3;
    }
    if (month==4||month==7){
        c = 6;
    }
    if (month==5){
        c = 1;
    }
    if (month==6){
        c = 4;
    }
    if (month==8){
        c = 2;
    }
    if (month==9||month==12){
        c = 5;
    }
    if (month==10){
        c = 0;
    }
    if(IsLeapYear(year)){
        if (month==1){
        c = 6;
        }
        if (month==2){
        c = 2;
        }
    }
    else{
        if (month==1){
        c = 0;
        }
        if (month==2){
        c = 3;
        }
    }

    x=(5*a)/4;

    ds = floor(x)+c+day-(2*(s%4))+7;

    return ds%7;
}

int main(){

    int year,month,day;

    cout << "Year: ";
    cin >> year;
    cout << "Month: ";
    cin >> month;
    cout << "Day: ";
    cin >>day;

    if (DayOfWeek(day,month,year)==0){
        cout << "It's a Saturday" << endl;
    }
    if (DayOfWeek(day,month,year)==1){
        cout << "It's a Sunday" << endl;
    }
    if (DayOfWeek(day,month,year)==2){
        cout << "It's a Monday" << endl;
    }
    if (DayOfWeek(day,month,year)==3){
        cout << "It's a Tuesday" << endl;
    }
    if (DayOfWeek(day,month,year)==4){
        cout << "It's a Wednesday" << endl;
    }
    if (DayOfWeek(day,month,year)==5){
        cout << "It's a Thursday" << endl;
    }
    if (DayOfWeek(day,month,year)==6){
        cout << "It's a Friday" << endl;
    }

    return 0;
}