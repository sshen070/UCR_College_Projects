#include <iostream>
#include <cstdlib>

#include "IntVector.h"
using namespace std;

// If vector is not empty, prints all vector elements
void Print(const IntVector &);

// Tests size(), capacity(), empty(), front(), back()
void BasicFunctionsTest(const IntVector &);

// Modifies and tests the non-const at(), front(), back()
void ElementModification(IntVector &);

// Modifies the vector size + elements using the following functions: insert(), erase(), push_back(), pop_back(), clear()
void SizeChange(IntVector &);

// Tests the resize(), reserve(), assign() functions
void FinalTests(IntVector &);

int main(){
    cout << "Vector with arguments (10, 7)" << endl;
    IntVector vec(10, 7);
    BasicFunctionsTest(vec);
    ElementModification(vec);
    
    cout << "Vector with NO arguments" << endl;
    IntVector vec2;
    // BasicFunctionsTest(vec2);
    // ElementModification(vec2);

    cout << "Vector with arguments (5, 1)" << endl;
    IntVector vec3(5, 1);
    SizeChange(vec3);

    //SizeChange(vec2);  

    cout << "Vector with arguments (13)" << endl;
    IntVector vec4(13);
    FinalTests(vec4);

    return 0;
}

void Print(const IntVector &testVec){
    if (testVec.empty()){
        cout << "Vector is empty." << endl;
    }
    else{
        for (unsigned i = 0; i < testVec.size(); i++){
            cout << testVec.at(i) << " ";
        }
        cout << endl;
    }
}

void BasicFunctionsTest(const IntVector &testVec){
    cout << "Size: " << testVec.size() << endl;
    cout << "Capacity: " << testVec.capacity() << endl;
    cout << "Is vector empty (0 = false, 1 = true): " << testVec.empty() << endl;
    cout << "Front: " << testVec.front() << " Back: " << testVec.back() << endl;
    Print(testVec);
    //cout << "Value out of bounds: " << testVec.at(testVec.size());
    cout << endl;
}

void ElementModification(IntVector &testVec){
    if (testVec.size() > 0){
        cout << "Inital Values: " << endl;
        Print(testVec);

        cout << "Size: " << testVec.size() << " Capacity: " << testVec.capacity() << endl;

        cout << "testVec.at(2) = 100: " << endl;
        testVec.at(2) = 100;
        Print(testVec);

        cout << "testVec.front() = 61: " << endl;
        testVec.front() = 61;
        Print(testVec);

        cout << "testVec.back() = 11: " << endl;
        testVec.back() = 11;
        Print(testVec);

        cout << "testVec.at(testVec.size() - 1) = 111: " << endl;
        testVec.at(testVec.size() - 1) = 111;
        Print(testVec);

        cout << "Size: " << testVec.size() << " Capacity: " << testVec.capacity() << endl;

        //testVec.at(testVec.size()) = 1;

        cout << endl;
    }
}

void SizeChange(IntVector &testVec){
    cout << "Initial values: " << endl;
    Print(testVec);
    cout << "Size: " << testVec.size() << endl;
    cout << endl;

    testVec.insert(3, 949);
    Print(testVec);
    cout << "Size: " << testVec.size() << endl;

    testVec.insert(testVec.size(), 856);
    Print(testVec);
    cout << "Size: " << testVec.size() << endl;
    
    //testVec.erase(testVec.size());
    testVec.erase(testVec.size() - 1);
    Print(testVec);
    cout << "Size: " << testVec.size() << endl;
    
    testVec.erase(0);
    Print(testVec);
    cout << "Size: " << testVec.size() << endl;

    testVec.push_back(131);
    Print(testVec);
    cout << "Size: " << testVec.size() << endl;

    testVec.pop_back();
    Print(testVec);
    cout << "Size: " << testVec.size() << endl;

    testVec.clear();
    Print(testVec);
    cout << "Size: " << testVec.size() << endl;

    testVec.push_back(131);
    Print(testVec);
    cout << "Size: " << testVec.size() << endl;
    
    cout << endl;
}

void FinalTests(IntVector &testVec){
    cout << "Initial values: " << endl;
    Print(testVec);
    cout << "Size: " << testVec.size() << endl;
    cout << endl;

    testVec.resize(7, 10);
    Print(testVec);
    cout << "Size: " << testVec.size() << endl;

    testVec.resize(11, 1);
    Print(testVec);
    cout << "Size: " << testVec.size() << endl;

    testVec.reserve(50);
    cout << "Capacity: " << testVec.capacity() << endl;

    testVec.assign(15, 61);
    Print(testVec);
    cout << "Size: " << testVec.size() << endl;

    testVec.clear();
    Print(testVec);
    cout << "Size: " << testVec.size() << endl;
}
