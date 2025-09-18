#include "BSTree.h"

#include <iostream>

using namespace std;

// Pass in a string as a parameter -> use as key for node to insert
void BSTree::insert(const string& key) {
  // If tree empty -> make node root
  if (root == nullptr){
    root = new Node(key);
    return;
  }
  // If duplicate -> increment count of the node instead of adding it to the tree
  if (search(key) == true) {
    findNode(key) -> count++;
    return;
  }
  
  Node* insertNode = new Node(key); // Node to insert

  Node* parentNode = nullptr;
  Node* currNode = root;

  // Iterate through loop until currNode == nullptr / insert location has been reached
  while (currNode != nullptr) {
  parentNode = currNode;
    // If node key is less than parameter key -> move left
    // Else -> move right
    if (insertNode -> key < currNode -> key) {
      currNode = currNode -> left;
    }
    else {
      currNode = currNode -> right;
    }
  }

  // Insert left or right accordingly
  if (insertNode -> key < parentNode -> key) {
    parentNode -> left = insertNode;
  }
  else {
    parentNode -> right = insertNode;
  }
}

// Pass in key to search for in the tree -> return whether or not found
bool BSTree::search(const string& key) const {
  // Return false if tree empty
  if (root == nullptr) {
    return false;
  }
  
  Node* currNode = root;
  // Iterate through the tree depending on how the key compares to the currNode
  // If node with the correct key found -> return true
  while (currNode != nullptr){
    if (currNode -> key == key){
      return true;
    }
    else if (key < currNode -> key){
      currNode = currNode -> left;
    }
    else {
      currNode = currNode -> right;
    }
  }
  // Otherwise return false
  return false;
}

// Return the largest value in the tree
string BSTree::largest() const {
  // If empty -> return empty string
  if (root == nullptr){
    return ""; 
  }
  Node* currNode = root;
  // To find largest find the rightmost leaf node 
  while (currNode -> right != nullptr){
    currNode = currNode -> right;
  }
  // Return the key
  return (currNode -> key);
}

// Return the smallest value in the tree
string BSTree::smallest() const {
  // If empty -> return empty string
  if (root == nullptr) {
    return "";
  }

  Node* currNode = root;
  // To find smallest find the leftmost leaf node
  while (currNode -> left != nullptr) {
    currNode = currNode -> left;
  }

  return (currNode -> key);
}

// Private helper function
// Same as search() function, but returns the node if found
Node* BSTree::findNode(const string& key) const {
  if (root == nullptr) {
    return nullptr;
  }

  Node* currNode = root;
  while (currNode != nullptr) {
    if (currNode -> key == key){
      return currNode;
    }
    else if (key < currNode -> key) {
      currNode = currNode -> left;
    }
    else {
      currNode = currNode -> right;
    }
  }
  return nullptr;
}

// Public member function that calls the height_of() recursive helper function
int BSTree::height(const string& key) const {
  return height_of(findNode(key));
}

// Public member function that calls the recursive remove function
void BSTree::remove(const string& key) {
  removeRecursive(key);
}

// Public member function -> calls calls the recursive preOrder function
void BSTree::preOrder() const {
  preOrder(root);
  cout << endl;
}

// Public member function -> calls calls the recursive postOrder function
void BSTree::postOrder() const {
  postOrder(root);
  cout << endl;
}

// Public member function -> calls calls the recursive inOrder function
void BSTree::inOrder() const {
  inOrder(root);
  cout << endl;
}

// Remove helper function
// If duplicates -> remove duplicate
// If leaf -> remove leaf
// If internal node -> swap with predecessor/sucessor then delete internal node
// If predecessor/sucessor also internal node -> keep swapping until remove node becomes leaf
void BSTree::removeRecursive(const string &key) {
  Node* parent = nullptr;
  Node* currNode = findNode(key);

  // If node is in the tree and has at least 1 duplicate -> remove duplicate
  if (currNode) { 
    if(currNode -> count > 1) {
      currNode -> count--;
      return;
    }
  }
  currNode = root;

  // Traverse through tree while currNode is not nullptr
  while (currNode) {
    // If node is found -> move to edge cases
    if (currNode -> key == key) { 
      // If leaf -> next three test cases
      if (!currNode -> left && !currNode -> right) {
        // If node is the root -> set root to nullptr
        if (!parent) {
          root = nullptr;
        }
        // If node is on the left
        else if (parent -> left == currNode) {   
          parent -> left = nullptr;
        }
        // If node is on the right
        else {
          parent -> right = nullptr;
        }
        delete currNode;
      }
      // If internal node & has left child
      else if (currNode -> left) {
        Node *leftChild = currNode -> left;
        // Traverse to the location of the predecessor
        while (leftChild -> right) {
          leftChild = leftChild -> right;
        }
        // Update the values for the predecessor -> save to swap with internal node
        string predecessorKey = leftChild -> key;
        int predecessorCount = leftChild -> count;

        leftChild -> count = 1;
        remove(leftChild -> key);  // Recursively call to remove predecessor

        // Swap values of internal with those of the predecessor 
        currNode -> key = predecessorKey;
        currNode -> count = predecessorCount;
      }
      // If internal node does not have a predecessor (no left child) -> move to the right
      // Same idea as looking for predecessor, but operates in the other direction 
      else if (currNode -> left == nullptr) {
        Node *rightNode = currNode -> right;
        while (rightNode -> left) {
            rightNode = rightNode -> left;
        }
        string successorKey = rightNode -> key;
        int successorCount = rightNode -> count;

        rightNode -> count = 1;
        remove(rightNode -> key);    

        currNode -> key = successorKey; 
        currNode -> count = successorCount;
      }
      return; // If any of the test cases were satisfied -> node was sucessfully removed
    }
    // Search right if key > node
    else if (key > currNode -> key) {
      parent = currNode;
      currNode = currNode -> right;
    }
      // Search left if key < node
    else {
      parent = currNode;
      currNode = currNode -> left;
    }
  }
  return; // None of the test cases satisfied -> not able to find node (nothing changed)
}



// The height (length of longest path to the bottom) of an empty tree is -1
// Otherwise, you pick the larger of the left height and the right height
// and add one to that
int BSTree::height_of(Node* tree) const {
  // Return -1 for height if tree is empty
  if (tree == nullptr) {
    return -1;
  }
  
  // Recursion to find the height of the left and right side of the tree 
  int leftHeight = 1 + height_of(tree -> left);
  int rightHeight = 1 + height_of(tree -> right);
  
  // Returns the height from the larger side of the two
  return std::max(leftHeight, rightHeight);
}

void BSTree::preOrder(Node* tree) const {
  if (tree == nullptr) {
    return;
  }
  // print key, do left, do right
  cout << tree -> key << "(" << tree -> count << "), ";
  preOrder(tree -> left);
  preOrder(tree -> right);
}

void BSTree::postOrder(Node* tree) const {
  if (tree == nullptr) {
    return;
  }

  // do left, do right, print key
  postOrder(tree -> left);
  postOrder(tree -> right);
  cout << tree -> key << "(" << tree -> count << "), ";
}

void BSTree::inOrder(Node* tree) const {
  if (tree == nullptr) {
    return;
  }

  // do left, print key, do right
  inOrder(tree -> left);
  cout << tree -> key << '(' << tree -> count << "), ";
  inOrder(tree -> right);
}
