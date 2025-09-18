#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

#include "Deck.h"
#include "Card.h"

// Returns true if vector of Cards passed in contains at least 2 Cards with the same rank.
bool hasPair(const vector<Card> &);

// Sends to output stream a hand of Cards on a single line, 
// each Card separated by a comma.
// If the vector is empty, do not output anything.
// Example (vector size of 3): Ace of Spades, Two of Hearts, King of Clubs 
ostream & operator<<(ostream &, const vector<Card> &);

int main() {
    srand(2222);

    Deck deck1;
    string response;
    string fileName;
    unsigned cardsInHand = 0;
    unsigned numPairs = 0;
    unsigned totalSimulations = 0;
    vector <Card> mainHands;
    ofstream outFS;
    
    // Card Card1;
    // for (int i = 0; i < 52; i++){
    //     cout << deck1.theDeck.at(i) << endl;
    // }

    cout << "Do you want to output all hands to a file?(Yes/No) ";
    cin >> response;
    cout << endl;
    
    if (response == "Yes"){
        cout << "Enter name of output file: ";
        cin >> fileName;
        cout << endl;

        outFS.open(fileName);

        if (!outFS.is_open()){
            cout << "Error " << fileName << " is not open!" << endl;
            return 1;
        }

        cout << "Enter number of cards per hand: ";
        cin >> cardsInHand;
        cout << endl;

        cout << "Enter number of deals (simulations): ";
        cin >> totalSimulations;
        cout << endl;

        for (unsigned int i = 0; i < totalSimulations; i++){
            deck1.shuffleDeck();
            for (unsigned int i = 0; i < cardsInHand; i++){
                mainHands.push_back(deck1.dealCard());
            }
            if (hasPair(mainHands)){
                numPairs++;
            }
            outFS << mainHands;
            mainHands.clear();
        }
        outFS.close();
    }
    else{
        cout << "Enter number of cards per hand: ";
        cin >> cardsInHand;
        cout << endl;

        cout << "Enter number of deals (simulations): ";
        cin >> totalSimulations;
        cout << endl;

        for (unsigned int i = 0; i < totalSimulations; i++){
            deck1.shuffleDeck();
            for (unsigned int i = 0; i < cardsInHand; i++){
                mainHands.push_back(deck1.dealCard());
            }
            if (hasPair(mainHands)){
                numPairs++;
            }
            mainHands.clear();
        }
    }
    cout << "Chances of receiving a pair in a hand of " << cardsInHand << " cards is: " << (static_cast<double>(numPairs) / totalSimulations) * 100 << "%" << endl;

    // for (unsigned int i = 0; i < deck1.theDeck.size(); i++){
    //     cout << deck1.theDeck.at(i).getRank() << " "<< deck1.theDeck.at(i).getSuit() << endl;
    //     cout << deck1.theDeck.size();
    // }

    return 0;
}

bool hasPair(const vector<Card> &hand){
    for (unsigned int i = 0; i < hand.size(); i++){
        for (unsigned int j = i + 1; j < hand.size(); j++){
            if (hand.at(i).getRank() == hand.at(j).getRank()){
                return true;
            }
        }
    }
    return false;
}

ostream & operator<<(ostream &out, const vector<Card> &dealtCards){
    if (hasPair(dealtCards)){
        out << "Found Pair!! ";
    }
    else{
        out << "             ";
    }

    for (unsigned int i = 0; i < dealtCards.size(); i++){
        out << dealtCards.at(i);
        if (i < dealtCards.size() - 1){
            out << ", ";
        }
    }
    out << endl;
    return out;
}
