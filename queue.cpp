#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
  stack<int> mainStack, auxStack;
  int front;
    MyQueue() {
    }
    
    void push(int x) { // O(N)
      if(mainStack.empty()){
      }
      while(!mainStack.empty()){ 
        auxStack.push(mainStack.top()); // swap elements from mainStack to auxStack ( reversed order );
        mainStack.pop();
      }
      auxStack.push(x); // when the main stack is empty, push the last element of the queue into the mainStack
      while(!auxStack.empty()){ // while the auxStack is not empty, send it's elements to the mainStack (back in the original order)
        mainStack.push(auxStack.top()); 
        auxStack.pop();
      }
    }

    int pop() { // O(1)
      int removed = mainStack.top();
      mainStack.pop();
      return removed;
    }
  

    int peek() {
        return mainStack.top();
    }

    bool empty() {
        bool isStackEmpty = mainStack.empty();
      return isStackEmpty;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
