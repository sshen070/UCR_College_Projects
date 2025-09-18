#include <iostream>
#include <cstdlib>
#include <stdexcept>

#include "IntVector.h"
using namespace std;

// IntVector::IntVector(){
//     _size = 0;
//     _capacity = 0;
//     _data = nullptr;
// }

IntVector::IntVector(unsigned capacity, int value){
    _capacity = capacity;
    _size = capacity;

    if (capacity == 0){
        _data = nullptr;
    }
    else{
        _data = new int[capacity];
        for (unsigned int i = 0; i < capacity; i++){
            _data[i] = value;
        }
    }
}

IntVector::~IntVector(){
    delete[] _data;
    _data = nullptr;
}

unsigned IntVector::size() const{
    return _size;
}

unsigned IntVector::capacity() const{
    return _capacity;
}

bool IntVector::empty() const{
    return (_size == 0);
}

const int & IntVector::at(unsigned index) const{
    if (index >= 0 && index <= _size - 1 && !empty()){
        return _data[index];
    }
    else{
        throw out_of_range("IntVector::at_range_check");
    }
}

const int & IntVector::front() const{
    if (_size == 0){
        throw out_of_range("IntVector::at_range_check");
    }
    return _data[0];
}

const int & IntVector::back() const{
    if (_size == 0){
        throw out_of_range("IntVector::at_range_check");
    }
    return _data[_size - 1];
}