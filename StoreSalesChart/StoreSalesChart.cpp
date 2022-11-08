#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int main(){
    string fileName;

    ifstream inputFile;

    int intStoreNum;
    int intSales;
    int i;
    bool firstValue = true;

    cout << "Enter input file name: ";
    cin >> fileName;
    cout << endl;

    inputFile.open(fileName);

    if (inputFile){
        ofstream outputFile;
        outputFile.open("saleschart.txt");
        if (outputFile){
            while (inputFile >> intStoreNum >> intSales){
                if (intStoreNum < 1 || intStoreNum > 99){
                    cout << "Error! The store number " << intStoreNum << " is not valid." << endl;
                } else if (intSales < 0){
                    cout << "Error! The sales value for store " << intStoreNum << " is negative." << endl;
                } else {
                    if (firstValue == true){
                        outputFile << "SALES BAR CHART" << endl;
                        outputFile << "(Each * equals 5,000 dollars)" << endl;
                        firstValue = false;
                    }

                    long long int barNum = intSales / 5000LL;
                    outputFile << "Store " << setw(2) << intStoreNum << ": ";
                    for (i = 0; i < barNum; i++){
                        outputFile << "*";
                    }
                    outputFile << endl;
                }
            }
            outputFile.close();
        }
        
        inputFile.close();

    } else {
        cout << "Error File " << "\"" << fileName << "\"" << " could not be opened." << endl;
    }
    
    return 0;
}