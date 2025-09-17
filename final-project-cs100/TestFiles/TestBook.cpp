#include "gtest/gtest.h"
#include "../HeaderFiles/Review.h"
#include "../HeaderFiles/Book.h"

// Constructor Tests (2 Total)
TEST(BookConstructorTest, testDefaultConstructor) {
    EXPECT_NO_THROW(Book newBook());
}

TEST(BookConstructorTest, testValidConstructor) {
    EXPECT_NO_THROW(Book newBook("Title", "Genre", 0, 0, "Author", 0));
}

// Set Copies Tests (2 Total)
TEST(BookConstructorTest, testSetCopies) {
    Book newBook("Title", "Genre", 0, 0, "Author", 0);
    newBook.setCopies(10);
    EXPECT_EQ(newBook.getCopies(), 10);
}

TEST(BookConstructorTest, testInvalidSetCopies) {
    Book newBook("Title", "Genre", 0, 0, "Author", 0);
    newBook.setCopies(-2);
    EXPECT_EQ(newBook.getCopies(), 0);
}

// View Book Test (1 Total) (Accounts for all gets)
TEST(ViewBookTest, testViewBookWithValidConstructor) {
    Book newBook("Title", "Genre", 1, 2, "Author", 3);
    ViewBook newViewBook;

    EXPECT_NO_THROW(newViewBook.viewBook(newBook));
}
