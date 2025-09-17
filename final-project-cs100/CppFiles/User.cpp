#include <iostream>
#include <string>

#include "../HeaderFiles/Account.h"
#include "../HeaderFiles/User.h"
#include "../HeaderFiles/Library.h"

using namespace std;

// User starts with empty checkout history & no book reccomendations
User::User() {}

User::User(const string& userName, const string& password, const string& userType) {
    this -> userName = userName;
    this -> password = password;
    this -> userType = userType;
}


string User::getUserType() {
    return userType;
}

// // Requires viewBook class
// void User::viewBook() {
// }

// // Requires viewReview
// void User::viewReview() {
// }

Book* User::bookIsCheckedOut(const string& title) {
    // vector<Books>::iterator i;
    // for (i = checkedOut.begin(); i != checkedOut.end(); i++) {
    //     if ((*i).getTitle() == title) {
    //         return true;
    //     }
    // }
    // return false;

    for (int i = 0; i < checkedOut.size(); i++) {
        if (checkedOut.at(i).getTitle() == title) {
            return &checkedOut.at(i);
        }
    }
    return nullptr;
}

bool User::checkOutBook(const string& title, Library& library) {
    Book* bookPtr = library.bookIfExists(title);
    if (library.removeBookFromLibrary(title)) {
        checkedOut.push_back(*bookPtr);
        return true;
    }
    
    else {
        cout << "Sorry, the book you wish to check out is unavailable. Please enter another book you wish check out." << endl;
    }
    return false;
}

bool User::returnBook(const string& title, Library& library) {
    Book* check = bookIsCheckedOut(title);
    if (check) {
        if (library.addBookToLibraryUser(title)) {

            std::swap(*check, checkedOut.at(checkedOut.size() - 1));
            checkedOut.pop_back();
    
            cout << "Success! Book has been returned" << endl;
            return true;
        }    
    }

    else {
        cout << "Sorry, the book you entered is not checked out. Please enter another book you wish to return." << endl;
    }
    return false;    
}

void User::viewBook(const string& title, Library& library) {
    Book* printBook = library.bookIfExists(title);
    
    if (printBook == nullptr) {
        cout << "Book not found in the library." << endl;
        return;
    }
    ViewBook view;
    view.viewBook(*printBook);
}

void User::changeUserName(User& user, const string& newUserName) {
    user.userName = newUserName;
}

void User::changePassword(User& user, const string& newPassword) {
    user.password = newPassword;
}