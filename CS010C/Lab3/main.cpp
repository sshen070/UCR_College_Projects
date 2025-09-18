#include <exception>
#include <iostream>
#include <vector>
#include <string>
#include <utility>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::runtime_error;
using std::endl;
using std::swap;

//  Predefined function to create a vector type char & fills it up with 0-25 chars
vector<char> createVector() {
  int vecSize = rand() % 26;
  char c = 'a';
  vector<char> vals;
  for(int i = 0; i < vecSize; i++) {
    vals.push_back(c);
    c++;
  }
  return vals;
}

// Passes in an index of type int and a vector of type T (T could be
// string, double, int or whatever). The function returns the index
// of the min value starting from "index" to the end of the "vector".
template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index) {
  unsigned minValIndex = index;  // Keeps track of the index with the smallest val
  //  Traverses from the index provided to the last element
  for (unsigned i = index; i < vals.size(); i++) {
    // If the value of the element is smaller than the smallest value so far -> make that that the min val index
    if (vals.at(i) < vals.at(minValIndex)) {
      minValIndex = i;
    }
  }
  return minValIndex;
}

// Passes in a vector of type T and sorts them based on the selection
// sort method. This function should utilize the min_index function
// to find the index of the min value in the unsorted portion of the
// vector.
template<typename T>
void selection_sort(vector<T> &vals) {
  if (vals.size() == 0) {  // If vector is empty -> exit the sort algorithm
    return;
  }

  int minIndex = 0;
  // Iterate until one before the last element -> the array will be sorted by selection sort
  // before the last element is reached
  for (unsigned i = 0; i < vals.size() - 1; i++) {
    // Use the min index function to find the smallest value to swap in the current iteration onwards
    minIndex = min_index(vals, i);
    swap(vals.at(minIndex), vals.at(i));  // Swap the value in the current index with the smallest val
  }
}

// Passes in a vector of type T (T could be string, double or int) and
// an index of type int. The function returns the element located at
// the index of the vals.
template<typename T>
T getElement(const vector<T>& vals, int index) {
  return vals.at(index);
}

int main() {
  // Seeding the random number generator so we get a different
  // run every time.
  srand(time(0));

  // Fill in a vector of some random size with some random
  // characters
  vector<char> vals = createVector();
  int numOfRuns = 10;
  while(--numOfRuns >= 0) {
    cout << "Enter a number: " << endl;
    int index;
    try {
      if (!(cin >> index)) {  // If user input fails (input not an int) -> throw runtime error
        throw runtime_error("could not read the index");
      }
      // If index input out of range of the size of the array -> throw out of range error
      if ((index) < 0 || (index) >= vals.size()) {
        throw std::out_of_range("out of range exception occured");
      }
      char curChar = getElement(vals, index);
      cout << "Element located at " << index << ": is " << curChar << endl;
    }

    catch (std::runtime_error& excpt) {  // Catch runtime error exception
      cout << excpt.what() << endl;
    }
    catch (std::out_of_range& excpt) {  // Catch out of range error exception
      cout << excpt.what() << endl;
    }
  }
  selection_sort(vals);

  return 0;
}
