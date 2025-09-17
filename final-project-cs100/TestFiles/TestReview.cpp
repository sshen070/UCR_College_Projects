#include "gtest/gtest.h"
#include "../HeaderFiles/Review.h"

// Constructor Tests (6 Total)
TEST(ReviewConstructorTest, testDefaultConstructor) {
    EXPECT_NO_THROW(Review newReview());
}

TEST(ReviewConstructorTest, testValidParameters) {
    EXPECT_NO_THROW(Review newReview("Test",5));
}

TEST(ReviewConstructorTest, testInvalidRating) {
    EXPECT_DEATH(Review newReview("Test",-2), "Invalid Rating");
}

TEST(ReviewConstructorTest, testGetSetComment) {
    Review newReview("Fail",5);
    newReview.setComment("Test");
    EXPECT_EQ(newReview.getComment(), "Test");
}

TEST(ReviewGetSetTest, testGetSetRating) {
    Review newReview("Test",4);
    newReview.setRating(5);
    EXPECT_EQ(newReview.getRating(), 5);
}

TEST(ReviewConstructorTest, testInvalidSetRating) {
    Review newReview("Test",4);
    EXPECT_DEATH(newReview.setRating(-2), "Invalid Rating");
}

// Add Review, Remove Review, and Edit Review Tests (3 Total)
TEST(ReviewList, testAddReview) {
    Review newReview1("Test1",1);
    Review newReview2("Test2",2);
    Review newReview3("Test3",3);

    ReviewList newReviewList;
    newReviewList.addReview(newReview1);
    newReviewList.addReview(newReview2);
    newReviewList.addReview(newReview3);

    // Comparison to just manually making a list
    vector<Review> testList = {newReview1, newReview2, newReview3};

    EXPECT_EQ(newReviewList.getReviewList(), testList);
}

TEST(ReviewList, testRemoveReview) {
    Review newReview1("Test1",1);
    Review newReview2("Test2",2);
    Review newReview3("Test3",3);

    ReviewList newReviewList;
    newReviewList.addReview(newReview1);
    newReviewList.addReview(newReview2);
    newReviewList.addReview(newReview3);
    newReviewList.removeReview(newReview3);

    // Comparison to just manually making a list
    vector<Review> testList = {newReview1, newReview2};

    EXPECT_EQ(newReviewList.getReviewList(), testList);
}

TEST(ReviewList, testEditReview) {
    Review newReview1("Test1",1);
    Review newReview2("Test2",2);
    Review newReview3("Test3",3);
    Review newReviewFail("Fail", 0);

    ReviewList newReviewList;
    newReviewList.addReview(newReview1);
    newReviewList.addReview(newReview2);
    newReviewList.addReview(newReviewFail);
    newReviewList.editReview(newReviewFail, "Test3", 3);

    // Comparison to just manually making a list
    vector<Review> testList = {newReview1, newReview2, newReview3};

    EXPECT_EQ(newReviewList.getReviewList(), testList);
}

// View Review Tests (3 Total)
TEST(ViewReview, testViewReview) {
    Review newReview1("Test1",1);
    Review newReview2("Test2",2);
    Review newReview3("Test3",3);

    ReviewList newReviewList;
    newReviewList.addReview(newReview1);
    newReviewList.addReview(newReview2);
    newReviewList.addReview(newReview3);

    ViewReviews newViewReview;
    EXPECT_NO_THROW(newViewReview.viewReviews(newReviewList));
}

TEST(ViewReview, testViewReviewWithRemove) {
    Review newReview1("Test1",1);
    Review newReview2("Test2",2);
    Review newReview3("Test3",3);

    ReviewList newReviewList;
    newReviewList.addReview(newReview1);
    newReviewList.addReview(newReview2);
    newReviewList.addReview(newReview3);
    newReviewList.removeReview(newReview3);

    ViewReviews newViewReview;
    EXPECT_NO_THROW(newViewReview.viewReviews(newReviewList));
}

TEST(ViewReview, testViewReviewWithEdit) {
    Review newReview1("Test1",1);
    Review newReview2("Test2",2);
    Review newReviewFail("Fail", 0);

    ReviewList newReviewList;
    newReviewList.addReview(newReview1);
    newReviewList.addReview(newReview2);
    newReviewList.addReview(newReviewFail);
    newReviewList.editReview(newReviewFail, "Test3", 3);

    ViewReviews newViewReview;
    EXPECT_NO_THROW(newViewReview.viewReviews(newReviewList));
}

// Average Rating Tests (3 Total)
TEST(AveragetRating, testAverageRating) {
    Review newReview1("Test1",3);
    Review newReview2("Test2",4);
    Review newReview3("Test3",4);

	ReviewList newReviewList;
    newReviewList.addReview(newReview1);
    newReviewList.addReview(newReview2);
    newReviewList.addReview(newReview3);

    AverageRating newAverageRating;
    newAverageRating.setAverageRating(newReviewList);
    EXPECT_NEAR(newAverageRating.getAverageRating(), 3.666, 0.001);
}

TEST(AveragetRating, testAverageRatingWithRemove) {
    Review newReview1("Test1",3);
    Review newReview2("Test2",4);
    Review newReview3("Test3",4);

    ReviewList newReviewList;
    newReviewList.addReview(newReview1);
    newReviewList.addReview(newReview2);
    newReviewList.addReview(newReview3);
    newReviewList.removeReview(newReview3);

    AverageRating newAverageRating;
    newAverageRating.setAverageRating(newReviewList);
    EXPECT_NEAR(newAverageRating.getAverageRating(), 3.5, 0.01);
}

TEST(AveragetRating, testAverageRatingWithEdit) {
    Review newReview1("Test1",3);
    Review newReview2("Test2",4);
    Review newReview3("Test3",1);

    ReviewList newReviewList;
    newReviewList.addReview(newReview1);
    newReviewList.addReview(newReview2);
    newReviewList.addReview(newReview3);
    newReviewList.editReview(newReview3, "Test3", 4);

    AverageRating newAverageRating;
    newAverageRating.setAverageRating(newReviewList);
    EXPECT_NEAR(newAverageRating.getAverageRating(), 3.666, 0.001);
}