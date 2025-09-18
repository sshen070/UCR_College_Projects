#include <string>
#include <exception>
#include <iostream>


using std::string;
using std::runtime_error;

class Queue {
  int maxsize;
  string* array;
  int first;
  int size;

  void resize() {
    string* copy = new string[maxsize*2];
    for(int i=0;i<size;++i) {
      copy[i] = array[(first+i)%maxsize];
    }

    delete[] array;
    maxsize = maxsize*2;
    array = copy;
    first = 0;
  }
public:
  Queue(int maxsize=10)
    : maxsize(maxsize),
      array(new string[maxsize]),
      first(0),
      size(0)
  {
  }

  ~Queue() {
    delete[] array;
  }
  Queue(const Queue&) = delete;
  Queue& operator=(const Queue&) = delete;

  void push(const string& element) {
    if (size == maxsize) {
      resize();
    }
    array[(first+size)%maxsize] = element;
    size++;
  }

  void pop() {
    if (size == 0) throw std::runtime_error("underflow");
    first = (first+1)%maxsize;
    --size;
  }

  string& front() {
    if (size == 0) throw std::runtime_error("underflow");
    return array[first];
  }
  const string& front() const {
    if (size == 0) throw std::runtime_error("underflow");
    return array[first];
  }

  bool is_empty() const {
    return (size == 0);
  }
};