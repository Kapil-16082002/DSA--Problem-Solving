class Solution {
public:
	bool isValidBSTHelper(TreeNode* root, long min, long max) {
		if(root == NULL){
			return true;
		}   
		if(root->val > min && root->val < max) {
			return isValidBSTHelper(root->left, min, root->val) && isValidBSTHelper(root->right, root->val, max);
		}    
		return false;
	}
	bool isValidBST(TreeNode* root) {
		return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
	} 
};
