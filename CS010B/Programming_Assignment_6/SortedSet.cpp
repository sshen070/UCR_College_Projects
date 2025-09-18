#include <iostream>
using namespace std;

#include "IntList.h"
#include "SortedSet.h"


// Constructor + Copy Constructors + Destructor
SortedSet::SortedSet(): IntList(){
}

SortedSet::SortedSet(const SortedSet &cpy): IntList(cpy){
}

SortedSet::SortedSet(const IntList &cpy): IntList(cpy){
    remove_duplicates();
    selection_sort();
}

SortedSet::~SortedSet(){
}

// Accessor Functions
bool SortedSet::in(int value) const{
    if (empty()){
        return false;
    }
    for (IntNode* searchNode = head; searchNode != nullptr; searchNode = searchNode -> next){
        if (searchNode -> value == value){
            return true;
        }
    }
    return false;
}

SortedSet SortedSet::operator|(const SortedSet& secSet) const{
    SortedSet combinedSet;
    for (IntNode* addNode = head; addNode != nullptr; addNode = addNode -> next){
        combinedSet.add(addNode -> value);
    }
    for (IntNode* addNode = secSet.head; addNode != nullptr; addNode = addNode -> next){
        combinedSet.add(addNode -> value);
    }
    return combinedSet;
}

SortedSet SortedSet::operator&(const SortedSet& secSet) const{
    SortedSet intersectionSet;
    for (IntNode* addNode = head; addNode != nullptr; addNode = addNode -> next){
        if (secSet.in(addNode -> value)){
            intersectionSet.add(addNode -> value);
        }
    }
    return intersectionSet;
}


// Mutator Functions
void SortedSet::add(int value){
    /*
    if (empty()){
        push_back(value);
        return;
    }

    if (in(value)){
        return;
    }

    if (value < head -> value){
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

    insertNode -> next = currNode;
    prevNode -> next = insertNode;

    if (currNode == nullptr){
        push_back(value);
    }
    */
    if (!in(value)){
        IntList::insert_ordered(value);
    }
}

void SortedSet::push_front(int value){
    add(value);
}

void SortedSet::push_back(int value){
    add(value);
}

void SortedSet::insert_ordered(int value){
    add(value);
}

SortedSet SortedSet::operator|=(const SortedSet& secSet){
    if (this == &secSet){
        return *this;
    }

    SortedSet combinedSet = *this | secSet;
    clear();
    for (IntNode* addNode = combinedSet.head; addNode != nullptr; addNode = addNode -> next){
        add(addNode -> value);
    }
    return *this;
}

SortedSet SortedSet::operator&=(const SortedSet& secSet){
    if (this == &secSet){
        return *this;
    }

    SortedSet intersectionSet = *this & secSet;
    clear();
    for (IntNode* addNode = intersectionSet.head; addNode != nullptr; addNode = addNode -> next){
        add(addNode -> value);
    }
    return *this;
}




