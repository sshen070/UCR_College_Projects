#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Node {
  std::string payload;
  Node* next;
};

// Since no constructor -> sets up node & member variable (payload) through newNode(const string&)
Node* newNode(const std::string& payload) {
  Node* addNode = new Node();  // Uses default constructor to initialize the new node
  addNode->payload = payload;  // Sets the payload to the string from the argument
  return addNode;
}

// First parameter -> number of contestants entered by the user
// Second parameter -> vector containing all the contestants added by the user
Node* loadGame(int n, const std::vector<std::string>& names) {
  Node* head = nullptr;
  Node* prev = nullptr;
  std::string name;

  // Iterates through the vector for n number of contestants
  for (int i = 0; i < n; ++i) {
    name = names.at(i);
    // Special edge case when the list is initially empty -> set head & tail = firstNode
    if (head == nullptr) {
      head = newNode(name);
      prev = head;
    } else {
      // Otherwise, add the new node to the end of the list
      prev->next = newNode(name);  // Make a new node and set the next pointer of the node that prev is pointing to that node
      prev = prev->next;  // Set prev the next node
    }
  }
  // If the node prev is pointing to is the last node, make the list circular by pointing making its next pointer point to the head
  if (prev != nullptr) {
    prev->next = head;
  }
  return head;
}

// Function prints payload in circular linked list until it reaches the head node again
void print(const Node* start) {
  const Node* curr = start;
  while (curr != nullptr) {
    std::cout << curr->payload << std::endl;  // Print payload of nodes
    curr = curr->next;  // Advance to the next node
    if (curr == start) {
      break;  // exit circular list
    }
  }
}

// josephus w circular list, k = num skips
Node* runGame(Node* start, int k) {
  if (start == nullptr) return nullptr;

  Node* curr = start;
  Node* prev = curr;
  while (curr->next != curr) {  // exit condition, last person standing
    for (int i = 0; i < k; ++i) {  // find kth node
      prev = curr;  // Keep track of the node before
      curr = curr->next;  // Move to the next node until kth node is reached (i < k fails)
    }
    Node* next = curr->next;  // Save the node after curr so curr node can be deleted
    prev->next = next;  // Connect the prev to the node after curr
    delete curr;
    curr = next;
  }
  return curr;  // last person standing
}

/* Driver program to test above functions */
int main() {
  int n = 1, k = 1;  // n = num names; k = num skips (minus 1)
  std::string name;
  std::vector<std::string> names;

  // get inputs
  std::cin >> n >> k;
  if (!std::cin) {
    throw std::runtime_error("error reading n and k from input");
  }

  while (std::cin >> name && name != ".") {  // EOF or . ends input
    names.push_back(name);
  }
  // initialize and run game
  Node* startPerson = loadGame(n, names);
  Node* lastPerson = runGame(startPerson, k);

  if (lastPerson != nullptr) {
    std::cout << lastPerson->payload << " wins!" << std::endl;
  } else {
    std::cout << "error: null game" << std::endl;
  }

  delete lastPerson;  // Delete to ensure no memory leaks after the program ends
  lastPerson = nullptr;  // No dangling pointers
  return 0;
}
