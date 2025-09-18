#include <iostream>
using namespace std;

#include "IntList.h"

// Constructors/Destructors
IntList::IntList(){
    head = nullptr;
    tail = nullptr;
}

IntList::~IntList(){
    // while (head){
    //     IntNode* nextNode = head -> next;
    //     delete head;
    //     head = nextNode;
    // }
    // head = nullptr;
    // tail = nullptr;
    clear();
}

// Member Functions
void IntList::push_front(int value){ 
    IntNode *nextPtr = new IntNode(value);
    if (empty()){
        head = nextPtr;
        tail = nextPtr;
    }
    else{
        nextPtr -> next = head;
        head = nextPtr;
    }
}

void IntList::pop_front(){
    if (empty()){
        return;
    }
    else if (head -> next == nullptr){ // head == tail
        delete head;
        head = nullptr; 
        tail = nullptr;
    }
    else{
        IntNode *nextPtr = head -> next;
        delete head;
        head = nextPtr;
    }
}

bool IntList::empty() const{
    return (head == nullptr);
}

// Empty list causes undefined behavior
const int & IntList::front() const{
    return head -> value;
}

// Empty list causes undefined behavior
const int & IntList::back() const{
    return tail -> value;
}

void IntList::clear(){
    while(head != nullptr){
        IntNode *nextPtr = head -> next;
        delete head;
        head = nextPtr; 
    }
    head = nullptr;
    tail = nullptr;
}

// Friend Function
ostream & operator<<(ostream & out, const IntList & rhs){
    for (IntNode* node = rhs.head; node != nullptr; node = node -> next){
        if (node != rhs.tail){
            out << node -> value << ' ';
        }
        else{
            out << node -> value;
        }
    }
    return out;
}