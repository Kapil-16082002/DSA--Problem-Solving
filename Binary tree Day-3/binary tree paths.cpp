class Solution {
public:
 
    vector<string> binaryTreePaths(TreeNode* root) {
        queue<pair<TreeNode* ,string>> q;
        vector<string> ans;
        q.push({root,""});
        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto f=q.front();
                q.pop();
                if(f.second!="") f.second+= "->"+to_string(f.first->val);
                else f.second+=to_string(f.first->val);
                if(f.first->left){
                    q.push({f.first->left,f.second});
                }
                if(f.first->right){
                     q.push({f.first->right,f.second});
                }
                if(!f.first->left && !f.first->right){
                     ans.push_back(f.second);
                }
            }
        }
        return ans;
       
        
    }
};
