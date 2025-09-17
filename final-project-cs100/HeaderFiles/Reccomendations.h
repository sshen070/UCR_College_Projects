#ifndef RECCOMENDATIONS_H
#define RECCOMENDATIONS_H

#include <string>
#include <vector>
#include "User.h"
#include "Book.h"

using namespace std;

class Reccomendations{
 public:
    vector<Book> bookRecomendations;
    void generateReccomendationsByGenre();
    void generateReccomendationsByAuthor();
    void generateReccomendationsByDate();
};

#endif