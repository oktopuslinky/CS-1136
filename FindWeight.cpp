#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(){
    double mass;

    // represents the object being heavy or light
    string lifting = "";
    
    cout << "Enter the mass of an object in kilograms: ";
    cin >> mass;

    if (mass <= 0){
        cout << "\nThe mass must be greater than zero" << endl;
        return 0;
    }

    // weight in newtons for each planet
    const double EARTH = mass * 9.807;
    const double VENUS = mass * 8.87;
    const double MARS = mass * 3.7;

    if (EARTH > 1500){
        lifting = "The object is heavy";
    } else if (EARTH < 5) {
        lifting = "The object is light";
    }

    cout << setw(6) << left << "Planet";
    cout << '\t' << setw(14) << right << "Weight (N)" << endl;
    cout << endl;

    if (lifting.length() > 0){
        cout << left << setw(6) << "Earth" << '\t' << setw(14) << right << fixed << setprecision(4) << EARTH << '\t' << lifting << endl;
    } else{
        cout << left << setw(6) << "Earth" << '\t' << setw(14) << right << fixed << setprecision(4) << EARTH << endl;
    }
    cout << left << setw(6) << "Venus" << '\t' << setw(14) << right << fixed << setprecision(4) << VENUS << endl;
    cout << left << setw(6) << "Mars" << '\t' << setw(14) << right << fixed << setprecision(4) << MARS << endl;

    return 0;
}