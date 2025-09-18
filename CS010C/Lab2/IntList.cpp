#include "IntList.h"

#include <iostream>
using namespace std;

//Deletes list -> deletes all nodes using pop_back()
IntList::~IntList() {
  while(!empty()){ //While the list isn't empty deletes the node in front of dummyTail
    pop_back();
  }
  dummyHead.next = nullptr; //Sets dummyHead + dummyTail to nullptr since they are not needed as all the nodes have been deleted 
  dummyTail.prev = nullptr;
}

//Adds node to the front of the list & takes int parameter in function call
void IntList::push_front(int value) {
  IntNode* addFront = new IntNode(value); //Creates node to be inserted

  // if (empty()){ //If the list is empty -> add node between dummyHead & dummyTail (using pointers + memory addresses)
  //   dummyHead.next = addFront;
  //   dummyTail.prev = dummyHead.next;
  //   addFront -> next = &dummyTail;
  //   addFront -> prev = &dummyHead;
  // }
  // else{ //If list is not empty, add node to the front of the list 
  //   IntNode* afterNode = dummyHead.next;
  //   dummyHead.next = addFront;
  //   addFront -> prev = &dummyHead;
  //   addFront -> next = afterNode;
  //   afterNode -> prev = addFront;
  // }

  addFront -> next = dummyHead.next; //Points inserted node to the current first node & dummyHead
  addFront -> prev = &dummyHead;

  IntNode* afterNode = addFront -> next; //Makes the node after & dummyHead point to the inserted node
  afterNode -> prev = addFront;
  dummyHead.next = addFront;
}

//Removes node from the front of the list
void IntList::pop_front(){
  if (empty()){ //If empty, nothing
    return;
  }
  else{ //Sets the dummyHead.next to the node after the first node, so the first node can be deleted -> then closes the gap
    IntNode* removeNode = dummyHead.next;
    dummyHead.next = removeNode -> next;

    IntNode* newFirstNode = removeNode -> next;
    newFirstNode -> prev = &dummyHead;

    delete removeNode; //Deletes the first node from the list
  }
}

//Adds node to the end of the list & takes int parameter in function call
void IntList::push_back(int value) {
  IntNode* addBack = new IntNode(value);

  // if (empty()){ //If list empty, sets dummyHead.next and dummyTail.next to node (same idea as push_front())
  //   dummyHead.next = addBack;
  //   dummyTail.prev = dummyHead.next;
  //   addBack -> next = &dummyTail;
  //   addBack -> prev = &dummyHead;
  // }
  // else{ //Same thing as push_front() except -> adds the node to the back of the list
  //   IntNode* beforeNode = dummyTail.prev;
  //   dummyTail.prev = addBack;
  //   addBack -> next = &dummyTail;
  //   addBack -> prev = beforeNode;
  //   beforeNode -> next = addBack;
  // }

  addBack -> prev = dummyTail.prev; //Points inserted node to the current last node & dummyTail
  addBack -> next = &dummyTail;

  IntNode* beforeNode = addBack -> prev; //Makes the node before & dummyTail point to the inserted node
  beforeNode -> next = addBack;
  dummyTail.prev = addBack;
}

//Deletes node from the back of the list
void IntList::pop_back() {  
  if (empty()){ //If empty, no action -> nothing to remove
    return;
  }
  else{ //Connects the node before the last node in the list to the dummyTail, so last node can be deleted
    IntNode* removeNode = dummyTail.prev;
    dummyTail.prev = removeNode -> prev;

    IntNode* newLastNode = removeNode -> prev;
    newLastNode -> next = &dummyTail;
    delete removeNode; //Deletes the last node from the list
  }
}

//Helper function -> returns true/false based on whether or not the list is empty based on the operation
bool IntList::empty() const {
  return (dummyHead.next == &dummyTail);
}

//Prints out all the data values of the nodes in the linked list sequentially
ostream& operator<<(ostream &out, const IntList &rhs){
  if (rhs.empty()){ //If the list is empty, return nothing
    return out;
  }
  // For loop adds all the data values to out with a space between them (except last) -> then returns out so it is printed out
  // Traverses through list starting from the first node (dummyHead.next to dummyTail.prev) - stops when the last node is reached
  for (IntNode* printNode = rhs.dummyHead.next; (printNode -> next) != nullptr; printNode = printNode -> next){
    if (printNode == rhs.dummyTail.prev){ //If true, then function is done
      out << printNode -> data;
      return out;
    }
    out << printNode -> data << " "; 
  }
  return out; //Returns values stored to main where they are printed
}

//Similar to friend function operator<<, except prints data stored in reverse (back of the list to the front) & doesn't store in out (directly prints it instead)
void IntList::printReverse() const {
  if (empty()){ //If empty, return nothing
    return;
  }
  // Traverses through the list from dummyTail.prev -> dummyHead.next - stops when the first node in list is reached
  for (IntNode* reversePrintNode = dummyTail.prev; (reversePrintNode -> prev) != nullptr; reversePrintNode = reversePrintNode -> prev){
    if (reversePrintNode == dummyHead.next){ //If true, does last check -> then function done
      cout << reversePrintNode -> data;
      return; //In the case there is only one node in the linked list, return necessary to prevent value from being printed again in the next line
    }
    cout << reversePrintNode -> data << " "; 
  }
}