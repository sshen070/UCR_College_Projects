#include "../HeaderFiles/LibrarySorts.h"
#include "../HeaderFiles/Library.h"
#include <algorithm>
#include <string>

using namespace std;


//Sort stubs but unsure if we're passing the book collection by reference or not (Kevin Tam)
void LibrarySorts::sortByAlphabet(Library& sortCollection){
    sort(sortCollection.bookCollection.begin(), sortCollection.bookCollection.end(), [](Book& a, Book& b) {
           return a.getTitle() < b.getTitle();
	   });
}

// void LibrarySorts::sortByRating(Library& sortCollection){
//     AverageRating avgRates; 
//     for(int i=0; i<sortCollection.bookCollection.size(); i++){
//      avgRates.setAverageRating(sortCollection.bookCollection.at(i).reviewList)}
//     sort(sortCollection.bookCollection.begin(), sortCollection.bookCollection.end(), [](Book& a, Book& b) {
//            return a.getAverageRating();
//         return;
//            });
// }

void LibrarySorts::sortByGenre(Library& sortCollection){
    sort(sortCollection.bookCollection.begin(), sortCollection.bookCollection.end(), [](Book& a, Book& b) {
           return a.getGenre() < b.getGenre();
           });
}

void LibrarySorts::sortByPopularity(Library& sortCollection){
    sort(sortCollection.bookCollection.begin(), sortCollection.bookCollection.end(), [](Book& a, Book& b) {
           return a.getPopularity() < b.getPopularity();
           });
}

void LibrarySorts::sortByAuthor(Library& sortCollection) {
    sort(sortCollection.bookCollection.begin(), sortCollection.bookCollection.end(), [](Book& a, Book& b) {
	   return a.getAuthor() < b.getAuthor();
	   });
}

void LibrarySorts::sortByPbDate(Library& sortCollection) {
    sort(sortCollection.bookCollection.begin(), sortCollection.bookCollection.end(), [](Book& a, Book& b) {
	  return a.getPublishDate() < b.getPublishDate();
	  });
}