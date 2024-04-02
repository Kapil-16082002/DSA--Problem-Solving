class Solution {
public:
void Inorder(TreeNode* root, int low, int high,int &sum){
        if(root == NULL)
        return;
      Inorder(root->left,low,high,sum);
      if(root->val>=low && root->val<=high)  sum=sum+root->val;
      Inorder(root->right,low,high,sum);
   }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        Inorder(root,low,high,sum);
        return sum;

        
    }
};
