#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

#include "Account.h"
// #include "Reccomendations.h"
// #include "UserMenu.h"
#include "Book.h"
#include "Library.h"

using namespace std;

class User: public Account{
 private:
  //  Reccomendations reccomendations;
  //  UserMenu menu;
   vector <Book> checkedOut;
   Book* bookIsCheckedOut(const string&);

 public:
   User();
   User(const string&, const string&, const string&);
   string getUserType() override;
   void viewBook(const string&, Library&);
   bool checkOutBook(const string&, Library&);
   bool returnBook(const string&, Library&);
   void changeUserName(User&, const string&);
   void changePassword(User&, const string&);

};

#endif