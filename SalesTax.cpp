#include <iostream>
using namespace std;

int main()
{
    double purchaseAmt, salesTax, countyTax, totalTax;

    cout << "Enter purchase amount:" << endl;
    cin >> purchaseAmt;

    salesTax = 0.06 * purchaseAmt;
    countyTax = 0.02 * purchaseAmt;
    totalTax = salesTax + countyTax;
   
    cout << "State sales tax = $" << salesTax << endl;
    cout << "County sales tax = $" << countyTax << endl;
    cout << "Total sales tax = $" << totalTax << endl;

    return 0;
}