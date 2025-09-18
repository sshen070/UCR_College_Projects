#include <iostream>
#include "IntList.h"

using namespace std;

int main() {
  IntList list;

  cout << "empty: " << list << endl;
  list.push_front(10);
  cout << "push front 10: " << list << endl;
  list.push_front(99);
  cout << "push front 99: " << list << endl;
  list.push_front(61);
  cout << "push front 61: " << list << endl;


  list.push_back(100);
  cout << "push back 100: " << list << endl;
  list.push_back(111);
  cout << "push back 111: " << list << endl;
  list.push_back(161);
  cout << "push back 161: " << list << endl;

  list.pop_back();
  cout << "pop back: " << list << endl;
  
  list.pop_front();
  cout << "pop front: " << list << endl;

  cout << "print reverse: ";
  list.printReverse();
  cout << endl;

  return 0;
}
