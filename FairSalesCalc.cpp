#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int chiliDogs, cornDogs, chips, softDrinks, waterBottles;
    const double tax = 0.0825;
    double taxable, taxAmount, nonTaxable, total;
    
    cout << "Enter the number of chili dogs" << endl;
    cin >> chiliDogs;
    
    cout << "Enter the number of corn dogs" << endl;
    cin >> cornDogs;
    
    cout << "Enter the number of chips" << endl;
    cin >> chips;
    
    cout << "Enter the number of soft drinks" << endl;
    cin >> softDrinks;
    
    cout << "Enter the number water bottles" << endl;
    cin >> waterBottles;
    
    taxable = 8 * chiliDogs + 6 * cornDogs + 2 * chips + 5 * softDrinks;
    taxAmount = taxable * tax;
    nonTaxable = waterBottles * 4;
    total = taxable + taxAmount + nonTaxable;
    
    cout << left << setw(13) << "Taxable:" << "$" << right << setw(8) << fixed << setprecision(2) << taxable << endl;
    cout << left << setw(13) << "Tax amount:" << "$" << right << setw(8) << fixed << setprecision(2) << taxAmount << endl;
    cout << left << setw(13) << "Non-taxable:" << "$" << right << setw(8) << fixed << setprecision(2) << nonTaxable << endl;
    cout << left << setw(13) << "Total:" << "$" << right << setw(8) << fixed << setprecision(2) << total << endl;

    return 0;
}