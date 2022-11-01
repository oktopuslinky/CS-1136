#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    
    double dollars;

    cout << "Enter an amount to be converted in dollars:";
    cin >> dollars;
    cout << endl;

    const double PESOS = dollars * 20.06;
    const double EUROS = dollars * 0.99;
    const double YEN = dollars * 143.08;

    cout << " " << setw(10) << " Dollars\t" << " " << setw(10) << " Pesos\t" << " " << setw(10) << " Euros\t" << setw(10) << " Yen" << endl;
    cout << fixed << setprecision(2) << setw(10) << dollars << "\t" << setw(10) << PESOS << "\t" << setw(10) << EUROS << "\t" << setw(10) << YEN << endl;

    return 0;
}