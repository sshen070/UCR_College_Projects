#include "IntList.h"

#include <ostream>

using namespace std;

   IntList::IntList() : head(nullptr) {}


   void IntList::push_front(int val) {
      if (!head) {
         head = new IntNode(val);
      } else {
         IntNode *temp = new IntNode(val);
         temp->next = head;
         head = temp;
      }
   }

   ostream & operator<<(ostream &out, const IntList &rhs){
      if (rhs.head != nullptr){
         out << rhs.head -> value << ' ';
         operator<<(out, rhs.head -> next);
      }
      return out;
   }

   bool IntList::exists(int val) const{
      if (head == nullptr){
         return false;
      }
      return exists(head, val);
   }

// Helper Functions
   ostream & operator<<(ostream &out, IntNode *start){
      if (start == nullptr){
         return out;
      }
      out << start -> value << ' ';
      return operator<<(out, start -> next);
   }

   bool IntList::exists(IntNode *searchNode, int val) const{
      if (searchNode -> value == val){
         return true;
      }
      else if (searchNode -> next == nullptr){
         return false;
      }
      return exists(searchNode -> next, val);
   }

