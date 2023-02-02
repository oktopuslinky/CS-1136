#include <iostream>
#include <iomanip>

using namespace std;

/*
Purpose: Get the information about the order from the user
Inputs:
    orderedSpools - Integer (passed by reference): Number of ordered spools
    stockSpools - Integer (passed by reference): Number of spools in stock
    charge - Char (passed by reference): Whether or not there is a shipping charge
    sahCharge - Double (passed by reference): Shipping and handling charge
Outputs: None
*/
void getOrder(int& orderedSpools, int& stockSpools, char& charge, double& sahCharge){
    sahCharge = 20.95;

    do {
        cout << "Please enter the number of spools ordered: ";
        cin >> orderedSpools;
        if (orderedSpools < 1) {
            cout << "Error, the number of spools must be at least 1." << endl;
        }
    } while (orderedSpools < 1);

    do {
        cout << "Please enter the number of spools in stock: ";
        cin >> stockSpools;
        if (stockSpools < 0){
            cout << "Error, the spools in stock should be 0 or more." << endl;
        }
    } while (stockSpools < 0);

    cout << "Is there a custom shipping and handling charge (Enter Y for Yes or N for No)? ";
    cin >> charge;

    if (charge == 'Y' || charge == 'y'){
        do {
            cout << "What is the shipping and handling charge? ";
            cin >> sahCharge;
            if (sahCharge < 0.00){
                cout << "Error, the charge must be at least $0.00." << endl;
            }
        } while (sahCharge < 0.00);
    }
}

/*
Purpose: Calculate the number of spools that are ready for shipping and on backorder
Inputs:
    orderedSpools - Integer (passed by reference): Number of ordered spools
    stockSpools - Integer (passed by reference): Number of spools in stock
    orderNumbers - Integer array: Contains the number of spools ready for shipping [0] and on backorder [1]
Outputs: None
*/
void CalcOrderNum(int& orderedSpools, int& stockSpools, int orderNumbers[]){
    // orderNumbers: [ready, backOrder]
    orderNumbers[1] = 0;

    if (stockSpools < orderedSpools){
        orderNumbers[0] = stockSpools;
        orderNumbers[1] = orderedSpools - stockSpools;
    } else {
        orderNumbers[0] = orderedSpools;
    }
}

/*
Purpose: Calculate the charge of the given number of spools
Inputs:
    spools - Integer: Number of spools ordered
Outputs:
    Double: Charge of the given number of spools
*/
double CalcSpoolCharges(int spools){
    return spools * 157.55;
}

/*
Purpose: Calculate the total charge of shipping on the given number of spools
Inputs:
    spools - Integer: Number of spools ordered
    sahCharge - Double: Rate of shipping and handling
Outputs:
    Double: Charge of shipping
*/
double calcShipping(int spools, double sahCharge=20.95){
    return spools * sahCharge;
}

/*
Purpose: Calculate the total charge of everything
Inputs:
    spoolCharges - Double: Charge of the given number of spools
    shipping - Double: Charge of shipping
Outputs:
    Double: Total charge of everything
*/
double CalcTotal(double spoolCharges, double shipping){
    return spoolCharges + shipping;
}

/*
Purpose: Output the details of the order
Inputs:
    shipping - Double: cost of shippping
    spoolCharges - Double: cost of the given number of spools
    totalCharges - Double: total cost of everything
    ready - Integer: number of spools ready for shipping
    backOrder - Integer: number of spools on backorder
Outputs:
    The details of the order on the screen
*/
void OutputOrder(double shipping, double spoolCharges, double totalCharges, int ready, int backOrder){
    cout << "\nSpools ready for shipping: " << ready << endl;
    if (backOrder > 0){
        cout << "Spools on back order: " << backOrder << endl;
    }
    cout << "Charges for " << ready << " spools: $" << fixed << setprecision(2) << spoolCharges << endl;
    cout << "Shipping and handling for " << ready << " spools: $" << fixed << setprecision(2) << shipping << endl;
    cout << "Total charges (Incl. shipping & handling): $" << fixed << setprecision(2) << totalCharges << endl;
}

int main(){
    int orderedSpools;
    int stockSpools;
    char charge;
    double sahCharge;
    double shipping;
    int orderNumbers[2];
    int ready;
    int backOrder;

    getOrder(orderedSpools, stockSpools, charge, sahCharge);
    CalcOrderNum(orderedSpools, stockSpools, orderNumbers);
    ready = orderNumbers[0];
    backOrder = orderNumbers[1];
    double spoolCharges = CalcSpoolCharges(ready);
    shipping = calcShipping(ready, sahCharge);
    double totalCharges = CalcTotal(spoolCharges, shipping);
    OutputOrder(shipping, spoolCharges, totalCharges, ready, backOrder);
}