#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    unsigned int medium;
    double distance;
    double time;
    const double airSpeed = 1133.2;
    const double waterSpeed = 4871.0;
    const double steelSpeed = 16400.0;

    cout << "\tTime for Sound to Travel through a Medium given Distance" << endl;
    cout << endl;
    cout << "1 - Air" << endl;
    cout << "2 - Water" << endl;
    cout << "3 - Steel" << endl;
    cout << endl;

    cout << "Enter the number of the medium: ";
    cin >> medium;

    if (!(medium > 0 && medium < 4)){
        cout << "\nthe entry is invalid. run the program again." << endl;
        return 0;
    }

    cout << "\nEnter the distance to travel (in feet): ";
    cin >> distance;
    if (distance <= 0){
        cout << "\nthe distance must be greater than zero" << endl;
        return 0;
    }

    switch (medium) {
        case 1:
            time = distance / airSpeed;
            cout << "In air it will take " << fixed << setprecision(4) << time << " seconds to travel " << distance << " feet." << endl;
            break;
        case 2:
            time = distance / waterSpeed;
            cout << "In water it will take " << fixed << setprecision(4) << time << " seconds to travel " << fixed << setprecision(4) << distance << " feet." << endl;
            break;
        case 3:
            time = distance / steelSpeed;
            cout << "In steel it will take " << fixed << setprecision(4) << time << " seconds to travel " << fixed << setprecision(4) << distance << " feet." << endl;
            break;
    }

    return 0;
}