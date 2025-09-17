#ifndef LIBRARYSORTS_H
#define LIBRARYSORTS_H

#include <string>
#include "Library.h"

class LibrarySorts {
public:
    Library bookCollection;

public:
    void sortByAlphabet(Library& sortCollection);
    void sortByRating(Library& sortByAlphabet);
    void sortByGenre(Library& sortCollection);
    void sortByPopularity(Library& sortCollection);
    void sortByAuthor(Library& sortCollection);
    void sortByPbDate(Library& sortCollection);

};

#endif