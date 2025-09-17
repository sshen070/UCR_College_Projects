#ifndef REVIEW_H
#define REVIEW_H

#include <string>
#include <vector>

using namespace std;

class Review {
  private:
    string comment;
    int rating;

  public:
    Review();
    Review(string newComment, int newRating);
    string getComment();
    int getRating();
    void setComment(string newComment);
    void setRating(int newRating);
    bool operator==(const Review& rhs) const;
};

class ReviewList {
  private:
    vector<Review> reviewList;

  public:
    vector<Review> getReviewList();
    void addReview(Review& addReview);
    void removeReview(Review& deleteReview);
    void editReview(Review& changeReview, string newComment, int newRating);
};

class AverageRating {
  private:
    double averageRating;

  public:
    double getAverageRating();
    void setAverageRating(ReviewList reviews);
 };

 class ViewReviews {
  private:
  
  public:
    void viewReviews(ReviewList reviews);
 };

#endif