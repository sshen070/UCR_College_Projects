#ifndef SORTEDSET_H
#define SORTEDSET_H

#include <ostream>

using namespace std;
#include "IntList.h"

class SortedSet: public IntList{

 public:
 // Constructor + Copy Constructors + Destructor
    SortedSet();
    SortedSet(const SortedSet &);
    SortedSet(const IntList &);
    ~SortedSet();

// Accessor Functions
    bool in(int) const;
    SortedSet operator|(const SortedSet& secSet) const;
    SortedSet operator&(const SortedSet& secSet) const;

// Mutator Functions
    void add(int value);
    void push_front(int value);
    void push_back(int value);
    void insert_ordered(int value);
    SortedSet operator|=(const SortedSet& secSet);
    SortedSet operator&=(const SortedSet& secSet);
};

#endif