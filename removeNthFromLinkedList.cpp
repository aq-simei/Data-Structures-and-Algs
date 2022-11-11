// exercise link : https://leetcode.com/problems/remove-nth-node-from-end-of-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
  if(head == nullptr || head->next == nullptr){return nullptr;}

  ListNode * curr = head;
  int listSize = 0;
  while(curr != nullptr){
    curr=curr->next;
    listSize++;
  }
  curr = head;
  int toRemoveTracker = listSize - n;

  for(int i = 1; i < toRemoveTracker; i++){
    curr=curr->next;
  }
  if(curr == head){
    head = head->next;
  }
  
  ListNode * previous = curr;
  ListNode* toRemoveNode = curr->next;
  ListNode* nextNode = toRemoveNode->next;
  previous->next = nextNode;
  return head;
}
};

