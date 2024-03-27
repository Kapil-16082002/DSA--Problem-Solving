
class Solution {
public:
    void solve(TreeNode *root, int level, vector<int> &res)
    {
        if(root==NULL) return ;
        if(res.size()==level) res.push_back(root->val);
        solve(root->left, level+1, res);
        solve(root->right, level+1, res);
    }
    
    vector<int> leftSideView(TreeNode *root) {
        vector<int> res;
        solve(root, 0, res);
        return res;
    }
};
