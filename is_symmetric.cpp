// https://leetcode.com/problems/symmetric-tree/
// check out sameTree.cpp to see a tree traversing problem in a different context
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
bool is_mirror(TreeNode* image, TreeNode* mirror){
  if(!image && !mirror) return true;
  if((!image && mirror) || (image && !mirror)) return true;
  if(image->val == mirror->val) {
    return is_mirror(image->right, mirror->left) && is_mirror(image->left, mirror->right);
  }
}

bool is_symmetric(TreeNode* root){
  return is_mirror(root->right, root->left);
}
