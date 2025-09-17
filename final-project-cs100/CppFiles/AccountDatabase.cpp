#include <iostream>
#include <string>

#include "../HeaderFiles/AccountDatabase.h"
#include "../HeaderFiles/Account.h"

using namespace std;

AccountDatabase::AccountDatabase() {}

// Required call for user to see option and interact with SignUp & Login features (abstraction)
void AccountDatabase::viewOptions(Library& lib) {
    cout << "Welcome to the UCR Library!" << endl;
    
    char userInput;
    cout << "Do you already have an account with us? (y/n): ";
    cin >> userInput;
    
    // Fixing infinite loop: Correcting condition
    while (userInput != 'y' && userInput != 'n') { 
        cout << "Invalid input, please type y(yes) or n(no): ";
        cin >> userInput;
    }
    // Changed here, the .h file, and reccomendations (Brandon Ng)
    if (userInput == 'n') {
        SignUp().signUp(accountDatabase);
        cout << endl;
    }
    
    bool check = Login().login(accountDatabase);

    if (!check) {
        cout << "Please make a new account." << endl;
        cout << endl;
        viewOptions(lib);
    }

    //Add userMenu/LibrarianMenu call here:
    
    if (userInput == 'n'){
        string name = "stub";
        string password = "stub";
        string userT = "user";
        User stub(name,password,userT);
        UserMenu().displayMenu(lib, stub);
    }
    else{
        
    }
    
}


// void printMenu() {
//     int userInput, insideIfInput;
//     string specialInput;
//     cout << "What would you like to do?" << endl;
    
//     cout << "Press (0) to log out" << endl;
//     cout << "Press (1) to view book availability" << endl;
//     cout << "Press (2) to add/remove a book" << endl;
//     cout << "Press (3) for account info" << endl;

//     cin >> userInput;

//     while (userInput != 0) {
//         if (userInput < 0 && userInput > 3) {
//             cout >> "Please input a value 1-3" << endl;
//         }

//         else if (userInput == 1) {
//             throw runtime_error("Not yet implemented yet!")
//             // cout << "Press (1) to view a rating" << endl;
//             // cout << "Press (2) view a genre" << endl;
//             // cout << "Press (3) to browse popular reviews" << endl;
//         }

//         else if (userInput == 2) {
//             throw runtime_error("Not yet implemented yet!")

//             // cout << "Press (1) to add a book" << endl;
//             // cout << "Press (2) to remove a book" << endl;
//         }
        
//         else if (userInput == 3){
//             // cout << "Press (1) to view books checked out" << endl;
//             // cout << "Press (2) to pay late fees" << endl;
//             cout << "Press (3) for account details" << endl; 
            
//             cin >> insideIfInput;
//             if (insideIfInput == 3) {
//                 cout << "Press (1) to edit/modify your account" << endl; 
//                 cout << "Press (2) to delete your account" << endl; 

//                 cin >> insideIfInput;

//                 if (insideIfInput == 1) {
//                     cout << "Would you like to change your userName or password?" << endl;
//                     cin >> specialInput;

//                     if (specialInput == "userName") {
//                         cout << "Enter your new userName: ";
//                         cin >> 
//                     }

//                 }
//             }
//         }
//         cin >> userInput;
//     }

//     if (userInput == 0) {
//         cout << "Thanks for visiting the library!" << endl;
//         cout << "Logging out..." << endl;
//     }
// }