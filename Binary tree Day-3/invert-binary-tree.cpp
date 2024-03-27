class Solution {
public:
TreeNode* invertTree(TreeNode* root) {
    if(root==NULL)  return root;
    // can put also here swap(root->left, root->right);
    TreeNode*left=invertTree(root->left);
    TreeNode*right=invertTree(root->right);
    swap(root->left, root->right);
    return root;
           
        
        
    }
};
