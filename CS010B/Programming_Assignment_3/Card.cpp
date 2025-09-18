#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

#include "Card.h"

    // Constructors
    Card::Card(){
        suit = 'c';
        rank = 2;
    }

    Card::Card(char userSuit, int userRank){
        // Suit Setup
        suit = tolower(userSuit);
        if (suit != 'c' && suit != 'd' && suit != 'h' && suit != 's'){
            suit = 'c';
        }
        
        // Rank Setup
        if (userRank >= 1 && userRank <= 13){
            rank = userRank;
        }
        else{
            rank = 2;
        }
    }

    // Acessors
    char Card::getSuit() const{
        return suit;
    }
    
    int Card::getRank() const{
        return rank;
    }
    
    ostream & operator<<(ostream &out, const Card &rhs){
        string fullSuit;
        string specialRank;

        if (rhs.suit == 'c'){
            fullSuit = "Clubs";
        }
        else if (rhs.suit == 'd'){
            fullSuit = "Diamonds";
        }      
        else if (rhs.suit == 'h'){
            fullSuit = "Hearts";
        }      
        else if (rhs.suit == 's'){
            fullSuit = "Spades";
        }

        if (rhs.rank >= 2 && rhs.rank <= 10){
            out << rhs.rank << " of " << fullSuit;
        }
        else{
            if(rhs.rank == 1){
                specialRank = "Ace";
            }
            else if (rhs.rank == 11){
                specialRank = "Jack";
            }
            else if (rhs.rank == 12){
                specialRank = "Queen";
            }
            else if (rhs.rank == 13){
                specialRank = "King";
            }
            out << specialRank << " of " << fullSuit;
        }
        return out; 
    }