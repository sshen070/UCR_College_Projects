#include <iostream>
#include <string>

#include "../HeaderFiles/Book.h"
#include "../HeaderFiles/Library.h"
#include "../HeaderFiles/Account.h"
#include "../HeaderFiles/Librarian.h"


using namespace std;

Librarian::Librarian(){}

Librarian::Librarian(const string& userName, const string& password, const string& userType) {
    this -> userName = userName;
    this -> password = password;
    this -> userType = userType;
}

string Librarian::getUserType(){
    return userType;
}

// void Librarian::addBook(Library& lib){

//     //get book title
//     string titleBook = "";
//     cout<<"Please Enter the Title of the Book: "<<endl;
//     cin >> titleBook;

//     //get vector of genres
//     string genre = "";
//     cout<<"Please Enter Genre of Book"<<endl;
//     cin >> genre;
    

//     //get popularity of book
//     int salesBook = 0;
//     cout<<"Please Enter the popularity of the Book(# of book sales): "<<endl;
//     cin >>salesBook;

//     //get copies of boook
//     int copies = 0;
//     cout<<"Please Enter the amount of copies being added: "<<endl;
//     cin >>copies;

//     //get author of book
//     string author = "";
//     cout<<"Please Enter Author of Book: "<<endl;
//     cin >> author;

//     //get publish date of book
//     unsigned int  publishDate = 0;
//     cout <<"Please Enter the Publish Date of the Book:"<<endl;
//     cin >> publishDate;

//     lib.addBook(titleBook, genre, salesBook,copies, author, publishDate);

// }

// void Librarian::removeBook(Library& lib){
    
//     string titleBook = "";
//     cout<< "Please Enter title of Book you want to remove from Library: "<<endl;
//     cin >> titleBook;

//     lib.removeBook(titleBook);



//     cout<< "Book has been removed"<<endl;
//}

