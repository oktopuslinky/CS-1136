#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

int main(){
    unsigned int seed;
    int flip;
    double heads = 0;
    double tails = 0;
    char choice;

    cin >> seed;
    srand(seed);

    while (true){
        flip = (rand() % 2) + 1;
        if (flip == 1){
            heads += 1;
            cout << "Flip = Heads" << endl;
        } else if (flip == 2){
            tails += 1;
            cout << "Flip = Tails" << endl;
        }

        cout << "Would you like to flip again?" << endl;
        cout << "Enter Y for Yes or N for No: ";
        
        while (true){
            cin >> choice;
            if (choice == 'N' || choice == 'n'){
                cout << fixed << setprecision(0) << heads << " of the " << heads + tails << " flips were Heads or " << fixed << setprecision(1) << (heads / (heads + tails)) * 100 << "% were Heads." << endl;
                cout << fixed << setprecision(0) << tails << " of the " << heads + tails << " flips were Tails or " << fixed << setprecision(1) << (tails / (heads + tails)) * 100 << "% were Tails." << endl;
                return 0;
            } else if (choice == 'Y' || choice == 'y'){
                break;
            } else {
                cout << "The input is invalid";
            }
        }
    }
}