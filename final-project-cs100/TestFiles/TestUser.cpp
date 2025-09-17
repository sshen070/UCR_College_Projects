#include "gtest/gtest.h"
#include "../HeaderFiles/User.h"
#include "../HeaderFiles/Book.h"
#include "../HeaderFiles/Library.h"

TEST(UserConstructor, validInput){
    string name = "fakeName";
    string password = "1234";
    string userType = "user";

    EXPECT_NO_THROW(User test(name, password,userType));
}

TEST(UserConstructor, invalidInput){
    string name = "fakeName";
    string password = "1234";
    string userType = "Libraryan";

    User user(name, password, userType);
    EXPECT_NE(user.getUserType(), "Librarian");
}

TEST(UserCheckOutBook, bookIsInLibrary){
    Library lib;
    string title = "ABook";
    string genre = "Comedy";
    int popularity = 12;
    int copies = 1;
    string author = "Profe";
    int publishDate = 12525;

    lib.addBookToLibrary(title, genre, popularity, copies, author, publishDate);

    EXPECT_TRUE(User().checkOutBook(title, lib));
}

TEST(UserCheckOutBook, bookIsInNotLibrary){
    Library lib;
    string title = "ABook";
    string genre = "Comedy";
    int popularity = 12;
    int copies = 1;
    string author = "Profe";
    int publishDate = 12525;

    lib.addBookToLibrary(title, genre, popularity, copies, author, publishDate);

    string search = "DiffBook";
    EXPECT_FALSE(User().checkOutBook(search, lib));
}


// TEST(UserBookIsCheckedOut, notNullPtr){//testing for this is done through making a library and using checkOut Book first
//     Library lib;
//     string title = "ABook";
//     string genre = "Comedy";
//     int popularity = 12;
//     int copies = 1;
//     string author = "Profe";
//     int publishDate = 12525;

//     lib.addBookToLibrary(title, genre, popularity, copies, author, publishDate);

//     string name = "fakeName";
//     string password = "1234";
//     string userType = "user";

//     User test(name, password, userType);

//     test.checkOutBook(title, lib);

//     Book* check = lib.bookIfExists(title);
//     EXPECT_EQ(test.bookIsCheckedOut(title)->getTitle(), "ABook");

// }

// TEST(UserBookIsCheckedOut, nullPtr){
//     Library lib;
//     string title = "ABook";
//     string genre = "Comedy";
//     int popularity = 12;
//     int copies = 1;
//     string author = "Profe";
//     int publishDate = 12525;

//     lib.addBookToLibrary(title, genre, popularity, copies, author, publishDate);

//     string name = "fakeName";
//     string password = "1234";
//     string userType = "user";

//     User test(name, password, userType);

//     string search = "DiffBook";
//     test.checkOutBook(search, lib);

//     EXPECT_EQ(test.bookIsCheckedOut(title), nullptr);
// }


TEST(UserReturnBook, bookReturned){

    Library lib;
    string title = "ABook";
    string genre = "Comedy";
    int popularity = 12;
    int copies = 1;
    string author = "Profe";
    int publishDate = 12525;

    lib.addBookToLibrary(title, genre, popularity, copies, author, publishDate);

    string name = "fakeName";
    string password = "1234";
    string userType = "user";

    User test(name, password, userType);

    test.checkOutBook(title, lib);

    EXPECT_NE(test.returnBook(title, lib),false);
}

TEST(UserReturnBook, doesntHaveBook){
    Library lib;
    string title = "ABook";
    string genre = "Comedy";
    int popularity = 12;
    int copies = 1;
    string author = "Profe";
    int publishDate = 12525;

    lib.addBookToLibrary(title, genre, popularity, copies, author, publishDate);

    string name = "fakeName";
    string password = "1234";
    string userType = "user";

    User test(name, password, userType);

    EXPECT_FALSE(test.returnBook(title, lib));
}