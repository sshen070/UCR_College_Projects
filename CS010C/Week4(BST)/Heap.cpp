#include <iostream>
#include <string>
#include <vector>


template<typename T>
class Heap {
  int maxsize;
  int size = 0;
  std::vector<T> array;

  void percolate_up(int i) {
    while(i > 0) {
      int parent = (i-1)/2;
      if (array[i] <= array[parent]) return;
      std::swap(array[i],array[parent]);
      i = parent;
    }
  }
public:
  Heap(int maxsize=10)
    : maxsize(maxsize), array(maxsize)
  {
  }

  bool is_empty() const {
    return (size == 0);
  }

  void push(const T& element) {
    if (size == maxsize) throw std::runtime_error("overflow");

    array[size] = element;
    percolate_up(size);
    size++;
  }

  void show() const {
    for(int i=0;i<size;++i) {
      std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
  }
};

int main() {
  Heap<std::string> H;

  std::cout << H.is_empty() << std::endl;
  H.show();

  H.push("hello");
  H.push("xyz");
  H.show();
  
  return 0;
}