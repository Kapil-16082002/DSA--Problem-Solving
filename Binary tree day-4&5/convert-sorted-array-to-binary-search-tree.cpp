class Solution {
public:
    TreeNode* convertBST(int left,int right,vector<int>&arr){
        if(left>right) return nullptr;
        int mid = left+((right-left)/2);
        TreeNode * root = new TreeNode(arr[mid]);
        root->left = convertBST(left,mid-1,arr);
        root->right = convertBST(mid+1,right,arr);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return convertBST(0,nums.size()-1,nums);
    }
};
