#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include <string>
#include <vector>
#include <iostream>

#include "Book.h"
#include "Account.h"
// #include "SearchAccount.h"
// #include "LibrarianMenu.h"
#include "Library.h"

using namespace std;

class Librarian: public Account{
 public:
   Librarian();
   Librarian(const string&, const string&, const string&);

   string getUserType() override;
  // //  LibrarianMenu menu;
  //  void viewBook();
  //  void addBook(Library&);
  //  void removeBook(Library&);
};

#endif