#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double degrees, radians;

	cout << "Enter an angle in degrees: ";
	cin >> degrees;
    cout << endl;
    
    double pi = acos(-1);
    radians = degrees * (pi/180);
    
    cout << "Angle in radians: " << radians << endl;
    cout << "sine(" << radians << ") = " << sin(radians) << endl;
    cout << "cosine(" << radians << ") = " << cos(radians) << endl;
    cout << "tangent(" << radians << ") = " << tan(radians) << endl;

	return 0;
}