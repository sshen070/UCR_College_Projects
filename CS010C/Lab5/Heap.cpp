#include <iostream>
#include "Heap.h"

using namespace std;

// Constructor
Heap::Heap()
  : numItems(0) {}

// Destructor
Heap::~Heap() {
  for (int i = 0; i < numItems; i++) {
    delete heap[i];
  }
  numItems = 0;
}

// Copy Constructor
Heap::Heap(const Heap& cpy) {
  numItems = cpy.numItems;
  for (int i = 0; i < numItems; i++) {
    heap[i] = new PrintJob(cpy.heap[i] -> getPriority(), cpy.heap[i] -> getJobNumber(), cpy.heap[i] -> getPages());
  }
}

// Copy Assignment Operator
Heap& Heap::operator=(const Heap& cpy) {
  if (this == &cpy) {
    return *this;
  }

  for (int i = 0; i < numItems; i++) {
    delete heap[i];
  }

  numItems = cpy.numItems;
  for (int i = 0; i < numItems; i++) {
    heap[i] = new PrintJob(cpy.heap[i] -> getPriority(), cpy.heap[i] -> getJobNumber(), cpy.heap[i] -> getPages());
  }
  return *this;
}

// Adds a new element to the end of the heap -> then percolates up to the proper location
void Heap::enqueue(PrintJob* job) {
  // Element can not be added if the heap is full
  if (numItems >= MAX_HEAP_SIZE) {
    return;
  }

  heap[numItems++] = job;  // Sets the last element to the paramater passed in
  percolate_up(numItems - 1);  // Calls percolate up for last element
}

// Recursive private helper function for enqueue() -> keeps swapping up the element until reaches the desired location
void Heap::percolate_up(int lastIndex) {
  // If only element in the heap -> nothing to percolate up
  if (lastIndex == 0) {
    return;
  }

  int parentIndex = (lastIndex - 1) / 2;  // Finds the parent element in the heap
  
  // Parent is greater than child -> base case (ends recursion)
  if (heap[parentIndex] -> getPriority() > heap[lastIndex] -> getPriority()) {
    return;
  }
  
  // While the parent is not greater than the child -> swap + call using the new location of the element
  swap(heap[parentIndex], heap[lastIndex]);
  percolate_up(parentIndex);
}

// Swaps & removes the first element in the heap (replacing with the last element) -> element moves down the heap to the right location
void Heap::dequeue() {
  // No elements in the heap -> nothing to percolate down
  if (numItems == 0) {
    return;
  }

  heap[0] = heap[--numItems];  // Sets the first element of the heap to the last element 
  percolate_down(0);  // Calls percolate down for the new first element
}

// Private helper function for dequeue() -> keeps swapping the element until it reaches the right location
void Heap::percolate_down(int firstIndex) {
  int leftChildIndex = (2 * firstIndex) + 1;  // Find leftChild -> rightChild = leftChild + 1

  // If generated value for child is > number of items in heap -> terminate (base case 1)
  if (leftChildIndex >= numItems) {
    return;
  }

  int largerVal = max(heap[leftChildIndex] -> getPriority(), heap[leftChildIndex + 1] -> getPriority());  // Find the larger of the two priority values of the children 
  int swapIndex = leftChildIndex;

  // If the priority value of the value passed in is greater than that of the two children -> it is in the correct location (base case 2)
  if (heap[firstIndex] -> getPriority() >= largerVal) {
    return;
  }

  // Swap the element with the larger child of the two
  else if (heap[leftChildIndex] -> getPriority() == largerVal) {
    swap(heap[firstIndex], heap[leftChildIndex]);
  }

  else {
    swap(heap[firstIndex], heap[leftChildIndex + 1]);
    swapIndex = leftChildIndex + 1;
  }

  // Call again until one of the base cases is reached
  percolate_down(swapIndex);
}

// Returns the first element of the heap (largest element)
PrintJob* Heap::highest() {
  if (numItems == 0) {
    return nullptr;
  }
  return heap[0];
}

// Prints out the data members values of the first/largest element in the heap
void Heap::print() const {
  if (numItems == 0) {
    return;
  }
  PrintJob* highestPriority = heap[0];
  cout <<  "Priority: " << highestPriority -> getPriority();
  cout << ", Job Number: " << highestPriority -> getJobNumber(); 
  cout << ", Number of Pages: " << highestPriority -> getPages() << endl ;
}
