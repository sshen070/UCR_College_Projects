#ifndef SIGNUP_H
#define SIGNUP_H

#include <string>
#include <vector>

#include "AccountDatabase.h"


using namespace std;

class SignUp {
   private:
    string userName;
    string password;
    string userType;

    // Private helper functions 
    bool userNameAvailability(const string&, vector<Account>&);
    void createAccount(vector<Account>& accountDatabase);
   
   public:
    SignUp();
    SignUp(const string&, const string&);
    void signUp(vector <Account>&);

};

#endif