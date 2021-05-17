#include "date.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

Date:: Date(unsigned int year1, unsigned int month1,unsigned int day1){
    this->year = year1;
    this->month = month1;
    this->day = day1;
}

Date:: Date(string yearMonthDay){
    istringstream line(yearMonthDay);
    string segment;
    vector<string> seglist;

    while(getline(line, segment, '/'))
    {
        seglist.push_back(segment);
    }

    year = stoi(seglist.at(0));
    month = stoi(seglist.at(1));
    day = stoi(seglist.at(2));
}

void Date:: setYear(unsigned int year){
    this->year = year;
}

void Date:: setMonth(unsigned int month){
    this->month = month;
}

void Date:: setDay(unsigned int day){
    this->day = day;
}

void Date:: setDate(unsigned int year, unsigned int month, unsigned int day){
    this->year = year;
    this->month = month;
    this->day = day;
}

unsigned int Date:: getYear() const{
    return year;
}
unsigned int Date:: getMonth() const{
    return month;
}
unsigned int Date:: getDay() const{
    return day;
}

string Date:: getDate() const{
    return to_string(year)+"/"+to_string(month)+"/"+to_string(day);
}

void Date:: show() const{
    cout << day << "/" << month << "/" << year << endl;
}