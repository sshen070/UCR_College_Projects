#include "gtest/gtest.h"
#include "../HeaderFiles/Account.h"
#include "../HeaderFiles/AccountDatabase.h"
#include "../HeaderFiles/SignUp.h"
#include "../HeaderFiles/Login.h"


class MockADatabase : public AccountDatabase {
    public:
        AccountDatabase dataB;
}

TEST(ViewOptionTest, testViewOptionY) {
    istringstream input("y"); //input initialization
    ostringstream output;
    streambuf* cinBuf = cin.rdbuf();
    streambuf* coutBuf = cout.rdbuf();

    cin.rdbuf(input.rdbuf());
    cout.rdbuf(output.rdbuf());
    
    dataB.viewOptions();
    
    cin.rdbuf(cinBuf);
    cout.rdbuf(coutBuf);
    
    EXPECT_NO_THROW(loginScreen.login(accountDatabase));
}

TEST(ViewOptionTest, testViewOptionN){
    istringstream input("n");
    ostringstream output;
    streambuf* cinBuf = std::cin.rdbuf();
    streambuf* coutBuf = std::cout.rdbuf();

    cin.rdbuf(input.rdbuf());
    cout.rdbuf(output.rdbuf());
    
    dataB.viewOptions();
    
    cin.rdbuf(cinBuf);
    cout.rdbuf(coutBuf);
    
    string result = output.str();
    EXPECT_NO_THROW(signUpScreen.SignUp());
}

TEST(AccountSignUpTest, testViewOptionFail) {
    istringstream input(" ");
    ostringstream output;
    streambuf* cinBuf = std::cin.rdbuf();
    streambuf* coutBuf = std::cout.rdbuf();

    cin.rdbuf(input.rdbuf());
    cout.rdbuf(output.rdbuf());
    
    dataB.viewOptions();
    
    cin.rdbuf(cinBuf);
    cout.rdbuf(coutBuf);

    string result = output.str();
    EXPECT_STREQ(result, "Invalid input, please type y(yes) or n(no)");
}

