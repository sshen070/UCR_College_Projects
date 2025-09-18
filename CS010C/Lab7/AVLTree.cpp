#include "AVLTree.h"

#include <iostream>
using namespace std;

// Constructor
AVLTree::AVLTree()
  : root(nullptr)
{
}

// Destructor
AVLTree::~AVLTree() { 
  deleteTree(root);
}

// Recursive helper function for the destructor
void AVLTree::deleteTree(Node *tree) {
  if (!tree) {
    return;
  }
  
  deleteTree(tree -> left);
  deleteTree(tree -> right);
  delete tree;
}


// Pass in a string as a parameter -> use as data for node to insert
void AVLTree::insert(const string& key) {
  // If tree empty -> make node root
  if (!root) {
    root = new Node(key);
    root -> count++;
    return;
  }

  // If duplicate -> increment count of the node instead of adding it to the tree
  Node* searchNode = search(key);
  if (searchNode) {
    searchNode -> count++;
    return;
  }

  Node* parentNode = root;
  Node* currNode = root;

  // Iterate through loop until currNode == nullptr / insert location has been reached
  while (currNode) {
    parentNode = currNode;

    // If node key is less than parameter key -> move left
    // Else -> move right
    if (key < currNode -> data) {
      currNode = currNode -> left;

    }
    else if (key > currNode -> data) {
      currNode = currNode -> right;
    }
  }

  Node* newChild = new Node(key);
  // Insert left or right accordingly
  if (key < parentNode -> data) {
    parentNode -> left = newChild;
    newChild -> parent = parentNode;
  } 
  else {
    parentNode -> right = newChild;
    newChild -> parent = parentNode;
  }

  Node* fixNode = newChild;
  // Keeps calling rotate until fixNode traverses though all the parents toward the root -> ensures all nodes are in the right position in the subtree
  // If no issue with the the balancing -> return (no change)
  while (fixNode) {
    rotate(fixNode);
    fixNode = fixNode -> parent;
  }
}

// Returns the balance factor of a node -> height of the left subtree - right subtree
int AVLTree::balanceFactor(Node* balanceNode) const {
  // Returns -1 if no tree exists
  if (balanceNode == nullptr) {
    return -1;
  }
  // Otherwise uses computed_height function to get the height of each subtree for arithmetic
  return computed_height(balanceNode -> left) - computed_height(balanceNode -> right);
}

// If an unbalanced node exists above the node passed in (just inserted) -> returns that node
Node* AVLTree::findUnbalancedNode(Node* currNode) const {
  // If root -> nothing to balance 
  if (!currNode -> parent) {
    return nullptr;
  }

  Node* parentNode = currNode -> parent;
  // Traverses up the tree -> if any node unbalanced returns the node
  while (parentNode) {
    if (balanceFactor(parentNode) < -1 || balanceFactor(parentNode) > 1) {
      return parentNode;
    }
    parentNode = parentNode -> parent; // Keeps traversing
  }
  return nullptr; // If all nodes balanced
}

// Main rotate function. Depending on the orientation of nodes in three tree levels -> variation in balancing steps
void AVLTree::rotate(Node* insertedNode) {
  Node* inBalancedNode = findUnbalancedNode(insertedNode); // Finds node to balance 

  // If nullptr -> return 
  if (!inBalancedNode) {
    return;
  }

  // If parent is heavy in in direction while the inner node (child) is inbalanced in other direction -> double rotation required
  // Else -> just the appropriate rotation
  if (balanceFactor(inBalancedNode) > 1) {
    // If left node is right-heavy -> double rotation (left then right)
    if (balanceFactor(inBalancedNode -> left) < 0) {
      rotateLeft(inBalancedNode -> left);
    }
    rotateRight(inBalancedNode);
  }

  // If contradictory balance values -> last two nodes are swapped to put them into sequential order (rotation fit order)
  // Same idea as the first case, but for the opposite configuration
  else if (balanceFactor(inBalancedNode) < -1) {
    // If left node is left-heavy -> double rotation (right then left)
    if (balanceFactor(inBalancedNode -> right) > 0) {
      rotateRight(inBalancedNode -> right);
    }
    rotateLeft(inBalancedNode);
  }
}

// Two seperate uses - 1) rotate 3 in order nodes (all pointing using right pointer (balance factor < 0) for both root/parent & internal node)
// Case 2) rotateLeft to swap inner node with leaf to put the nodes in order -> rotateRight to balance the three nodes 
void AVLTree::rotateLeft(Node* rotateNode) {
  // If rotateNode or the right child of rotateNode doesn't exist -> nothing to rotate
  if (!rotateNode || !rotateNode -> right) {
    return;
  }

  // Easy access of nodes to be rotated
  Node* newRoot = rotateNode -> right;
  Node* leftChild = newRoot -> left;

  // Node that is passed in -> becomes child of its left child & keeps track of the other node it may have been pointing to
  newRoot -> left = rotateNode;
  rotateNode -> right = leftChild;

  // If left child exists -> make it the child of rotateNode
  if (leftChild) {
    leftChild -> parent = rotateNode;
  }

  Node* parentNode = rotateNode -> parent; // Parent of node passed in
  newRoot -> parent = parentNode; // Swaps the position of the node passed in and its child starting with the parent


// Three cases to either make newRoot the root of the tree/left or right child of rotateNode's parent
  // If no parent -> make it root
  if (!rotateNode -> parent) {
    root = newRoot;
  }
  // Determine if newRoot belongs on the left of the parent or right
  else if (rotateNode == parentNode -> left) {
    parentNode -> left = newRoot;
  }
  else {
    parentNode -> right = newRoot;
  }

  rotateNode -> parent = newRoot; // Makes the now child node point back to its parent
}


// Same idea as rotateLeft -> two seperate uses - 1) rotate 3 in order nodes (all pointing using left pointer (balance factor > 0) for both root/parent & internal node)
// Case 2) rotateRight to swap inner node with leaf to put the nodes in order -> rotateLeft to balance the three nodes 
void AVLTree::rotateRight(Node* rotateNode) {
  // If rotateNode or the right child of rotateNode doesn't exist -> nothing to rotate
  if (!rotateNode || !rotateNode -> left) {
    return;
  }

  Node* newRoot = rotateNode -> left;
  Node* rightChild = newRoot -> right;

  // Node that is passed in -> becomes child of its left child & keeps track of the other node it may have been pointing to
  newRoot -> right = rotateNode;
  rotateNode -> left = rightChild;

  // If right child exists -> make it the child of rotateNode
  if (rightChild) {
    rightChild -> parent = rotateNode;
  }

  Node* parentNode = rotateNode -> parent; // Parent of node passed in
  newRoot -> parent = parentNode; // Swaps the position of the node passed in and its child starting with the parent

// Three cases to either make newRoot the root of the tree/left or right child of rotateNode's parent
  // If no parent -> make it root
  if (!rotateNode -> parent) {
    root = newRoot;
  } 

  // Determine if newRoot belongs on the left of the parent or right
  else if (rotateNode == parentNode -> left) {
    parentNode -> left = newRoot;
  }
  else {
    parentNode -> right = newRoot;
  }

  rotateNode -> parent = newRoot; // Makes the now child node point back to its parent
}


// This is a helper function that traverses the tree to compute the height
int AVLTree::computed_height(const Node* subtree) const{
  if (subtree == nullptr) return 0;
  return max(computed_height(subtree->left), computed_height(subtree->right)) + 1;
}

// Finds and returns the node if found; else -> returns nullptr
Node* AVLTree::search(const string& key) {
  // Return nullptr if tree empty
  if (!root) {
    return nullptr;
  }
  
  Node* currNode = root;
  // Iterate through the tree depending on how the key compares to the currNode
  // If node with the correct key found -> return the node
  while (currNode){
    if (currNode -> data == key){
      return currNode;
    }
    else if (key < currNode -> data){
      currNode = currNode -> left;
    }
    else {
      currNode = currNode -> right;
    }
  }
  // Otherwise return nullptr
  return nullptr;
}

// Public print funtion -> calls its recursive helper function
void AVLTree::printBalanceFactors() const {
  printBalanceFactors(root);
  cout << endl;
}

// Prints out the AVL Tree in order along with their respective balance factors
void AVLTree::printBalanceFactors(Node* currNode) const {
  if (!currNode) {
    return;
  }

  printBalanceFactors(currNode -> left); // Starts on the bottom left prints on its way up -> then moves right
  cout << currNode -> data << "(" << balanceFactor(currNode) <<  "), ";
  printBalanceFactors(currNode -> right);
}


// We visualize a tree as text (there are some notes about doing this with VizGraph
// but it has never been worth the effort to get that part working)
void AVLTree::visualizeTree(const Node* subtree,int indent) const {
  // Indenting some spaces
  for(int i=0;i<indent;++i) {
    cout << ' ';
  }

  if (subtree == nullptr) {
    cout << "-empty-" << endl;
  } else {
    cout << subtree->data << ' ' << '(' << (computed_height(subtree->left)-computed_height(subtree->right)) << ')' << endl;
    visualizeTree(subtree->left,indent+4);
    visualizeTree(subtree->right,indent+4);
  }
}
