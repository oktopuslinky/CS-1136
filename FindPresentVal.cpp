#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int readYears();
double presentValue(double futureValue, double interestRate, int numberYears);
void displayResults(double presentValue, double futureValue, double interestRate, int numberYears);

int main(){
    double presValue;
    double futureValue;
    double interestRate;
    int numYears;
    
    do {
        cout << "Enter the future value of the investment: ";
        cin >> futureValue;
        if (futureValue <= 0){
            cout << "Error the future value must be greater than zero." << endl;
        } else {
            break;
        }
    } while (true);

    do {
        cout << "Enter the annual interest rate: ";
        cin >> interestRate;
        if (interestRate <= 0){
            cout << "Error the annual interest rate must be greater than zero." << endl;
        } else {
            interestRate /= 100;
            break;
        }
    } while (true);

    numYears = readYears();
    presValue = presentValue(futureValue, interestRate, numYears);
    displayResults(presValue, futureValue, interestRate, numYears);
}

int readYears(){
    int investmentYears;

    do {
        cout << "Enter the whole number of years of the investment: ";
        cin >> investmentYears;
        if (investmentYears <= 0){
            cout << "Error the number of years must be greater than zero." << endl;
        } else {
            return investmentYears;
        }
    } while (true);
}

double presentValue(double futureValue, double interestRate, int numberYears){
    return (futureValue / (pow((1.0 + interestRate), numberYears)));
}

void displayResults(double presentValue, double futureValue, double interestRate, int years){
    cout << "Present value: $" << fixed << setprecision(2) << presentValue << endl;
    cout << "Years: " << years << endl;
    cout << "Annual interest rate: " << fixed << setprecision(3) << interestRate * 100 << "%" << endl;
    cout << "Future value: $" << fixed << setprecision (2) << futureValue << endl;
}