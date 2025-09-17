#ifndef LIBRARY_H
#define LIBRARY_H


#include <string>
#include <vector>

// Not yet implemented -> must be implemented before Library.h
#include "Book.h"

using namespace std;

class Library {
 private:
    

 public:
   vector<Book> bookCollection;
   
    Library();
    void editBook(Book);
    void addBookToLibrary(const string& , const string&, int , int, const string&, int);
    bool addBookToLibraryUser(const string&);
    bool removeBookFromLibrary(const string&);
    void printLibrary();

    Book* bookIfExists(const string&);
};

#endif