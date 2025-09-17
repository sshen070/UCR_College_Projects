#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>

using namespace std;

class Account {
 protected:
   string userName;
   string password;
   string userType;

 public:
   // Account -> abstract class (no account object)
   virtual ~Account();
   virtual string getUserType();

   string getUserName();
   string getPassword();
   void setName(const string&);
   void setPassword(const string&);
};

#endif
