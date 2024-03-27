class Solution {
public:
bool helper(TreeNode* root, int targetSum, int sum )
    {
        if(root == NULL) return false;
        if(root->left == NULL && root->right == NULL && sum+root->val == targetSum) return true;
        bool left =helper(root->left,targetSum, sum+root->val);
        bool right=helper(root->right,targetSum, sum+root->val);
        return left||right;
    }


bool  hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        return helper(root,  targetSum, 0);
       
        
    }
};
