#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::string;
using std::vector;


template<class T>
class Heap {
  int maxsize;
  vector<T> array;
  int size = 0;

  void percolate_up(int i) {
    if (i==0) return; // At the root... Stop!

    int parent = (i-1)/2;
    if ( array[parent] > array[i]) return; // Dominates!

    // Fix with a swap so child becomes dominant one
    std::swap(array[parent],array[i]);
    percolate_up(parent);
  }

public:
  Heap(int maxsize=10)
    : maxsize(maxsize),array(maxsize)
  {
  }

  bool is_empty() const {
    return (size == 0);
  }

  void push(const T& element) {
    if (size == maxsize) throw std::runtime_error("full");

    array[size] = element;
    percolate_up(size);
    size++;

    // and more!
  }

  void pop() {
  }

  T& front() {
  }

  const T& front() const {
  }

  void show() const {
    for(auto& x:array) {
      cout << x << ' ';
    }
    cout << std::endl;
  }

};

int main() {
  Heap<string> H;

  H.show();
  cout << H.is_empty() << std::endl;

  H.push("hello");
  H.push("xyz");
  H.show();
  return 0;
}