#include <string>
#include <iostream>

using std::cout;
using std::string;
using std::runtime_error;

class Stack {
  struct Node {
    string payload;
    Node* next;
    Node(const string& payload) : payload(payload), next(nullptr) {}
  };

  Node* head = nullptr;
public:
  Stack() {}

  void push(const string& element) {
    Node* new_node = new Node(element);
    new_node->next = head;
    head = new_node;
  }

  void pop() {
    if ( head == nullptr) throw runtime_error("underflow");
    Node* victim = head;
    head = head->next;
    delete victim;
  }

  string& top() {
    if ( head == nullptr) throw runtime_error("underflow");
    return head->payload;
  }
  const string& top() const {
    if ( head == nullptr) throw runtime_error("underflow");
    return head->payload;
  }

  bool is_empty() const {
    return (head == nullptr);
  }
};

void show_me_the_last(const Stack& s) {
  cout << s.top() << '\n';
}


int main() {

  Stack S;

  if ( S.is_empty() ) {
    cout << "empty\n";
  }

  S.push("A");
  S.push("B");
  S.push("C");

  show_me_the_last(S);
 
  if ( S.is_empty() ) {
    cout << "empty\n";
  } else {
    cout << "got stuff\n";
  }

  while(!S.is_empty()) {
    cout << S.top() << '\n';
    S.pop();
  }

  try {
    S.pop();
  } catch(const std::exception&) {
    cout << "well, that didn't work!\n";
  }
  return 0;
}
