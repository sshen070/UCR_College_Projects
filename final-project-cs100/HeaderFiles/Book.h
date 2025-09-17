#ifndef BOOK_H
#define BOOK_H

#include "Review.h"
#include <string>
#include <vector>

using namespace std;

class Book {
  private:
    string title;
    string author;
    string genres;
    unsigned int publishDate;
    int popularity;
    int copies;
    vector <Review> reviewList;

  public:
    Book();
    Book(const string&, const string&, int, int, const string&, int);

    string getTitle();
    string getAuthor();
    string getGenre();
    unsigned int getPublishDate();
    int getPopularity();
    int getCopies();

    void setCopies(int);
};

class ViewBook {
  private:

  public:
    void viewBook(Book&);
};

#endif