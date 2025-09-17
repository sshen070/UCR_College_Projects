#include <iostream>
#include <string>

#include "../HeaderFiles/Account.h"

using namespace std;

Account::~Account(){}

string Account::getUserType() {
    return userType; 
}

string Account::getUserName(){
    return userName;
}

string Account::getPassword() {
    return password;
}

void Account::setName(const string& newName) {
    userName = newName;
}

void Account::setPassword(const string& newPassword) {
    password = newPassword;
}

