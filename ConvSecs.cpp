#include <iostream>
using namespace std;

int main(){
    long long int seconds = 0;

    cout << "Enter a number of seconds";
    cin >> seconds;

    if (seconds <= 0){
        cout << "\nseconds must be greater than zero" << endl;
        return 0;
    }

    if (seconds >= 86400){
        cout << "Day(s): " << (seconds / 86400) << endl;
        seconds %= 86400;
    }

    if (seconds >= 3600){
        cout << "Hour(s): " << (seconds / 3600) << endl;
        seconds %= 3600;
    }
    
    if (seconds >= 60){
        cout << "Minute(s): " << (seconds / 60) << endl;
        seconds %= 60;
    }

    if (seconds >= 1){
        cout << "Remaining second(s): " << seconds << endl;
    }

    return 0;
}