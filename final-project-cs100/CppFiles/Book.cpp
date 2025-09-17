// Note: Add the .h files (Brandon Ng)
#include "../HeaderFiles/Book.h"
#include "../HeaderFiles/Review.h"
#include <iostream>
#include <string>


// Stub for Book constructor (Steve)
// Added some default values (Brandon Ng)
Book::Book(){
    this->title = "No Title";
    this->genres = "No Genre";
    this->popularity = 0;
    this->copies = 0;
    this->author = "No Author";
    this->publishDate = 0;
}

Book::Book(const string& title, const string& genres, int popularity, int copies, const string& author, int publishDate){
    this->title = title;
    this->genres = genres;
    this->popularity = popularity;
    this->copies = copies;
    this->author = author;
    this->publishDate = publishDate;
}

string Book::getTitle(){
    return this->title;
}

string Book::getAuthor(){
    return this->author;
}

string Book::getGenre(){
    return this->genres;
}

unsigned int Book::getPublishDate(){
    return this->publishDate;
}

int Book::getPopularity(){
    return this->popularity;
}

int Book::getCopies(){
    return this->copies;
}

void Book::setCopies(int newCopies){
    this->copies = newCopies;
}

void ViewBook::viewBook(Book& book) {
    cout << "Title: " << book.getTitle() << endl;
    cout << "Author: " << book.getAuthor() << endl;
    cout << "Genre: " << book.getGenre() << endl;
    cout << "Publish Date: " << book.getPublishDate() << endl;
    cout << "Popularity: " << book.getPopularity() << endl;
    cout << "Copies: " << book.getCopies() << endl << endl;
}

// May not use (Brandon Ng)
// void Book::setTitle(string newTitle){
//     this->title = newTitle;
// }

// void Book::setAuthor(string newAuthor){
//     this->author = newAuthor;
// }

// void Book::setGenre(string newGenre){
//     this->genres = newGenre;
// }

// void Book::setPublishDate(unsigned int newPublishDate){
//     this->publishDate = newPublishDate;
// }

// void Book::setPopularity(int newPopularity){
//     this->popularity = newPopularity;
// }