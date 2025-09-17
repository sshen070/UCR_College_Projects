#include "../HeaderFiles/UserMenu.h"
#include "../HeaderFiles/User.h"


void UserMenu::displayMenu(Library& lib, User& user){ 

    int userInput, insideIfInput;
    string specialInput;
    cout << endl;
    cout << "What would you like to do?" << endl;
    
    cout << "Press (0) to log out" << endl;
    cout << "Press (1) to view book availability" << endl;
    cout << "Press (2) to check out a book" << endl;
    cout << "Prese (3) to return a book" << endl;
    cout << "Press (4) for account info" << endl;

    cin >> userInput;

    while (userInput != 0) {
        if (userInput < 0 && userInput > 4) {
            cout << "Please input a value 1-4" << endl;
        }

        else if (userInput == 1) {
            cout << "you are viewing book availability " << endl;
            cout << "All available books: " << endl;
            lib.printLibrary();
            cout << endl;

            cout << "Please enter the title of the book: " << endl;
            string findTitle;
            cin.ignore();
            getline(cin, findTitle);

            user.viewBook(findTitle, lib);
            //throw runtime_error("Not yet implemented yet!");
            // cout << "Press (1) to view a rating" << endl;
            // cout << "Press (2) view a genre" << endl;
            // cout << "Press (3) to browse popular reviews" << endl;
        }

        else if (userInput == 2) {
            cout << "you are checking out a book" << endl;
            cout << "Please enter the title of the book: " << endl;
            string title = "";
            cin >> title;

            while(!user.checkOutBook(title, lib)){
                cout << endl;
                cout <<  "Do you wish to Exit " << endl;
                int ans = 0;
                cout << "Press (1) to Re-Enter title " << endl;
                cout << "Press (2) to Exit " << endl;
                cin >> ans;

                if(ans == 1){
                    cout << "Please enter the title of the book: " << endl;
                    cin >> title;
                    cout << endl;
                }
                else{
                    break;
                }
            }

            // cout << "Press (1) to add a book" << endl;
            // cout << "Press (2) to remove a book" << endl;
        }
        
        else if(userInput == 3) {
            cout << "you are returning a book " <<  endl;

            cout << "Please enter the title of the book: " << endl;
            string title = "";
            cin >> title;

            while(!user.returnBook(title, lib)){
                cout << endl;
                cout <<  "Do you wish to Exit " << endl;
                int ans = 0;
                cout << "Press (1) to Re-Enter title " << endl;
                cout << "Press (2) to Exit " << endl;
                cin >> ans;

                if(ans == 1){
                    cout << "Please enter the title of the book: " << endl;
                    cin >> title;
                    cout << endl;
                }
                else{
                    break;
                }
            }
            

            //return book here
        }

        else if (userInput == 4){
            cout << " You are looking at Account Info " << endl;
            // cout << "Press (1) to view books checked out" << endl;
            // cout << "Press (2) to pay late fees" << endl;
            cout << "Press (3) for account details" << endl; 
            
            cin >> insideIfInput;
            if (insideIfInput == 3) {
                cout << "Press (1) to edit/modify your account" << endl; 
                cout << "Press (2) to delete your account" << endl; 

                cin >> insideIfInput;

                if (insideIfInput == 1) {
                    cout << "Would you like to change your userName or password?" << endl;
                    cin >> specialInput;

                    if (specialInput == "userName") {
                        cout << "Enter your new userName: " << endl;
                        cin >> specialInput;
                        
                        user.changeUserName(user, specialInput);
                    }

                    if (specialInput == "password") {
                        cout << "Enter your new password: " << endl;
                        cin >> specialInput;
                        
                        user.changeUserName(user, specialInput);
                    }
                }
            }
        }

        cout << endl;
        cout << "What would you like to do?" << endl;
    
        cout << "Press (0) to log out" << endl;
        cout << "Press (1) to view book availability" << endl;
        cout << "Press (2) to check out a book" << endl;
        cout << "Prese (3) to return a book" << endl;
        cout << "Press (4) for account info" << endl;

        cin >> userInput;
    }

    if (userInput == 0) {
        cout << "Thanks for visiting the library!" << endl;
        cout << "Logging out..." << endl;
    }
}

