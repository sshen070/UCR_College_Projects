#ifndef __INTVECTOR_H__
#define __INTVECTOR_H__

#include <iostream>
#include <cstdlib>

using namespace std;

class IntVector{
    private:
        unsigned _size;
        unsigned _capacity;
        int *_data;

        // Private Helper Functions
        void expand();
        void expand(unsigned amount);


    public:
        // From Lab (complete)
        IntVector(unsigned capacity = 0, int value = 0);
        ~IntVector();
        unsigned size() const;
        unsigned capacity() const;
        bool empty() const;
        const int & at(unsigned index) const;
        const int & front() const;
        const int & back() const;

        int & at(unsigned index);
        int & front();
        int & back();
        void insert(unsigned index, int value);
        void erase(unsigned index);
        void push_back(int value);
        void pop_back();
        void clear();
        void resize(unsigned size, int value = 0);
        void reserve(unsigned n);
        void assign(unsigned n, int value);
};

#endif