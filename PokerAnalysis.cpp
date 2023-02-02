#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

string card (int number);
void shuffle (int deck[52], int times=338);
void deal (int deck[52], int dealDeck[5]);
void sort (int dealDeck[5]);
int analyzeHand(int sortedDeck[5]);

string card (int number){
    string cardName = "";
   
    int rank = number / 4 + 1;
    char rankChar;
    int suitNum = number % 4;
    char suit;
   
    if (suitNum == 0){
        suit = 'S';
    } else if (suitNum == 1){
        suit = 'H';
    } else if (suitNum == 2){
        suit = 'D';
    } else if (suitNum == 3){
        suit = 'C';
    }

    switch (rank){
        case 1:
            rankChar = 'A';
            cardName.push_back(rankChar);
            break;
        case 2:
            rankChar = '2';
            cardName.push_back(rankChar);
            break;
        case 3:
            rankChar = '3';
            cardName.push_back(rankChar);
            break;
        case 4:
            rankChar = '4';
            cardName.push_back(rankChar);
            break;
        case 5:
            rankChar = '5';
            cardName.push_back(rankChar);
            break;
        case 6:
            rankChar = '6';
            cardName.push_back(rankChar);
            break;
        case 7:
            rankChar = '7';
            cardName.push_back(rankChar);
            break;
        case 8:
            rankChar = '8';
            cardName.push_back(rankChar);
            break;
        case 9:
            rankChar = '9';
            cardName.push_back(rankChar);
            break;
        case 10:
            cardName.push_back('1');
            cardName.push_back('0');
            break;
        case 11:
            rankChar = 'J';
            cardName.push_back(rankChar);
            break;
        case 12:
            rankChar = 'Q';
            cardName.push_back(rankChar);
            break;
        case 13:
            rankChar = 'K';
            cardName.push_back(rankChar);
            break;
    }
    cardName.push_back(suit);
    
    return cardName;
}

void shuffle(int deck[52], int times){
    unsigned int randomIndex1;
    unsigned int randomIndex2;
    int item1;

    for (int i = 0; i < times; i++){
        randomIndex1 = rand() % 52;
        randomIndex2 = rand() % 52;

        item1 = deck[randomIndex1];

        deck[randomIndex1] = deck[randomIndex2];
        deck[randomIndex2] = item1;
    }
}

void deal (int deck[52], int dealDeck[5]){
    for (unsigned int i = 0; i < 5; i++){
        dealDeck[i] = deck[i];
    }
}

void sort (int dealDeck[5]){
    unsigned int i = 0;
    int item1;
    bool valid = false;

    while (valid == false){
        valid = true;
        for (i = 1; i < 5; i++){
            if (dealDeck[i-1] > dealDeck[i]){
                valid = false;
                item1 = dealDeck[i-1];

                dealDeck[i-1] = dealDeck[i];
                dealDeck[i] = item1;
            }
        }
    }
}

int analyzeHand(int sortedDeck[5]){
    int type = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int rank = 0;

    bool flush = true;
    bool straightUp = true;
    bool straightDown = true;
    bool straight = false;
    bool threeOfAKind = false;

    /*go from highest to lowest*/

    // 8: one pair
    for (i = 0; i < 5; i++){
        for (j = 0; j < 5; j++){
            if ((i != j) && ((sortedDeck[i] / 4 + 1) == (sortedDeck[j] / 4 + 1))){
                type = 8;
                rank = sortedDeck[i] / 4 + 1;
            }
        }
    }

    // 7: two pair
    if (type == 8){
        for (k = 0; k < 5; k++){
            for (l = 0; l < 5; l++){
                if ((k != l) && ((sortedDeck[k] / 4 + 1) == (sortedDeck[l] / 4 + 1)) && (sortedDeck[k] / 4 + 1 != rank)){
                    type = 7;
                }
            }
        }
    }

    // 6: three of a kind
    for (i = 0; i < 5; i++){
        for (j = 0; j < 5; j++){
            for (k = 0; k < 5; k++){
                if (i != j && j != k && i != k){
                    if ((sortedDeck[i] / 4 + 1) == (sortedDeck[j] / 4 + 1) && (sortedDeck[j] / 4 + 1) == (sortedDeck[k] / 4 + 1)){
                        type = 6;
                        threeOfAKind = true;
                        rank = sortedDeck[i] / 4 + 1;
                    }
                }
            }
        }
    }

    // 5: straight
    for (i = 1; i < 5; i++){
        if (sortedDeck[i] / 4 + 1 != sortedDeck[i - 1] / 4 + 2){
            straightUp = false;
        }
    }
    for (i = 1; i < 5; i++){
        if (sortedDeck[i] / 4 + 2 != sortedDeck[i - 1] / 4 + 1){
            straightDown = false;
        }
    }
    if (straightUp == true || straightDown == true){
        straight = true;
        type = 5;
    }

    // 4: flush
    for (i = 1; i < 5; i++){
        if (sortedDeck[i] % 4 != sortedDeck[i-1] % 4){
            flush = false;
        }
    }
    if (flush == true){
        type = 4;
    }

    // 3: full house
    if (threeOfAKind == true){
        for (i = 0; i < 5; i++){
            for (j = 0; j < 5; j++){
                if (i != j){
                    if (sortedDeck[i] / 4 + 1 == sortedDeck[j] / 4 + 1){
                        if (sortedDeck[i] / 4 + 1 != rank){
                            type = 3;
                        }
                    }
                }
            }
        }
    }

    // 2: four of a kind
    for (i = 0; i < 5; i++){
        for (j = 0; j < 5; j++){
            for (k = 0; k < 5; k++){
                for (l = 0; l < 5; l++){
                    if (i != j && i != k && i != l && j != k && j != l && k != l){
                        if (
                            (sortedDeck[i] / 4 + 1) == (sortedDeck[j] / 4 + 1) && 
                            (sortedDeck[j] / 4 + 1) == (sortedDeck[k] / 4 + 1) &&
                            (sortedDeck[k] / 4 + 1) == (sortedDeck[l] / 4 + 1)
                            ){
                            type = 2;
                            threeOfAKind = true;
                            rank = sortedDeck[i] / 4 + 1;
                        }
                    }
                }
            }
        }
    }

    // 1: straight flush
    if (flush == true){
        if (straight == true){
            type = 1;
        }
    }

    // 9: high card
    if (type == 0){
        type = 9;
    }
    return type;
}

int main(){
    // [1s,1h,1d,1c, 2s,2h,2d,2c ... ]
    unsigned int i = 0;
    unsigned int j = 0;
    int k = 0;
    int theDeck[52] = {};
    int hand[5] = {};
    int seed;
    int hands;
    int analysis;

    cout << "Enter the seed value : ";
    cin >> seed;

    srand(seed);

    for (i = 0; i < 52; i++){
        theDeck[i] = i;
    }

    for (i = 0; i < 5; i++){
        shuffle(theDeck);
        deal(theDeck, hand);
        sort(hand);
        for (j = 0; j < 5; j++){
            cout << card(hand[j]) << " ";
        }
        cout << endl;

    }

    cout << "Enter the number of hands : ";
    cin >> hands;

    int bucket[10] = {};

    for (k = 0; k < hands; k++){
        shuffle(theDeck);
        deal(theDeck, hand);
        sort(hand);
        analysis = analyzeHand(hand);
        bucket[analysis]++;
    }

    cout << setw(25) << left << "Straight Flush" << right << bucket[1] << setw(9) << right << fixed << setprecision(5) << 100.00 * bucket[1] / abs(hands) << '%' << endl;
    cout << setw(25) << left << "Four of a Kind" << right << bucket[2] << setw(9) << right << fixed << setprecision(5) << 100.00 * bucket[2] / abs(hands) << '%' << endl;
    cout << setw(25) << left << "Full House" << right << bucket[3] << setw(9) << right << fixed << setprecision(5) << 100.00 * bucket[3] / abs(hands) << '%' << endl;
    cout << setw(25) << left << "Flush" << right << bucket[4] << setw(9) << right << fixed << setprecision(5) << 100.00 * bucket[4] / abs(hands) << '%' << endl;
    cout << setw(25) << left << "Straight" << right << bucket[5] << setw(9) << right << fixed << setprecision(5) << 100.00 * bucket[5] / abs(hands) << '%' << endl;
    cout << setw(25) << left << "Three of a Kind" << right << bucket[6] << setw(9) << right << fixed << setprecision(5) << 100.00 * bucket[6] / abs(hands) << '%' << endl;
    cout << setw(25) << left << "Two Pair" << right << bucket[7] << setw(9) << right << fixed << setprecision(5) << 100.00 * bucket[7] / abs(hands) << '%' << endl;
    cout << setw(25) << left << "One Pair" << right << bucket[8] << setw(9) << right << fixed << setprecision(5) << 100.00 * bucket[8] / abs(hands) << '%' << endl;
    cout << setw(25) << left << "High Card" << right << bucket[9] << setw(9) << right << fixed << setprecision(5) << 100.00 * bucket[9] / abs(hands) << '%' << endl;
}