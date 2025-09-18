#pragma once
#include <string>

#include "Node.h"

class AVLTree{
  private:
    Node *root;
    void visualizeTree(const Node* subtree, int indent=0) const;
    int computed_height(const Node* subtree) const;
    void printBalanceFactors(Node*) const;
    void deleteTree(Node*);

  public:
    AVLTree();
    ~AVLTree();
    // Delete cpy constructor + cpy assignment operator
    AVLTree(const AVLTree&) = delete;
    AVLTree& operator=(const AVLTree&) = delete;

    void insert(const std::string&);
    int balanceFactor(Node*) const;
    void printBalanceFactors() const;
    

    Node* search(const std::string&); 
    Node* findUnbalancedNode(Node*) const;
    void rotate(Node*);
    void rotateLeft(Node*);
    void rotateRight(Node*);

    void visualizeTree() const { visualizeTree(root); }
};
