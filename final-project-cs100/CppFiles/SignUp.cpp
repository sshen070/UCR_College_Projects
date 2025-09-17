#include <iostream>
#include <string>

#include "../HeaderFiles/AccountDatabase.h"
#include "../HeaderFiles/Librarian.h"
#include "../HeaderFiles/User.h"
#include "../HeaderFiles/Account.h"

using namespace std;

SignUp::SignUp(){}

SignUp::SignUp(const string& _userName, const string& _password): userName(_userName), password(_password), userType("User"){}

void SignUp::signUp(vector <Account>& accountDatabase) {
    cout << "Enter an Username: ";
    cin >> userName;

    while (!userNameAvailability(userName, accountDatabase)) {
        cout << "Username already in use... Choose a different userName." << endl;
        cin >> userName;
    }

    cout << "Enter a password: ";
    cin >> password;
    cout << endl;

    char userInput;
    cout << "One final question are you a librarian (y/n): ";
    cin >> userInput;

    if (userInput == 'y') {
        userType = "Librarian";
    }

    cout << "Getting things ready..." << endl;
    createAccount(accountDatabase);
}
    
bool SignUp::userNameAvailability(const string& userName, vector <Account>& accountDatabase) {
    for (int i = 0; i < accountDatabase.size(); i++) {
        if ((accountDatabase.at(i)).getUserName() == userName) {
            return false;
        }
    }
    return true;
}

void SignUp::createAccount(vector<Account>& accountDatabase) {
    if (userType == "Librarian") {
        accountDatabase.push_back(Librarian(userName, password, userType));
    }
    else {
        accountDatabase.push_back(User(userName, password, userType));
    }
}


    
