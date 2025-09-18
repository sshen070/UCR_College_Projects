#include <iostream>

template<typename T>
class queue {
  struct Node {
    T key;
    Node* next;
    Node(const T& key) : key(key), next(nullptr) {}
  };

  Node* head = nullptr; // We delete at the head
  Node* tail = nullptr; // We append to the tail
public:
  queue() {
  }
  ~queue() {
    // Some people like this one, but I don't
    // while(not is_empty()) pop();
    while(head != nullptr) {
      Node* next = head->next;
      delete head;
      head = head->next;
    }
  }
  queue(const queue&) = delete;
  queue& operator=(const queue&) = delete;

  void push(const T& element) {
    Node* new_node = new Node(element);
    if (tail == nullptr) {
      head = tail = new_node;
    } else {
      tail->next = new_node;
      tail = new_node;
    }
  }

  void pop() {
    if (is_empty()) throw std::runtime_error("underflow");
    Node* victim = head;
    head = head->next;
    if (head == nullptr) tail = nullptr;
    delete victim;
  }

  T& front() {
    if (is_empty()) throw std::runtime_error("underflow");
    return head->key;
  }

  const T& front() const {
    if (is_empty()) throw std::runtime_error("underflow");
    return head->key;
  }

  bool is_empty() const {
    return (head == nullptr);
  }
};


int main() {
  queue<std::string> Q;

  Q.push("a");
  Q.push("b");
  Q.push("c");
  while(!Q.is_empty()) {
    std::cout << Q.front() << std::endl;
    Q.pop();
  }

  return 0;
}