vector<int> result;
getPreOrder(root, result);
return result;
getPreOrder(TreeNode* root, vector<int> & result){
  if(root == nullptr){
    return;
  }
  result.push_back(root->val);
  getPreOrder(root->left, result);
  getPreOrder(root->right, result);
}

getPosOrder(root, result);

getPosOrder(TreeNode* root, vector<int> & result){
  if(root == nullptr){
    return;
  }
  getPosOrder(root->left, result);
  getPosOrder(root->right, result);
  result.push_back(root->val);
}

getInOrder(root, result);

getInOrder(TreeNode* root, vector<int> & result){
  if(root == nullptr){
    return;
  }
  getInOrder(root->left, result);
  result.push_back(root->val);
  getInOrder(root->right, result);
}
