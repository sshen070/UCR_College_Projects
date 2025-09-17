#include <iostream>
#include <string>
#include <vector>

#include "../HeaderFiles/AccountDatabase.h"
#include "../HeaderFiles/Login.h"
#include "../HeaderFiles/Account.h"

using namespace std;

Login::Login(){}

Login::Login(const string& _userName, const string& _password) : userName(_userName), password(_password) {}


bool Login::login(vector<Account>& accountDatabase) {
    cin.ignore();
    cout << "UserName: ";
    getline(cin, userName);
    
    int iterationCt = 0;
    while (!userNameValid(accountDatabase, userName)) {
        cout << "UserName invalid! Please try again." << endl;
        cout << "UserName: "; 
        getline(cin, userName);

        if (iterationCt >= 2) {
            char userInput;
            cout << "Did you forget your userName? (y/n): ";
            cin >> userInput;
            if (userInput == 'y') {
                return false;
            }
            else {
                iterationCt = 0;
            }
        }
        iterationCt++;
    }

    cout << "Password: "; 
    getline(cin, password);
    
    while (!passwordValid(accountDatabase, password)) {
        cout << "Password invalid! Please try again: " << endl;
        cout << endl;
        cout << "Password: "; 
        getline(cin, password);
    }
    cout << "Logging in..." << endl;
    return true;
}


bool Login::userNameValid(vector<Account>& accountDatabase, const string& _userName) {
    for (int i = 0; i < accountDatabase.size(); i++) {
        if ((accountDatabase.at(i)).getUserName() == _userName){
            return true;
        }
    }
    return false;
}


bool Login::passwordValid(vector<Account>& accountDatabase, const string& _password) {
    for (int i = 0; i < accountDatabase.size(); i++) {
        if (accountDatabase.at(i).getPassword() == _password){
            return true;
        }
    }
    return false;
}
