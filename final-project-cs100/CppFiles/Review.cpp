#include "../HeaderFiles/Review.h"
#include <assert.h>
#include <iostream>
#include <string>

// Review Functions: 8 Total
Review::Review() {
    comment = "";
    rating = -1;
}

Review::Review(string newComment, int newRating) 
  : comment{newComment},
    rating{newRating} {
    assert(rating >= 0 && rating <= 5 && "Invalid Rating");
}

string Review::getComment() {
    return comment;
}

int Review::getRating() {
    return rating;
}

void Review::setComment(string newComment) {
    comment = newComment;
}

void Review::setRating(int newRating) {
    rating = newRating;
    assert(rating >= 0 && rating <= 5 && "Invalid Rating");
}

// Operator overloading
bool Review::operator==(const Review& rhs) const {
    return (comment == rhs.comment && rating == rhs.rating);
}

// Review List Functions: 4 Total
vector<Review> ReviewList::getReviewList() {
    return reviewList;
}

void ReviewList::addReview(Review& addReview) {
    reviewList.push_back(addReview);
}

void ReviewList::removeReview(Review& deleteReview) {
    for (vector<Review>::iterator i = reviewList.begin(); i != reviewList.end(); i++) {
        if (deleteReview == *i) {
            reviewList.erase(i);
            break;
        }
    }
}

void ReviewList::editReview(Review& changeReview, string newComment, int newRating) {
    for (unsigned int i = 0; i < reviewList.size(); i++) {
        if (changeReview == reviewList.at(i)) {
            (reviewList.at(i)).setComment(newComment);
            (reviewList.at(i)).setRating(newRating);
            break;
        }
    }
}

// Average Rating Functions: 2 Total
double AverageRating::getAverageRating() {
    return averageRating;
}

void AverageRating::setAverageRating(ReviewList reviews) {
    averageRating = 0;

    if (reviews.getReviewList().size() != 0) {
        for (unsigned int i = 0; i < reviews.getReviewList().size(); i++) {
            averageRating += reviews.getReviewList().at(i).getRating();
        }

        averageRating /= reviews.getReviewList().size();
    }
}

// View Reviews Functions: 1 Total 
void ViewReviews::viewReviews(ReviewList reviews) {
    for (unsigned int i = 0; i < reviews.getReviewList().size(); i++) {
        cout << "Comment " << i + 1 << ": " << reviews.getReviewList().at(i).getComment() << endl;
        cout << "Rating " << i + 1 << ": " << reviews.getReviewList().at(i).getRating() << endl << endl;
    }
}
