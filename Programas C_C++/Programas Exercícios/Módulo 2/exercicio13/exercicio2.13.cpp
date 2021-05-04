/* Reads a sequence of integer numbers, 
and determines and writes the sum, the mean, the standard deviation,
the smallest and the largest of the numbers */

#include <iostream>
#include <cmath>

using namespace std;

int main(){

    //initialize
    int number,sum=0,smallest=INT_MAX,largest=INT_MIN,len=0,sum_power=0;
    double mean,stdev;

    //input numbers
    while(true){
        cout << "Number (Ctrl-Z to end)? ";
        cin >> number;
        
        if (cin.fail()){
            if (cin.eof()){
                cout << "End of program!"<<endl;//end of program
                break;
            }
            else{
                cin.clear();
                cin.ignore(1000,'\n');//not valid input
            }
        } 
        else{//largest smallest 
            sum += number;
            if (number>largest){
                largest = number;
            }
            if (number<smallest){
                smallest = number;
            }
            len+=1;
            sum_power += pow(number,2);//for calculate stdev
        }
    }

    mean= double(sum)/double(len);

    stdev = sqrt((sum_power-2*sum*mean+pow(mean,2)*len)/len);

    //output
    cout << "Sum = " << sum << endl;
    cout << "Smallest = " << smallest << endl;
    cout << "Largest = " << largest << endl;
    cout << "Length = " << len << endl;
    cout << "Mean = " << mean << endl;
    cout << "Standard deviation = " << stdev << endl;

    return 0;
}
