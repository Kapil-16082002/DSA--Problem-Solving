class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if(root==NULL)  return v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int count=q.size();
            for(int i=0;i<count;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(i==count-1) // means we are at right side
                    v.push_back(curr->val);
                //if(i==0) cout<<curr->val<<" "; left view
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
            }
        }
        return v;
        
    }
};
