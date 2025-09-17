#ifndef LOGIN_H
#define LOGIN_H

#include <string>
#include <vector>

#include "AccountDatabase.h"


using namespace std;

class Login {
   private: 
    string userName;
    string password;
    
    // Private helper functions
    bool userNameValid(vector<Account>&, const string&);
    bool passwordValid(vector<Account>&, const string&);

   public:
    Login();
    Login(const string&, const string&);
    bool login(vector<Account>&);
};

#endif