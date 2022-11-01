#include <iostream>

using namespace std;

int main(){
    unsigned int lower;
    unsigned int upper;
    char character;

    do {
        cout << "Enter the ASCII code that is the lower bound [32 through 126]: ";
        cin >> lower;
        if ((lower < 32) || (lower > 126)){
            cout << "Error: The lower bound entered is invalid." << endl;
        } else {
            break;
        }
    } while (true);
    
    do {
        cout << "Enter the ASCII code that is the upper bound [" << lower << " through 126]: ";
        cin >> upper;
        if ((upper < lower) || (upper > 126)){
            cout << "Error: The upper bound entered is invalid." << endl;
        } else {
            break;
        }
    } while (true);

    cout << "\nThe characters with ASCII values in range " << lower << " through " << upper << " are:" << endl;

    for (int i = lower; i <= upper; i++){
        character = i;
        if ((i - lower) % 15 == 0){
            cout << endl;
        }
        cout << character;
    }
    cout << endl;
}