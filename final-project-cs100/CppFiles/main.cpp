#include <iostream>
#include <vector>
#include "../HeaderFiles/AccountDatabase.h"
#include "../HeaderFiles/Account.h"
#include "../HeaderFiles/User.h"
#include "../HeaderFiles/Librarian.h"
#include "../HeaderFiles/SignUp.h"
#include "../HeaderFiles/Login.h"

using namespace std;

int main() {
    AccountDatabase database; // Vector to store user accounts

    Library library;
    // Adding some sample accounts
    database.viewOptions(library);

    //cout << "Login successful! Welcome to the system." << endl;

    return 0;
}