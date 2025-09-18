#include <iostream>
#include <string>

using std::string;
using std::cout;

class BST {
  struct Node {
    string key;
    Node* left;
    Node* right;
    Node(const string& key) : key(key), left(nullptr), right(nullptr) {}
  };

  Node* root = nullptr;

  bool search(const Node* subtree, const string& key) const {
    if (subtree == nullptr) return false;
    if (key == subtree->key) return true;
    if (key < subtree->key) return search(subtree->left,key);
    return search(subtree->right, key);
  }

  Node* insert(Node* subtree, const string& key) {
    if (subtree == nullptr) {
      return new Node(key);
    }

    if (key == subtree->key) return subtree;
    if ( key < subtree->key ) {
      subtree->left = insert(subtree->left, key);
      return subtree;
    }
    subtree->right = insert(subtree->right, key);
    return subtree;
  }

  Node* remove(Node* subtree, const string& key) {
    if (subtree == nullptr) return nullptr;
    if (key == subtree->key) {
      // Leaves are easy!
      if (subtree->left == nullptr && subtree->right == nullptr){
        delete subtree;
        return nullptr;
      }
      // Only a left? or perhaps both?
      if (subtree->left != nullptr){
        Node* largest = subtree->left;
        while (largest->right != nullptr) largest = largest->right;

        // Copy that largest of my left subtree to me
        subtree->key = largest->key;

        // Remove the duplicate I need
        subtree->left = remove(subtree->left, largest->key);

        return subtree;
      }

      // Just a right
      else {
        Node* smallest = subtree->right;
        while (smallest->left != nullptr) smallest = smallest->left;

        subtree->key = smallest->key;
        subtree->right = remove(subtree->right, smallest->key);
        return subtree;
      }

    } else if (key < subtree->key) {
      subtree->left = remove(subtree->left, key);
    } else {  // key > subtree->key
      subtree->right = remove(subtree->right, key);
    } 

    return subtree;  // Correctly return the unchanged subtree
  }
  
  void printme(const Node* subtree) const {
    if (subtree == nullptr) return;
    printme(subtree->left);
    cout << subtree->key << ' ';
    printme(subtree->right);
  }

public:
  void printme() const {
    printme(root);
    cout << std::endl;
  }
  bool is_empty() const {
    return (root == nullptr);
  }

  void insert(const string& key) {
    root = insert(root, key);
  }

  bool search(const string& key) const {
    return search(root, key);
  }

  // Make the remove function public
  void remove(const string& key) {
    root = remove(root, key);  // Call the private remove function with the root
  }
};

int main() {
  BST B;

  cout << B.is_empty() << '\n';

  B.insert("M");
  B.insert("hello");
  cout << B.is_empty() << '\n';

  cout << B.search("hello") << '\n';
  cout << B.search("M") << std::endl;

  B.printme();
  B.remove("G");  // This will not do anything as "G" does not exist in the tree
  B.printme();

  return 0;
}
