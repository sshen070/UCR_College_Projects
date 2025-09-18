#include <string>
using std::string;

class TwoThree {
  struct Node {
    Node* left;
    Node* mid;
    Node* right;
    Node* parent;

    string low;
    string high;
    int count;
  };

  void stealFromLeftSibling(Node* curr, Node* left) {
    Node* parent = curr->parent;
    // assert parent == left->parent
    curr->low = parent->low;
    curr->count = 1;

    parent->low = left->high;

    left->count = 1;
  }


  Node* findRightSibling(Node* curr) {
    if ( curr == nullptr ) return nullptr;
    if ( curr->parent == nullptr ) return nullptr; // root?

    Node* parent = curr->parent;
    if (curr == parent->left) { // I am my parent's left child. RS is p->mid
      return parent->mid;
    } else if ( curr == parent->mid ) {
      return parent->right;
      // if ( parent->count > 1 ) return parent->right;
      // return nullptr;
    } else {
      // must be the right child of my parent
      return nullptr;
    }
  }
};