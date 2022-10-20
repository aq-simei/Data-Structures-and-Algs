#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;


int fib(int n) {
  // for n = 3
  // fib(3) => fib(2) + fib(1) ==> calls the fib function twice 
  // for n = 4 
  // fib(4) = fib(3) + fib(2) ==> fib(2) + fib(1) + fib(1) + fib(0) ==> calls the fib function four times 2 ^ n (raises its time consumption to the power of n) => O(2 ** n) for time complexity
  //         -> fib(3) => fib(2) + fib(1) 
  //         -> fib(2) => fib(1) + fib(0)

  // for n = 5 =>> fib(5) => fib(1) + fib(0) + fib(1) + fib(1) + fib(0) + fib(1) + fib(1) + fib(0) => for N=5, we need to call the fib function 8 times => O(2 ** n) for time complexity
  if (n <= 1) { 
    return n;
  }
  return fib(n - 1) + fib(n - 2);
}


// __B__



// input => "abc"

void permutation(string str, string prefix) { //think about a str with prefix ""
  if (str.length() == 0) {
    cout << prefix;
  } else {
    for (int i = 0; i < str.length(); i++) {
      string rem = str.substr(0, i) + str.substr(i + 1);
      permutation(rem, prefix + str[i]); 
    }
  }
}


// LeetCode Merge two lists;
class Node {
  public: 
    int data;
    Node* next;
};

Node* MergeLists(Node* a, Node* b){
  Node* result = NULL;
  //base cases when one of the lists is empty
  if(a == NULL) {
    return b;
  }

  else if(b == NULL){
    return a;
  }

  if( a->data <= b->data ) {//compare the values of a and b => in this case, b is greater or equal to a 
    result = a;
    result->next = MergeLists(a->next, b);
  }
  else{
    result = b;
    result->next = MergeLists(a, b->next);
  }
  cout << result << endl;
  return result;
}

int main(){
  Node* list1 = new Node();
  Node* list2 = new Node();
  MergeLists(list1, list2);
  return(0);
}


class Node {
  public:
  int data;
  Node* next;
};

// LeetCode Merge two lists (recursive solution);
Node* orderListsRecursively(Node* firstNode, Node* secondNode){
  Node* result = NULL;
  if(firstNode == NULL){
    return secondNode;
  }
  else if(secondNode == NULL){
    return firstNode;
  }
  if(firstNode->data <= secondNode->data){
    result = firstNode;
        cout << result->data << endl;
    result->next = orderListsRecursively(firstNode->next, secondNode);
  }
  else{
    result = secondNode;
    cout << result->data << endl;
    result->next = orderListsRecursively(firstNode, secondNode->next);
  }
  return result;
};



 // LeetCode Merge two lists -> Iterative solution
Node* orderLists(Node* firstListNode, Node* secondListNode, Node* currentPointer){
  Node* newSortedHead = NULL;
  //first check
  if( firstListNode == NULL ){
    return secondListNode;
  }
  if( secondListNode == NULL ){
    return firstListNode;
  }
  if( firstListNode && secondListNode ){
    if( firstListNode -> data <= secondListNode -> data ){
      currentPointer = firstListNode;
      firstListNode = currentPointer -> next; 
    }
    else{
      currentPointer = secondListNode;
      secondListNode = currentPointer -> next;
    }
  }
    newSortedHead = currentPointer;

    while( firstListNode && secondListNode ){
      if( firstListNode->data <= secondListNode->data ){
        currentPointer -> next = firstListNode;
        currentPointer = firstListNode;
        firstListNode = currentPointer -> next;
      }
      else{
        currentPointer -> next = secondListNode;
        currentPointer = secondListNode;
        secondListNode = currentPointer -> next;
      }
    }
      if( firstListNode == NULL ){
        currentPointer -> next = secondListNode;
      }
      if( secondListNode == NULL ){
        currentPointer -> next = firstListNode;
      }
  return newSortedHead;
  };

  
int main() {
  Node* headOfList1 = NULL;
  Node* secondOfList1 = NULL;
  Node* thirdOfList1 = NULL;
  Node* currentPointer = NULL;

  Node* headOfList2 = NULL;
  Node* secondOfList2 = NULL;
  Node* thirdOfList2 = NULL;

  headOfList1 = new Node();
  secondOfList1 = new Node();
  thirdOfList1 = new Node();

  headOfList2 = new Node();
  secondOfList2 = new Node();
  thirdOfList2 = new Node();

  headOfList1->data = 1;
  headOfList1->next = secondOfList1;

  secondOfList1->data = 2;
  secondOfList1->next = thirdOfList1;

  thirdOfList1->data = 4;
  thirdOfList1->next = NULL;

  headOfList2->data = 1;
  headOfList2->next = secondOfList2;

  secondOfList2->data = 3;
  secondOfList2->next = thirdOfList2;

  thirdOfList2->data = 4;
  thirdOfList2->next = NULL;

  orderLists(headOfList1, headOfList2, currentPointer);
  return 0;
}
 


struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr){};
  ListNode(int x) : val(x), next(nullptr){};
  ListNode(int x, ListNode *next) : val(x), next(next){};
};

 

ListNode* deleteDuplicates(ListNode* head){
  ListNode* current = head;
  ListNode* ahead = NULL;
  while(current != NULL && current->next != NULL){
    if(current->val != current->next->val){ // no repeated value, sets current pointer to next; NO NEED TO FIX THE NEXT POINTER;
      current = current->next; // only passes the current pointer to another node when all duplicates are removed;
    }
    if(current->val == current->next->val){ //values are equal
      ahead = current->next->next; //set ahead pointer to second next node of the link to see if there are more repeated values
      if(ahead == NULL){ // the current->next node is the last one in the list
        current->next = NULL; //makes the current values when are looking at with current pointer the last node in the list;
        break;
      }
      current->next = ahead; //set the current->next to link the second next node;;
    }
  }
}


ListNode* removeAllDuplicates(ListNode* head){
  ListNode* current = head;
  ListNode* ahead = NULL;
  ListNode* previous = NULL;
  ListNode* newHead = NULL;

  while (current == head){
    if(current -> val != current -> next -> val){
      newHead = current;
      current = current -> next;
      ahead = current -> next;
      return newHead;
    }
    if(current -> val == current -> next -> val){
      ahead = current -> next -> next;
      if(ahead == NULL){
        current -> next = NULL;
        break;
      }
      if(ahead->val != current->val){
        current = ahead;
        head = current;
        ahead == current -> next;
      }
    }
  }
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* getMiddleNode(ListNode* head){
  ListNode* slowRunner = head;
  ListNode* fastRunner = head;

  while(fastRunner != nullptr && fastRunner->next != nullptr){
    slowRunner = slowRunner->next;
    fastRunner = fastRunner->next->next;
  }
  return slowRunner;
}

