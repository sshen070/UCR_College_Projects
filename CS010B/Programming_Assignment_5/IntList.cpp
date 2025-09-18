#include <iostream>
using namespace std;

#include "IntList.h"

// Constructors/Destructors
IntList::IntList(){
    head = nullptr;
    tail = nullptr;
}

IntList::~IntList(){
    // while(head != nullptr){
    //     IntNode *nextPtr = head -> next;
    //     delete head;
    //     head = nextPtr;
    // }
    // head = nullptr;
    // tail = nullptr;    
    clear();
}

// Copy Constructor
IntList::IntList(const IntList &cpy){
    head = nullptr;
    tail = nullptr;
    
    if (!cpy.empty()){
        for (IntNode* copyNode = cpy.head; copyNode != nullptr; copyNode = copyNode -> next){
            push_back(copyNode -> value);
        }
    }
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

IntList& IntList::operator=(const IntList &rhs){
    if (this != &rhs){
        clear();
        if (rhs.empty()){
            head = nullptr;
            tail = nullptr;
        }
        else{
            for (IntNode* copyNode = rhs.head; copyNode != nullptr; copyNode = copyNode -> next){
                push_back(copyNode -> value);
            }
        }
    }
    return *this;
}

void IntList::push_back(int value){
    IntNode *nextPtr = new IntNode(value);
    if (empty()){
        head = nextPtr;
        tail = nextPtr;
    }
    else{
        tail -> next = nextPtr;
        tail = nextPtr;
    }
}

void IntList::selection_sort(){ // selection sort algorithm from zybooks
    if (empty()){
        return;
    }
    for (IntNode* firstNode = head; firstNode != nullptr; firstNode = firstNode -> next){
        IntNode* minNode = firstNode;
        for (IntNode* secondNode = firstNode -> next; secondNode != nullptr; secondNode = secondNode -> next){
            if (secondNode -> value < minNode -> value){
                minNode = secondNode;
            }
        }
        swap(firstNode -> value, minNode -> value);
    }
}

void IntList::insert_ordered(int value){
    if (empty()){
        push_back(value);
        return;
    }
    
    if (value <= head -> value){
        push_front(value);
        return;
    }
    
    IntNode* insertNode = new IntNode(value);
    IntNode* prevNode = head;
    IntNode* currNode = head -> next;

    while ((currNode != nullptr) && (value > currNode -> value)){
        prevNode = currNode;
        currNode = currNode -> next;
    }

    // if (value <= currNode -> value){
    insertNode -> next = currNode;
    prevNode -> next = insertNode;
    // }

    if (currNode == nullptr){
        push_back(value);
    }
}

void IntList::remove_duplicates(){
    for (IntNode* origNode = head; origNode != nullptr; origNode = origNode -> next){
        IntNode* prevNode = origNode;
        IntNode* currNode = prevNode -> next;
        while (currNode != nullptr){
            if (currNode -> value == origNode -> value){
                prevNode -> next = currNode -> next;
                if (currNode != tail){
                    delete currNode;
                    currNode = prevNode -> next;
                }
                else{
                    tail = prevNode;
                    tail -> next = nullptr; // no dangling pointers
                    delete currNode;
                    currNode = prevNode -> next;
                }
            }
            else{
                prevNode = currNode;
                currNode = currNode -> next;
            }
        }
    }
}

// Friend Function
ostream & operator<<(ostream & out, const IntList & rhs){
    for (IntNode* node = rhs.head; node != nullptr; node = node -> next){
        if (node -> next != nullptr){
            out << node -> value << ' ';
        }
        else{
            out << node -> value;
        }
    }
    return out;
}