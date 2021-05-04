/* Computes the sum of two hours */

#include <iostream>

using namespace std;

int main()
{
    
    int hours1,hours2,minutes1,minutes2,seconds1,seconds2,hours_final,minutes_final,seconds_final,days_final;
    char sep1,sep2,sep3,sep4;
    // input
    cout << "Time1 (hours minutes seconds) ?";
    cin >> hours1 >> sep1 >> minutes1 >> sep2 >> seconds1;
    cout << "Time2 (hours minutes seconds) ?";
    cin >> hours2 >> sep3 >> minutes2 >> sep4 >> seconds2;

    // compute
    seconds_final=seconds1+seconds2;
	minutes_final=minutes1+minutes2+(seconds_final/60);
	hours_final=hours1+hours2+(minutes_final/60);
    days_final=hours_final/24;
    hours_final = hours_final%24;
	minutes_final=minutes_final%60;
	seconds_final=seconds_final%60;

    //output
    if (days_final==1)
        cout << "Time1 + Time2 = " << days_final << " day, " << hours_final << " hours, " << minutes_final << " minutes and " << seconds_final << " seconds." << endl; 
    else
        cout << "Time1 + Time2 = " << hours_final << " hours, " << minutes_final << " minutes and " << seconds_final << " seconds." << endl;

    return 0;

}