#ifndef ACCOUNTDATABASE_H
#define ACCOUNTDATABASE_H

#include <string>
#include <vector>

#include "Account.h"
#include "Login.h"
#include "SignUp.h"
#include "UserMenu.h"
#include "User.h"
#include "Library.h"

using namespace std;

class AccountDatabase {
 private:
   vector<Account> accountDatabase;
   // Login loginScreen;
   // SignUp signUpScreen;

   // Do these functions belong in AccountDatabase?
  //  void deleteAccount(Account&);
  //  void editAccount(Account&);
  //  void printMenu();


 public:
   AccountDatabase();
   void viewOptions(Library&);

};

#endif