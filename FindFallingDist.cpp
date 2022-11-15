#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double getSeconds();
double findEarthFallDist(double fallTime);
double findMoonFallDist(double fallTime);
void displayResults(double earthDist, double moonDist, double fallTime);

int main(){
    double seconds = getSeconds();
    double earth = findEarthFallDist(seconds);
    double moon = findMoonFallDist(seconds);
    displayResults(earth, moon, seconds);
    return 0;
}

/*
Purpose: Get the fall time input from user
Inputs: Fall time input
Outputs: Returns fall time
*/
double getSeconds(){
    do {
        double fallTime;
        cout << "Please enter the fall time (in seconds): ";
        cin >> fallTime;
        if (fallTime < 0){
            cout << "Error the fall time must be 0 or more." << endl;
        } else {
            return fallTime;
        }
    } while (true);
}

/*
Purpose: Find the fall distance on Earth
Inputs: fallTime parameter
Outputs: Calculated fall distance on Earth
*/
double findEarthFallDist(double fallTime){
    return (0.5 * 9.81 * pow(fallTime, 2));
}


/*
Purpose: Find the fall distance on the Moon
Inputs: fallTime parameter
Outputs: Calculated fall distance on the Moon
*/
double findMoonFallDist(double fallTime){
    return (0.5 * 1.625 * pow(fallTime, 2));
}

/*
Purpose: Display the results from previous calculations
Inputs:
    - Parameter earthDist: Fall distance on Earth
    - Parameter moonDist: Fall distance on the Moon
    - Parameter fallTime: Fall time in seconds
Outputs: Formatted results of previous calculations
*/
void displayResults(double earthDist, double moonDist, double fallTime){
    cout << "\nThe object traveled " << fixed << setprecision(3) << earthDist << " meters in " << fixed << setprecision(1) << fallTime << " seconds on Earth." << endl;
    cout << "The object traveled " << fixed << setprecision(3) << moonDist<< " meters in " << fixed << setprecision(1) << fallTime << " seconds on the Moon." << endl;
}