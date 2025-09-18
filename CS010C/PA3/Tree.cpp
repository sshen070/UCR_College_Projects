#include "Tree.h"
#include <iostream>
#include <string>

using namespace std;

// Constructor
Tree::Tree() {
  root = nullptr;
}

// Destructor
Tree::~Tree() {
  destroyTree(root);
  root = nullptr;
}

// Private helper function for destructor -> deletes all the nodes through recursion
void Tree::destroyTree(Node* node) {
  if (!node) {
    return;
  }

  destroyTree(node -> left);
  destroyTree(node -> middle);
  destroyTree(node -> right);
  delete node;
}

// If left, right, & middle children of the node are nullptr -> return true (no children)
bool Tree::noChildren(Node* node) const {
  return (!node -> left && !node -> middle && !node -> right);
}


// Public function insert -> creates a root if no root exists otherwise calls the insert helper function
void Tree::insert(const string& word) {
  if (root == nullptr) {
    root = new Node(word);
  }
  else {
    insert(root, word);
  }
}

// Private helper function insert -> base case if curr == root/leaf
// If root add word or split if full
// Same idea with when word belongs in a leaf ((noChildren(curr)) is true) -> either add word or split
// Edge case -> word is already in the tree
void Tree::insert(Node* curr, const string& word) {
  // If the word is already in the Tree -> no action (no duplicates)
  if (search(word)) {
    return;
  }

  // If the curr node is the root/leaf
  if (noChildren(curr)) {
    // If node has 1 key
    if (curr -> numData == 1) {
      addData(curr, word);
    }
    // If node has 2 keys
    else {
      splitFullLeaf(curr, word);
    }
  }

  // If word belongs in leaf
  else {
    // Traverse to the appropriate child based on the value of the word
    if (word < curr -> small) {
      // If left child doesn't exist -> create one
      if (!curr -> left) {
        Node* leftChild = new Node(word);
        curr -> left = leftChild;
        leftChild -> parent = curr;
      }
      // Else -> keep moving left to the right insert location
      else {
        insert(curr -> left, word);
      }
    }

    else if (curr -> numData == 1 || word < curr -> large) {
      // If right spot and middle node does not exist already -> create one
      if (!curr -> middle) {
        Node* middleChild = new Node(word);
        curr -> middle = middleChild;
        middleChild -> parent = curr;
      }
      // Otherwise -> keep traversing to the right spot
      else {
        insert(curr -> middle, word);
      }
    }

    else {
      // Same idea as left & middle, but for the right node
      if (!curr -> right) {
        Node* rightChild = new Node(word);
        curr -> right = rightChild;
        rightChild -> parent = curr;
      }
      // Else -> keep moving right
      else {
        insert(curr -> right, word);
      }
    }
  }
}


// Private helper function for the insert function
// Addresses cases where root is full -> split up
// Case: if leaf node is full and parent node has only 1 key -> split middle key up to parent & create a middle node
void Tree::splitFullLeaf(Node* curr, const string& word) {

  // If curr is the root node -> no parent
  // Depending on how the inserted key compares to the current keys -> middle key becomes parent
  if (!curr -> parent) {
    // Word < small & large
    if (word < curr -> small) {
      Node* parent = new Node(curr -> small);
      removeData(curr, curr -> small);
      Node* newChild = new Node(word);
      parent -> left = newChild;
      parent -> right = curr;

      // Children must point back to parent
      root = parent;
      newChild -> parent = root;
      curr -> parent = root;
    }
    // Word > small & word < large
    else if (word > curr -> small && word < curr -> large){
      Node* parent = new Node(word);
      Node* newChild = new Node(curr -> large);
      removeData(curr, curr -> large);
      parent -> left = curr;
      parent -> right = newChild;

      // Children must point back to parent
      root = parent;
      newChild -> parent = root;
      curr -> parent = root;

    }
    // Word > small & large
    else {
      Node* parent = new Node(curr -> large);
      removeData(curr, curr -> large);
      Node* newChild = new Node(word);
      parent -> left = curr;
      parent -> right = newChild;

      // Children must point back to parent
      root = parent;
      newChild -> parent = root;
      curr -> parent = root;
    }
  }

  // Otherwise -> the node to insert into is not the root
  // Different set of insertion involving the spliting the a node up to the parent and creating a middle child
  else if (curr -> parent) {
    // If parent has 1 key & child has 1 key case should have been finished in base case insert function
    if (curr -> parent -> numData == 1 && curr -> numData == 1) {
      throw runtime_error("ERROR case should be completed insert function");
    }

    // If the parent has only 1 key & node to insert has 2 -> middle key is split up to parent & leftmost/rightmost key becomes the middle node
    else if (curr -> parent -> numData == 1 && curr -> numData == 2) {
      Node* parent = curr -> parent;
      // Case if curr is on the left of parent
      if (curr == parent -> left) {
        // Word < small & large
        if (word < curr -> small) {
          addData(parent, curr -> small);
          removeData(curr, curr -> small);
          Node* middleChild = new Node(curr -> large);
          
          addData(curr, word);
          removeData(curr, curr -> large);
          parent -> middle = middleChild;

          // Children must point back to parent
          middleChild -> parent = parent;
       }
        // Word > small & word < large
        else if (word > curr -> small && word < curr -> large) {
          addData(parent, word);
          Node* middleChild = new Node(curr -> large);
          removeData(curr, curr -> large);
          parent -> middle = middleChild;

          // Children must point back to parent
          middleChild -> parent = parent;
        }
        // Word > small & large
        else {
          addData(parent, curr -> large);
          Node* middleChild = new Node(word);
          removeData(curr, curr -> large);
          parent -> middle = middleChild;

          // Children must point back to parent
          middleChild -> parent = parent;
        }
      }
      // Other case if curr is on the right of parent
      else if (curr == parent -> right) {
        // Word < small & large
        if (word < curr -> small) {
          addData(parent, curr -> small);
          removeData(curr, curr -> small);
          Node* middleChild = new Node(word);
          parent -> middle = middleChild;

          // Children must point back to parent
          middleChild -> parent = parent;
        }
        // Word > small & word < large
        else if (word > curr -> small && word < curr -> large) {
          addData(parent, word);
          Node* middleChild = new Node(curr -> small);
          removeData(curr, curr -> small);
          parent -> middle = middleChild;

          // Children must point back to parent
          middleChild -> parent = parent;
        }
        // Word > small & large
        else {
          addData(parent, curr -> large);
          removeData(curr, curr -> large);
          Node* middleChild = new Node(curr -> small);

          addData(curr, word);
          removeData(curr, curr -> small);
          parent -> middle = middleChild;

          // Children must point back to parent
          middleChild -> parent = parent;
        }
      }
    }
    // Leaf & parent has 2 keys -> double split
    else if (curr -> parent -> numData == 2) {
      throw runtime_error("Parent node is full case not yet implemented.");
    }
  }
}


void Tree::remove(const string& word) {
  // If tree empty OR key not in tree -> nothing to remove
  if (!root || !search(word)) {
    return;
  }
  
  Node* removeNode = search(word);

  // Special case: removing the a key in the root 
  if (removeNode == root) {
    // If root contains the key to be removed & root has no children
    if (noChildren(removeNode)) {
      // Delete root if only 1 key
      if (root -> numData == 1) {
        delete root;
        root = nullptr;
        return;
      }
      // Remove key if two keys in root
      else {
        removeData(removeNode, word);
      }
    }
    // Root has >1 child (2 children)
    else if (removeNode -> numData == 1) {
      // If both left & right children only have 1 key
      if (removeNode -> left && removeNode -> left -> numData == 1 && removeNode -> right && removeNode -> right -> numData == 1) {
        // And neither of the children have children of their own -> create new root node and remove existing
        if (noChildren(removeNode -> left) && noChildren(removeNode -> right)) {
          Node* rightChild = removeNode -> right;
          addData(removeNode -> left, rightChild -> small);
          delete removeNode;
          delete rightChild;
          root = removeNode -> left;
        }
      }
    }
  }
  
  // If the key is located in a child of the root node
  else if (removeNode -> parent == root) {
    // Make sure there is space to bring the child up to the parent
    if (root -> numData == 1) {
      Node* parentNode = removeNode -> parent;
      // If node to remove is left & has a right sibling & they both have 1 key and no children -> move right key up to parent 
      if (removeNode == parentNode -> left) {
        if (noChildren(removeNode) && removeNode -> numData == 1 && parentNode -> right && noChildren(parentNode -> right) && parentNode -> right -> numData == 1) {
          Node* rightChild = parentNode -> right;
          addData(parentNode, rightChild -> small);
          delete removeNode;
          delete rightChild;
        }
      }
      // Same idea as the case with the left node -> but for the right instead
      // Bring left key up to parent if both children only have 1 key & no children
      else if (removeNode == parentNode -> right) {
        if (noChildren(removeNode) && removeNode -> numData == 1 && parentNode -> left && noChildren(parentNode -> left) && parentNode -> left -> numData == 1) {
          Node* leftChild = parentNode -> left;
          if (leftChild -> numData == 1) {
            addData(parentNode, leftChild -> small);
            delete removeNode;
            delete leftChild;
          }
        }
      }
      parentNode -> left = nullptr;  // Since only parent remains -> both sides set to nullptr
      parentNode -> right = nullptr;
    }
    else {
      throw runtime_error("Root has two keys & children case not yet done");
    }
  }

  // If removeNode has two keys -> remove the key that matches
  else if (noChildren(removeNode)) {
    if (removeNode -> numData == 2) {
      removeData(removeNode, word);
    }
    else {
      throw runtime_error("Remove key from node w/ only 1 key case not yet implemented");
    }
  }
}

// This is handy since it puts a key into the right spot (small or large string)
void Tree::addData(Node* addHere, const string& word) {
  // If word < small -> word becomes small and small is shifted over to large 
  if (word < addHere -> small) {
    addHere -> large = addHere -> small;
    addHere -> small = word;
  }
  else {
    addHere -> large = word;
  }
  addHere -> numData++; // Incremented to keep track of the # of keys in node
}

// Removes a key from the node useful for insert/remove functions
void Tree::removeData(Node* removeHere, const string& word) {
  // Shifts large value over to the small spot if small word is removed
  if (removeHere -> small == word) {
    removeHere -> small = removeHere -> large;
    removeHere -> large = "";
  }
  else {
    removeHere -> large = "";
  }
  removeHere -> numData--; // Decremented to keep track of the # of keys in node
}

void Tree::preOrder() const {
  preOrder(root);
  cout << endl;
}

// Helper function for the preOrder function -> prints out the keys in preOrder format
void Tree::preOrder(const Node* curr) const {
  // Base case
  if (!curr) {
    return;
  }

  // If node contains two keys -> print small and traverse left until nullptr then while returning print out the large values
  // Then do the same thing traversing middle & right
  if (curr -> numData == 2) {  
    cout << curr -> small << ", " ;
    preOrder(curr -> left) ;
    cout << curr -> large << ", ";
    preOrder(curr -> middle) ;
    preOrder(curr -> right) ;
  }

  // If only 1 key -> print small and traverse (no large key to print)
  else {
    cout << curr -> small << ", ";
    preOrder(curr -> left);
    preOrder(curr -> middle);
    preOrder(curr -> right);
  }
}

void Tree::inOrder() const {
  inOrder(root);
  cout << endl;
}

// Helper function for the inOrder function -> prints out the keys in inOrder format
void Tree::inOrder(const Node* curr) const {
  // Base case
  if (!curr) {
    return;
  }
  
  // Since values printed in sequential order -> must start at the bottom left and print
  // As returning back up traverse down the middle & right
  inOrder(curr -> left);
  cout << curr -> small << ", ";
  inOrder(curr -> middle);

  if (curr -> numData == 2) {
    cout << curr -> large << ", ";
  }
  inOrder(curr -> right);
}

void Tree::postOrder() const {
  postOrder(root);
  cout << endl;
}

// Helper function for the postOrder function -> prints out the keys in posterOrder format
void Tree::postOrder(const Node* curr) const {
  // Base case
  if (!curr) {
    return;
  }

  // Traverse down to the leaf -> print leaves on left side then internal node
  // Move to the right subtree & print leaves -> return back up to the root
  if (curr -> numData == 2) {
    postOrder(curr -> left); // Left & middle first -> then right
    postOrder(curr -> middle);
    cout << curr -> small << ", ";
    postOrder(curr -> right);
    cout << curr -> large << ", ";
  }

  else {
      postOrder(curr -> left);
      postOrder(curr -> right);
      cout << curr -> small << ", ";
  }
}

// Majority of insertion & removal cases done in respective functions
void Tree::fix(Node* emptyNode) {
  if (!emptyNode) {
    return;
  }
  
  else {
    throw runtime_error("Merge/Redistribution not yet done!");
  } 
}

// Returns boolean value representing if the node passed in has two siblings or not
bool Tree::hasTwoChildSibling(Node* sib) const {
  // If no parent -> no siblings
  if (!sib -> parent) {
    return false;
  }

  // Determine which child -> then if the other siblings exist 
  Node* parentNode = sib -> parent;
  if (sib == parentNode -> left) {
    if (parentNode -> middle && parentNode -> right) {
      return true;
    }
  }

  else if (sib == parentNode -> middle) {
    if (parentNode -> left && parentNode -> right) {
      return true;
    }
  }

  else if (sib == parentNode -> right) {
    if (parentNode -> left && parentNode -> middle) {
      return true;
    }
  }
  return false;  // If does not have two siblings -> return false
}


Node* Tree::search(const string& word) {
  return search(root, word);
}

// Recursive helper function for the search function
Node* Tree::search(Node* curr, const string& word) {

  // Base case: keep traversing until node with key reached or nullptr
  if (!curr) {
    return nullptr;
  }

  else {
    // If node contain key is found -> return the node
    if (curr -> small == word || curr -> large == word) {
      return curr;
    }

    // Traverse left if word < small
    if (word < curr -> small) {
      return search(curr -> left, word);
    }

    // Traverse middle if word < small && word > large
    else if (word > curr -> small && word < curr -> large) {
      return search(curr -> middle, word);
    }

    // Traverse right if word > small & large
    else if (word > curr -> large) {
      return search(curr -> right, word);
    }
  }
  return nullptr;
}
