#include "../HeaderFiles/Library.h"
#include "../HeaderFiles/Book.h"

#include <iostream>
#include <ostream>

using namespace std;

Library::Library(){
    bookCollection.push_back(Book("1984", "Dystopian", 95, 5, "George Orwell", 1949));
    bookCollection.push_back(Book("To Kill a Mockingbird", "Fiction", 90, 3, "Harper Lee", 1960));
    bookCollection.push_back(Book("The Great Gatsby", "Classic", 85, 4, "F. Scott Fitzgerald", 1925));
    bookCollection.push_back(Book("Moby-Dick", "Adventure", 75, 2, "Herman Melville", 1851));
    bookCollection.push_back(Book("Pride and Prejudice", "Romance", 88, 6, "Jane Austen", 1813));
    bookCollection.push_back(Book("The Catcher in the Rye", "Fiction", 80, 3, "J.D. Salinger", 1951));
    bookCollection.push_back(Book("Brave New World", "Dystopian", 92, 5, "Aldous Huxley", 1932));
    bookCollection.push_back(Book("The Hobbit", "Fantasy", 97, 8, "J.R.R. Tolkien", 1937));
    bookCollection.push_back(Book("War and Peace", "Historical", 70, 2, "Leo Tolstoy", 1869));
    bookCollection.push_back(Book("Crime and Punishment", "Psychological", 78, 3, "Fyodor Dostoevsky", 1866));
    bookCollection.push_back(Book("Frankenstein", "Horror", 83, 4, "Mary Shelley", 1818));
    bookCollection.push_back(Book("Dracula", "Horror", 82, 3, "Bram Stoker", 1897));
    bookCollection.push_back(Book("The Odyssey", "Epic", 95, 5, "Homer", -800));
    bookCollection.push_back(Book("Les Misérables", "Historical", 88, 4, "Victor Hugo", 1862));
    bookCollection.push_back(Book("Ulysses", "Modernist", 79, 2, "James Joyce", 1922));
    bookCollection.push_back(Book("The Divine Comedy", "Epic", 91, 5, "Dante Alighieri", 1320));
    bookCollection.push_back(Book("The Brothers Karamazov", "Philosophical", 86, 4, "Fyodor Dostoevsky", 1880));
    bookCollection.push_back(Book("Fahrenheit 451", "Dystopian", 89, 3, "Ray Bradbury", 1953));
    bookCollection.push_back(Book("One Hundred Years of Solitude", "Magical Realism", 93, 6, "Gabriel García Márquez", 1967));
    bookCollection.push_back(Book("The Lord of the Rings", "Fantasy", 98, 10, "J.R.R. Tolkien", 1954));
    bookCollection.push_back(Book("The Stranger", "Existential", 84, 2, "Albert Camus", 1942));
    bookCollection.push_back(Book("Don Quixote", "Satire", 90, 5, "Miguel de Cervantes", 1605));
    bookCollection.push_back(Book("The Grapes of Wrath", "Historical", 87, 4, "John Steinbeck", 1939));
    bookCollection.push_back(Book("Jane Eyre", "Romance", 89, 6, "Charlotte Brontë", 1847));
    bookCollection.push_back(Book("Wuthering Heights", "Romance", 82, 3, "Emily Brontë", 1847));
    bookCollection.push_back(Book("The Picture of Dorian Gray", "Gothic", 85, 3, "Oscar Wilde", 1890));
    bookCollection.push_back(Book("Meditations", "Philosophy", 88, 2, "Marcus Aurelius", 180));
    bookCollection.push_back(Book("The Republic", "Philosophy", 92, 4, "Plato", -380));
    bookCollection.push_back(Book("The Art of War", "Strategy", 90, 5, "Sun Tzu", -500));
    bookCollection.push_back(Book("The Iliad", "Epic", 95, 5, "Homer", -750));
    bookCollection.push_back(Book("Hamlet", "Tragedy", 96, 6, "William Shakespeare", 1600));
}

Book* Library::bookIfExists(const string& title) {
    for (int i = 0; i < bookCollection.size(); i++) {
        if (bookCollection.at(i).getTitle() == title) {
            return &bookCollection.at(i);
        }
    }
    return nullptr;
}

// For Librarian only -> passes in the specifics
void Library::addBookToLibrary(const string& title, const string& genres, int popularity, int copies, const string& author, int publishDate) {
    Book* existsBook = bookIfExists(title);

    if (existsBook == nullptr) {
        bookCollection.push_back(Book(title, genres, popularity, copies, author, publishDate));
    } 

    else {
        int tempCopies = existsBook -> getCopies();
        existsBook -> setCopies(tempCopies + 1);
    }
}

// For User only -> requires title as a parameter only
bool Library::addBookToLibraryUser(const string& title) {
    Book* existsBook = bookIfExists(title);
    
    if (existsBook != nullptr) {
        int tempCopies = existsBook -> getCopies();

        existsBook -> setCopies(tempCopies + 1);
        return true;
    }
    return false;
}



bool Library::removeBookFromLibrary(const string& title) {
    Book* existsBook = bookIfExists(title);

    if (existsBook != nullptr) {
        int tempCopies = existsBook -> getCopies();

        if (tempCopies > 0) {
            existsBook -> setCopies(tempCopies - 1);
            return true;
        }
    }
    return false;
}

void Library::printLibrary() {
    for (int i = 0; i < bookCollection.size(); i++) {
        cout << bookCollection.at(i).getTitle() << endl;
    }
}

// void Library::addBook(string& title, string& genres, int popularity, int copies, string& author, unsigned int publishDate){
    
//     for(unsigned i = 0 ; i < bookCollection.size();i++){
//         if(bookCollection.at(i).getTitle() == title){

//             int tempCopies = bookCollection.at(i).getCopies();

//             if(tempCopies > 0){

//                 bookCollection.at(i).setCopies(tempCopies+1);

//             }
//             else{
//                 Book newlyAddedBook(title, genres, popularity, copies, author, publishDate);

//                 bookCollection.push_back(newlyAddedBook);
//             }

//             break;
//         }
//     }

    

// }


// void Library::removeBook(string titleBook){
    
//     for(unsigned i = 0 ; i < bookCollection.size();i++){
//         if(bookCollection.at(i).getTitle() == titleBook){

//             int tempCopies = bookCollection.at(i).getCopies();

//             if(tempCopies > 0){

//                 bookCollection.at(i).setCopies(tempCopies-1);

//             }
//         }
//     }
// }
