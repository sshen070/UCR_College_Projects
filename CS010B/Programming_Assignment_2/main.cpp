#include <iostream>
#include <string>

using namespace std;

class Date {
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
   // creates the date January 1st, 2000.
   Date();


   /* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
   Date(unsigned m, unsigned d, unsigned y);


   /* parameterized constructor: month name, day, year
      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).
 
       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */
   Date(const string &mn, unsigned d, unsigned y);


   /* Outputs to the console (cout) a Date exactly in the format "3/15/2012". 
      Does not output a newline at the end.
   */
   void printNumeric() const;


   /* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
   void printAlpha() const;

 private:

   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool isLeap(unsigned y) const;


   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned m, unsigned y) const;

   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
   string name(unsigned m) const;

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned number(const string &mn) const;
};


// Implement the Date member functions here

// Member functions
Date::Date(){
   day = 1;
   month = 1;
   monthName = "January";
   year = 2000;
}

Date::Date(unsigned m, unsigned d, unsigned y){
   year = y;
   bool issue = false;
   if (m >= 1 && m <= 12){
      month = m;
   }
   else if (m > 12){
      month = 12;
      issue = true;
   }
   else{
      month = 1;
      issue = true;
   }

   unsigned int numDays = daysPerMonth(month, year);

   if (d >= 1 && d <= numDays){
      day = d;
   }
   else if (d > numDays){
      day = numDays;
      issue = true;
   }
   else{
      day = 1;
      issue = true;
   }

   monthName = name(month);
   
   if (issue){
      cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "."  << endl;
   }
}

Date::Date(const string &mn, unsigned d, unsigned y){
   month = number(mn);

   if (month == 0){
      cout << "Invalid month name: the Date was set to 1/1/2000." << endl;
      day = 1;
      month = 1;
      monthName = "January";
      year = 2000;
   }
   else{
      monthName = name(month);
      year = y;
      unsigned numDays = daysPerMonth(month, year);
   
      if (d >= 1 && d <= numDays){
         day = d;
      }
      else if (d > numDays){
         day = numDays;
         cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
      }
      else{
         day = 1;
         cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
      }
   }
}


// Helper Functions
unsigned Date::daysPerMonth(unsigned m, unsigned y) const{
   int numDays;
   if (m == 2){
      if(isLeap(y)){
         numDays = 29;
      }
      else{
         numDays = 28;
      }
   }
   
   else{
      if (m == 4 || m == 6 || m == 9 || m == 11){
         numDays = 30;
      }
      else{
         numDays = 31;
      }
   }
   return numDays;
}

bool Date::isLeap(unsigned y) const{
   if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)){
      return true;
   }
   else{
      return false;
   }
}

string Date::name(unsigned m) const{
   string monthN;

   if (m == 1){
      monthN = "January";
   }
   else if (m == 2){
      monthN = "February";
   }
   else if (m == 3){
      monthN = "March";
   }
   else if (m == 4){
      monthN = "April";
   }
   else if (m == 5){
      monthN = "May";
   }
   else if (m == 6){
      monthN = "June";
   }
   else if (m == 7){
      monthN = "July";
   }
   else if (m == 8){
      monthN = "August";
   }
   else if (m == 9){
      monthN = "September";
   }
   else if (m == 10){
      monthN = "October";
   }
   else if (m == 11){
      monthN = "November";
   }
   else if (m == 12){
      monthN = "December";
   }

   return monthN;
}

unsigned Date::number(const string &mn) const{
   unsigned int monthNum;
   if (mn == "January" || mn == "january"){
      //mn = "January";
      monthNum = 1;
   }
   else if (mn == "February" || mn == "february"){
      //mn = "February";
      monthNum = 2;
   }
   else if (mn == "March" || mn == "march"){
      //mn = "March";
      monthNum = 3;
   }
   else if (mn == "April" || mn == "april"){
      //mn = "April";
      monthNum = 4;
   }
   else if (mn == "May" || mn == "may"){
      //mn = "May";
      monthNum = 5;
   }
   else if (mn == "June" || mn == "june"){
      //mn = "June";
      monthNum = 6;
   }
   else if (mn == "July" || mn == "july"){
      //mn = "July";
      monthNum = 7;
   }
   else if (mn == "August" || mn == "august"){
      //mn = "August";
      monthNum = 8;
   }
   else if (mn == "September" || mn == "september"){
      //mn = "September";
      monthNum = 9;
   }
   else if (mn == "October" || mn == "october"){
      //mn = "October";
      monthNum = 10;
   }
   else if (mn == "November" || mn == "november"){
      //mn = "November";
      monthNum = 11;
   }
   else if (mn == "December" || mn == "december"){
      //mn = "December";
      monthNum = 12;
   }
   else{
      //mn = "Error";
      monthNum = 0;
   }
   return monthNum;
}

void Date::printNumeric() const{
   cout << month << "/" << day << "/" << year; 
}

void Date::printAlpha() const{
   cout << monthName << " " << day << ", " << year;
}


// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develop mode, but you will need these to pass tets in submit mode.

Date getDate();

int main() {
   
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}
