void Inorder(TreeNode* root, vector<int>&vec){
        if(root == NULL)
        return;
      Inorder(root->left,vec);
      vec.push_back(root->val);
      Inorder(root->right,vec);
   }
    bool findTarget(TreeNode* root, int k){
        vector<int>vec;
        Inorder(root, vec);
        int mini=INT_MAX;
        int n=vec.size();
        if(n==1) return false;
        int low=0,high=n-1;
        while(low<high){

            if(vec[low]+vec[high]==k) return true;
            else if(vec[low]+vec[high]>k) high--;
            else low++;
        }
        return false;
    }
};
