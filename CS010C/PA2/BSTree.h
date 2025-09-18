#pragma once

#include "Node.h"

class BSTree {
  Node* root;

 public:
  BSTree(): root(nullptr) {}
  ~BSTree() {
    // Safe to delete nullptr, so no check needed
    // The Node class recursively deletes its children
    delete root;
  }
  BSTree(const BSTree&) = delete;
  BSTree& operator=(const BSTree&) = delete;
  
  void insert(const string& key);
  bool search(const string& key) const;
  string largest() const;
  string smallest() const;
  int height(const string& key) const;
  void remove(const string& key);

  void preOrder() const;
  void postOrder() const;
  void inOrder() const;
  
 private:
  int height_of(Node* tree) const;
  void removeRecursive(const string& key);
  void remove(Node* tree, const string& key);
  Node* findNode(const string& key) const;
  void preOrder(Node* tree) const;
  void postOrder(Node* tree) const;
  void inOrder(Node* tree) const;
};
