// problem link https://leetcode.com/problems/same-tree/
// check out is_symmetric.cpp to see a tree traversing problem in a different context

/**
 * Definition for a binary tree node.
 */
//pos - order problem
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  class Solution {
  public:
      bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true; 
        if(p == nullptr && q != nullptr) return false;
        if(q != nullptr && p == nullptr) return false;
        if(isSameTree(p->left, q->left) && isSameTree(p->right, q -> right) && p->val == q->val) return true;
      };
  };
  // check if nodes have the same value
  // check if both of them have both children to compare
  // if so, check their values
