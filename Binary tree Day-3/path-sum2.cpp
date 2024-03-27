class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == NULL)     return {};
        queue<pair<TreeNode*, pair<int, vector<int>>>> q;
        q.push({root, {root->val, {root->val}}});//node,sum,vector<root->values
        vector<vector<int>> result;
        
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            
            if(temp.first->left==NULL && temp.first->right==NULL){
                if(temp.second.first == sum){
                    result.push_back(temp.second.second);
                }
            }            
            if(temp.first->left){
                vector<int> curr{temp.second.second.begin(), temp.second.second.end()};
                curr.push_back(temp.first->left->val);
               q.push({temp.first->left, {temp.second.first + temp.first->left->val, curr}});
            }
            if(temp.first->right){
                vector<int> curr{temp.second.second.begin(), temp.second.second.end()};
                curr.push_back(temp.first->right->val);
                q.push({temp.first->right, {temp.second.first + temp.first->right->val, curr}});
            }
        }
        
        return result;
    }
};
