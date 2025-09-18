#include <iostream>
#include <cstdlib>

#include "IntVector.h"
using namespace std;

void Print(const IntVector &);
void FunctionTest(const IntVector &);

int main(){
    cout << "Vector with arguments (10, 5)" << endl;
    IntVector vec(10, 5);
    FunctionTest(vec);
    
    cout << "Vector with NO arguments" << endl;
    IntVector vec2;
    FunctionTest(vec2);
    return 0;
}

void Print(const IntVector &testVec){
    if (testVec.empty()){
        cout << "Vector is empty.";
    }
    else{
        for (unsigned i = 0; i < testVec.size(); i++)
        {
            cout << testVec.at(i) << " ";
        }
        cout << endl;
    }
}

void FunctionTest(const IntVector &testVec){
    cout << "Size: " << testVec.size() << endl;
    cout << "Capacity: " << testVec.capacity() << endl;
    cout << "Is vector empty (0 = false, 1 = true): " << testVec.empty() << endl;
    cout << "Front: " << testVec.front() << " Back: " << testVec.back() << endl;
    Print(testVec);
    if (testVec.size() >= 2){
        cout << "Value at index 1: " << testVec.at(1) << endl;  
    }
    //cout << "Value out of bounds: " << testVec.at(testVec.size());
    cout << endl;
}