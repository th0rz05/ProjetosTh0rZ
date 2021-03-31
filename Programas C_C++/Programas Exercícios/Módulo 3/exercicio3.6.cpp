/* Function that returns the time (in seconds) that has elapsed since the first time it was called. */

#include <iostream>
#include <ctime>

using namespace std;

time_t timeElapsed(){
    /* Returns the time elapsed in seconds since the function was called for the first time */

    static const time_t time1 = time(NULL);
    return time(NULL)-time1;
}

int main(){
    
    cout << "Hit enter to call function? (Ctrl-Z to end)";

    while (true){
        cin.get();
        if (cin.eof()){
            break;//end of program
        }   
        else{
            cout << timeElapsed() << "s."; //output
        } 
    }

    return 0;
}