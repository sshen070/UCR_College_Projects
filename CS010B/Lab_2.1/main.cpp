#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

// Place fileSum prototype (declaration) here
int fileSum(const string& filename);

int main() {

   string filename;
   int sum = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   
   sum = fileSum(filename);

   cout << "Sum: " << sum << endl;
   
   return 0;
}

// Place fileSum implementation here
int fileSum(const string& filename){

    ifstream inFS;
    int fileInput;
    int sum = 0;

    inFS.open(filename);

    if(!inFS.is_open()){
        cout << "Error opening " << filename << endl;
        exit(EXIT_FAILURE);
    }

    while (inFS >> fileInput){
        sum += fileInput;
    }

    inFS.close();
    return sum;
}