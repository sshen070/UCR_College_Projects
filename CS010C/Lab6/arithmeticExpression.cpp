#include <iostream>
#include <sstream>
#include <stack>

#include "arithmeticExpression.h"

using namespace std;

// Constructor
arithmeticExpression::arithmeticExpression(const string& expression)
  : infixExpression(expression),
    root(nullptr)
{
}

// Destructor -> uses deleteTree() to recursive delete all nodes in the tree
arithmeticExpression::~arithmeticExpression() {
    deleteTree(root);
}

// Recursively deletes all of the nodes in the tree -> traverses to the left then right 
void arithmeticExpression::deleteTree(TreeNode* subtree) {
    if (!subtree) {
        return;
    }
    deleteTree(subtree -> left);
    deleteTree(subtree -> right);
    delete subtree;
}

// Uses the postfix order to create a tree representing all of the operations
void arithmeticExpression::buildTree() {
    stack <TreeNode*> prefixStack;
    string postFixString = infix_to_postfix();  // Converts infix -> postfix to make adding nodes easier
    unsigned charCounter = 0;

    // Traverses for for the size of the postfix string
    while (charCounter < postFixString.size()) {
        // Creates a new node in the stack for every char
        TreeNode* addNode = new TreeNode(postFixString.at(charCounter), 'a' + charCounter);

        // If the char is not a operator (+, -, *, / ...) -> add it to the stack
        if (priority(postFixString.at(charCounter)) == 0) {
            prefixStack.push(addNode);
        }

        // Otherwise if operator -> make the current nodes in the tree (digits) the children of the operator node
        else if (postFixString.at(charCounter) == '+' || postFixString.at(charCounter) == '-' || postFixString.at(charCounter) == '*' || postFixString.at(charCounter) == '/') {
            addNode -> right = prefixStack.top();
            prefixStack.pop();
            addNode -> left = prefixStack.top();
            prefixStack.pop();
            prefixStack.push(addNode);
            root = addNode;
        }
        // In the case that any of the chars are not digits OR not operators -> no memory leaks
        else {
            delete addNode;
        }
        charCounter++;  // Increment to move to next char
    }
}

// Calls the infix() helper function
void arithmeticExpression::infix() const {
    infix(root);
}

// Calls the prefix() helper function
void arithmeticExpression::prefix() const {
    prefix(root);                       
}

// Calls the postfix() helper function
void arithmeticExpression::postfix() const {
    postfix(root);                   
}

// Recursively calls itself to print the values in infix notation -> (a+(b*c))
void arithmeticExpression::infix(TreeNode* subtree) const {
    if (!subtree) {
        return;
    }
    // Value is a digit -> the following recursive calls
	if (priority(subtree -> data) == 0){    
        infix(subtree -> left);
        cout << subtree -> data;
        infix(subtree -> right);
    }
    // Value is a operator -> the following calls + include parentheses to indicate scope
    else {
		cout << "(";
		infix(subtree -> left);
		cout << subtree -> data;
		infix(subtree -> right);
		cout << ")";
	}
}

// Recursively calls itself to print the values in prefix notation -> +a*bc
void arithmeticExpression::prefix(TreeNode* subtree) const { 
    if (!subtree) {
        return;
    }
    // Prints operator first and goes down the left subtree -> returns then goes down the right subtree
    cout << subtree -> data;
    prefix(subtree -> left);
    prefix(subtree -> right);
}

// Opposite of prefix notation -> calls itself to print the values in postfix notation -> abc*+
void arithmeticExpression::postfix(TreeNode* subtree) const {
    if (!subtree) {
        return;
    }
    // Prints leafs on left -> moves to operator holding them together then right leafs -> finally works it way to the root
    postfix(subtree -> left);
    postfix(subtree -> right);
    cout << subtree -> data;
}

// Given function -> returns the priority of the different chars (digits -> 0, operators have different precedence)
int arithmeticExpression::priority(char op) {
    int priority = 0;
    if (op == '(') {
        priority =  3;
    }
    else if (op == '*' || op == '/') {
        priority = 2;
    }
    else if (op == '+' || op == '-') {
        priority = 1;
    }
    return priority;
}

// Given function -> converts infix notation to postfix for tree construction
string arithmeticExpression::infix_to_postfix() const {
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i) {
        c = infixExpression.at(i);
        if (c == ' ') {
            continue;
        }
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') { //c is an operator
            if ( c == '(') {
                s.push(c);
            }
            else if (c == ')') {
                while(s.top() != '(') {
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())) {
                    if (s.top() == '(') {
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()) {
        oss << s.top();
        s.pop();
    }
    return oss.str();
}
