#include <iostream>
using namespace std;

#include "IntList.h"
#include "SortedSet.h"

int main(){
    cout << "intList1 Declared: " << endl;
    IntList intList1;

    intList1.push_back(11);
    intList1.push_back(61);
    intList1.push_back(10);
    intList1.push_back(111);
    intList1.push_back(100);
    cout << intList1 << endl;
    cout << endl;

    cout << "setList1 Declared (set to intList1): " << endl;
    SortedSet setList1 = intList1;
    cout << setList1 << endl;
    cout << endl;

    cout << "setList2 Declared (set to setList1): " << endl;

    SortedSet setList2 = setList1;
    cout << setList2 << endl;
    cout << endl;
    
    cout << "111 in setList 2: ";
    cout << setList2.in(111) << endl;
    cout << "150 in setList 2: ";
    cout << setList2.in(150) << endl;

    SortedSet setList3;
    cout << "61 in setList3: ";
    cout << setList3.in(61) << endl;
    cout << endl;

    cout << "setList3: " << endl;
    setList3.add(100);
    setList3.add(10);
    setList3.add(25);
    setList3.add(144);
    setList3.add(98);
    setList3.add(61);
    cout << setList3 << endl;
    cout << endl;

    cout << "Combination of sets: setList2 & setList3: " << endl;
    SortedSet combinedSet = setList2 | setList3;
    cout << combinedSet << endl;
    cout << endl;

    cout << "Intersection of sets: setList2 & setList3: " << endl;
    SortedSet intersectionSet = setList2 & setList3;
    cout << intersectionSet << endl;
    cout << endl;

    combinedSet.clear();
    intersectionSet.clear();

    combinedSet.add(34);
    combinedSet.add(563);
    combinedSet.add(45);
    combinedSet.add(100);
    combinedSet.add(61);

    intersectionSet.add(10);
    intersectionSet.add(111);
    intersectionSet.add(45);
    intersectionSet.add(78);
    intersectionSet.add(61);


    cout << "Combination of sets: combinedSet & setList2: " << endl;
    combinedSet |= setList2;
    cout << combinedSet << endl;
    cout << endl;

    cout << "Combination of sets: combinedSet & setList3: " << endl;
    combinedSet |= setList3;
    cout << combinedSet << endl;
    cout << endl;


    cout << "Intersection of sets: intersectionSet & setList2: " << endl;
    intersectionSet &= setList2;
    cout << intersectionSet << endl;
    cout << endl;

    cout << "Intersection of sets: intersectionSet & setList3: " << endl;
    intersectionSet &= setList3;
    cout << intersectionSet << endl;
    cout << endl;

    return 0;
}
