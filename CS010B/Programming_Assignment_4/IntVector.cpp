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

// // Copy Constructor
// IntVector::IntVector(const IntVector& cpy): _capacity(cpy._capacity), _capacity(cpy._capacity){
//     if (_capacity == 0){
//         _data = nullptr;
//     }
//     else{
//         _data = new int[_capacity];
//         for (int i = 0; i < _size; i++){
//         _data[i] = cpy._data[i];
//         }
//     }
// }

// // Copy Assignment Operator
// IntVector::IntVector operator=(const IntVector& cpy){
//     if (this != &rhs){
//         delete[] _data;
//         _size = cpy._size;
//         _capacity = cpy._capacity;
//         if (_capacity == 0){
//             _data = nullptr;
//         }
//         else{
//             _data = new int[_capacity];
//             for (unsigned i = 0; i < _size; ++i){
//                 _data[i] = cpy._data[i];
//             }
//         }
//     }
//     return *this;
// }

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

const int& IntVector::at(unsigned index) const{
    if (index <= _size - 1 && !empty()){
        return _data[index];
    }
    else{
        throw out_of_range("IntVector::at_range_check");
    }
}

int& IntVector::at(unsigned index){
    if (index <= _size - 1 && !empty()){
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

int& IntVector::front(){
    if (_size == 0){
        throw out_of_range("IntVector::at_range_check");
    }
    return _data[0];
}

const int& IntVector::back() const{
    if (_size == 0){
        throw out_of_range("IntVector::at_range_check");
    }
    return _data[_size - 1];
}

int& IntVector::back(){
    if (_size == 0){
        throw out_of_range("IntVector::at_range_check");
    }
    return _data[_size - 1];
}

void IntVector::insert(unsigned index, int value){
    if (index > _size){
        throw out_of_range("IntVector::insert_range_check");
    }

    // if (_size == 0){
    //     expand();
    // }

    if (_size == _capacity){
        expand();
    }

    for (unsigned i = _size; i > index; i--){
        _data[i] = _data[i - 1];
    }
    _data[index] = value;
    _size++;
}

void IntVector::erase(unsigned index){
    if (index >= _size){
        throw out_of_range("IntVector::erase_range_check");
    }

    for (unsigned i = index; i < _size - 1; i++){
        _data[i] = _data[i + 1];
    }
    _size--;
}

void IntVector::push_back(int value){
    if (_size >= _capacity){
        expand();
    }

    _data[_size] = value;
    _size++;
}

void IntVector::pop_back(){
    _size--;
}

void IntVector::clear(){
    _size = 0;
}

void IntVector::resize(unsigned size, int value){
    if (size <= _size){
        _size = size;
    }
    else if (size > _size){
        if (size > _capacity){
            if ((_capacity * 2) < size){
                expand(size - _capacity);
            }
            else{
                expand();
            }
        }
        for (unsigned int i = _size; i < size; i++){
            _data[i] = value;
        }
        _size = size;
    }
}

void IntVector::reserve(unsigned n){
    if (n > _capacity){
        expand(n - _capacity);
    }
}

void IntVector::assign(unsigned n, int value){
    if (n <= _size){
        for (unsigned int i = 0; i < n; i++){
            _data[i] = value;
        }
        _size = n;
    }
    else if (n > _size){
        if (n > _capacity){
            if ((_capacity * 2) < n){
                expand(n - _capacity);
            }
            else{
                expand();
            }
        }
        for (unsigned int i = 0; i < n; i++){
            _data[i] = value;
        }
        _size = n;
    }
}

// Private Helper Functions

void IntVector::expand(){ // make sure to revert it (no function call)
    if (_capacity == 0){
        _data = new int[1];
        _capacity++;
    }
    else{
        int *temp = new int [_capacity * 2];
        for (unsigned int i = 0; i < _size; i++){
            temp[i] = _data[i];
        }
        delete[] _data;
        _data = temp;
        _capacity *= 2;
    }
}

void IntVector::expand(unsigned amount){
    if (_capacity == 0){
        _data = new int[amount];
        _capacity += amount;
    }
    else{
        int *temp = new int [_capacity + amount];
        for (unsigned int i = 0; i < _size; i++){
            temp[i] = _data[i];
        }
        delete[] _data;
        _data = temp;
        _capacity += amount;
    }
}


