class Solution {

TreeNode* insertIntoBST(TreeNode* root, int data) {     
    if(root == NULL) {

        root = new TreeNode(data);

        return root;
    }
    if(data > root -> val) 
        root -> right = insertIntoBST(root -> right, data);
    
    else
        root -> left = insertIntoBST(root -> left, data);
    
    return root;
}

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int n = preorder.size();           
        
        TreeNode* root = NULL;

        for(int i=0; i<n; i++)
            root = insertIntoBST(root, preorder[i]);
        
        return root;
    }
};
