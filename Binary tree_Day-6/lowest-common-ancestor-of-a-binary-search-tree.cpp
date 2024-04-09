class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)  return nullptr;
        int curr = root->val;
        if (p->val > curr && curr < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        
        if ( p->val < curr && curr > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};
