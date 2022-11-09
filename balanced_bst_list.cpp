// https://www.geeksforgeeks.org/introduction-to-height-balanced-binary-tree/ 
// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    ListNode* middleNode(ListNode* start,ListNode* end) {
      ListNode* slow=start,*fast=start;
      while (fast!=end&&fast->next!=end) {
        slow=slow->next;
        fast=fast->next->next;
      }
      return slow;
    }
    TreeNode* buildTree(ListNode* start,ListNode* end) {
      if (start==end) return nullptr;
      ListNode* mid=middleNode(start,end);
      TreeNode* root=new TreeNode(mid->val);
      root->left=buildTree(start,mid);
      root->right=buildTree(mid->next,end);
      return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return buildTree(head,nullptr);
    }
};

/*
*/
