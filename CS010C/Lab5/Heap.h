#pragma once
#include "PrintJob.h"


class Heap {
private:
  static const int MAX_HEAP_SIZE = 10;

  PrintJob* heap[MAX_HEAP_SIZE];      // Notice this is an array of PrintJob pointers
  int numItems;  // current number of items in heap

public:
  /* Initializes an empty heap.*/
  Heap();

  // Rule of three -> Destructor, Copy Constructor, & Copy Assignment Operator
  ~Heap();
  Heap(const Heap& cpy);
  Heap& operator=(const Heap& cpy);

  /* Inserts a PrintJob to the heap without
  violating max-heap properties.*/
  void enqueue(PrintJob* job);

  /* Removes the node with highest priority from the heap. 
  Follow the algorithm on priority-queue slides. */
  void dequeue();

  /* Returns the node with highest priority.*/
  PrintJob* highest();

  /* Prints the PrintJob with highest priority in the following format:
     Priority: priority, Job Number: jobNum, Number of Pages: numPages
     (Add a new line at the end.) */
  void print() const;

private:
  /* Passes in the location of the element that needs to be percolated up the max heap (last element)
  Recursively calls itself until element is in the right position*/
  void percolate_up(int arraySize);

  /* Passes in the location of the first element of the array that needs to be percolated down
  Recursively calls itself until element is in the right position*/
  void percolate_down(int arrayLocation);
};
