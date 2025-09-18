#pragma once
#include <iostream>
#include <stdexcept>

using std::overflow_error;
using std::runtime_error;
using std::underflow_error;
using std::string;

template <typename T> 
class stack {
  static constexpr unsigned MAX_SIZE = 20;
  T dataArray[MAX_SIZE];
  unsigned arraySize = 0;

public:
  stack(): arraySize(0){}  // Initializer list to set arraySize -> 0 if no argument is passed in

  // push(T val): inserts a new element (val) of type T (T could be integer or string)
  // into the data. If the data array is full, this function should throw an overflow_error
  // exception with error message "Called push on full stack.".
  void push(const T& value) {
      if (arraySize >= MAX_SIZE) {  // If arraySize is >= capacity -> throw error
        throw std::overflow_error("Called push on full stack.");
      }
      dataArray[arraySize++] = value; // arraySize is post-incremented after value is set to array location
  }

  // empty(): returns true if the stack is empty otherwise it returns false.
  bool empty() const {
    return (arraySize == 0);
  }

  // pop(): removes the last element from data. If the data array is empty, this function
  // should throw an outofrange exception with error message "Called pop on empty stack.".
  void pop() {
      if (empty()){
        throw std::out_of_range("Called pop on empty stack.");
      }
      arraySize--;  // Decrements value of arraySize to prep for future function calls
  }

  // pop_two(): removes the last two elements from data. If the data array is empty or is
  // of size 1, this function should throw an out_of_range exception. If empty then the error
  // message should be "Called pop_two on empty stack." If the size is 1 then the error
  // message should be "Called pop_two on a stack of size 1.".
  void pop_two() {
    if (arraySize == 0) {
      throw std::out_of_range("Called pop_two on empty stack.");
    }
    else if (arraySize == 1) {
      throw std::out_of_range("Called pop_two on a stack of size 1.");
    }
    arraySize -= 2;  // Decrements value of arraySize by 2 if neither of the prev cases are true
  }

  T& top() {
    if (empty()) {
      throw std::underflow_error("Called top on empty stack.");
    }
    return dataArray[arraySize - 1];  // If array is not empty -> returns a reference to the element
    // Can be modified by setting it = to something in main
  }

  const T& top() const {
    if (empty()) {
      throw std::underflow_error("Called top on empty stack.");
    }    
    return dataArray[arraySize - 1];  // Same as the non-const function, but value can not be modified
  }
};
