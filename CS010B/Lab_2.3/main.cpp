#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
   
   string inputFile;
   string outputFile;
   
   // Assign to inputFile value of 2nd command line argument
   // Assign to outputFile value of 3rd command line argument
   if (argc != 3) {
      cout << "Usage ERROR" << endl;
      exit(EXIT_FAILURE);
   }

   inputFile = argv[1];
   outputFile = argv[2];

   // Create input stream and open input csv file.
   ifstream inFS;
   inFS.open(inputFile);

   // Verify file opened correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if(!inFS.is_open()){
      cout << "Error opening " << inputFile << endl;
      exit(EXIT_FAILURE);
   }
   
   // Read in integers from input file to vector.
   vector <int> integers;
   int fileInput;
   char commas;

   while (inFS >> fileInput){
      integers.push_back(fileInput);
      inFS >> commas;
   }

   // Close input stream.
   inFS.close();

   // Get integer average of all values read in.
   int sum = 0;
   for (unsigned int i = 0; i < integers.size(); i++){
      sum += integers.at(i);
   }

   // Convert each value within vector to be the difference between the original value and the average.
   double average = sum / integers.size();

   for (unsigned int i = 0; i < integers.size(); i++){
      integers.at(i) = integers.at(i) - average;
   }

   // Create output stream and open/create output csv file.
   ofstream outFS;
   outFS.open(outputFile);

   // Verify file opened or was created correctly.
   // Output error message and return 1 if file stream did not open correctly.

   if(!outFS.is_open()){
      cout << "Error opening " << outputFile << endl;
      exit(EXIT_FAILURE);
   }
   
   // Write converted values into ouptut csv file, each integer separated by a comma.
   for (unsigned int i = 0; i < integers.size(); i++) {
       outFS << integers.at(i);
       if (i != integers.size() - 1) {
           outFS << ",";
       }
   }

   // Close output stream.
   outFS.close();

   return 0;
}