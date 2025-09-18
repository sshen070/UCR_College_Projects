#include "IntList.h"

bool IntList::bubbleUp() {
   if (head == nullptr){
      return false;
   }
   if (head -> next){
      return false;
   }
   bubbleUp(head);
}

bool IntList::bubbleUp(IntNode *curr) {
   
}
