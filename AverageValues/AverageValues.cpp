#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
    string fileName;

    double num;
    int numValues = 0;
    double numValidValues = 0;
    int numInvalidValues = 0;
    double total = 0.0;
    double average = 0.0;

    ifstream inputFile;
    ofstream outputFile;

    cout << "Enter the input file name: ";
    cin >> fileName;
    cout << endl;

    inputFile.open(fileName);
    if (inputFile){
        outputFile.open("badvalues.txt");
        if (outputFile){
            while (inputFile >> num) {
                numValues += 1;
                if (num < 1 || num > 150){
                    outputFile << fixed << setprecision(3) << num << endl;
                    numInvalidValues += 1;
                } else {
                    numValidValues += 1;
                    total += num;
                }
            }
            cout << "Total number of values read: " << numValues << endl;
            cout << "Valid values read: " << numValidValues << endl;
            cout << "Invalid values read: " << numInvalidValues << endl;
            if (numValidValues == 0){
                cout << "The file did not contain any valid values." << endl;
            } else {
                cout << "The average of the valid numbers read = " << fixed << setprecision(2) << total / numValidValues << endl;
            }
        }
    } else {
        cout << "The file " << "\"" << fileName << "\"" << " could not be opened." << endl;
    }

    return 0;
}