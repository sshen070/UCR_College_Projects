#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

#include "Deck.h"

    Deck::Deck(){
        for (int i = 1; i <= 4; i++){
            for (int j = 13; j >= 1; j--){
                if (i == 1){
                    theDeck.push_back(Card('s', j));
                }
                else if (i == 2){
                    theDeck.push_back(Card('h', j));
                }
                else if (i == 3){
                    theDeck.push_back(Card('d', j));
                }
                else if (i == 4){
                    theDeck.push_back(Card('c', j));
                }
            }
        }
    }

    Card Deck::dealCard(){
        Card topCard = theDeck.back();
        dealtCards.push_back(topCard);
        theDeck.pop_back();
        return topCard;
    }

    void Deck::shuffleDeck(){
        for (unsigned int i = 0; i < dealtCards.size(); i++){
            theDeck.push_back(dealtCards.at(i));
        }
        dealtCards.clear();
        random_shuffle(theDeck.begin(), theDeck.end());
    }
    
    unsigned Deck::deckSize() const{
        return theDeck.size();
    }
