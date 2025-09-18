#pragma once

#include "Node.h"

using std::string;

class Tree {
private:
  Node* root;

public:
  // Constructors + Rule of 3
  Tree();
  ~Tree();
  Tree(const Tree&) = delete;
  Tree& operator=(const Tree&) = delete;
  
  // Public member functions
  void insert(const string &);
  void preOrder() const;
  void inOrder() const;
  void postOrder() const;
  void remove(const string &);
  Node* search(const string &);

private:
  // Private member function used in destructor
  void destroyTree(Node* node);

  // Private member functions used for insert & delete
  bool noChildren(Node* curr) const;
  void insert(Node* curr, const string& word);
  void splitFullLeaf(Node* curr, const string& word);
  Node* insertLocation(Node* curr, const string& word);
  void addData(Node* addHere, const string& word);
  void removeData(Node* removeHere, const string& word);
  bool hasTwoChildSibling(Node* curr) const;
  Node* search(Node* curr, const string& word);

  // BTree traversal
  void preOrder(const Node* curr) const;
  void inOrder(const Node* curr) const;
  void postOrder(const Node* curr) const;

  void fix(Node* emptyNode);
};
