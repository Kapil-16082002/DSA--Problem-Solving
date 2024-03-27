// same as step by step directions from a binary tree node to another
class Solution {
    int start;
    int end;

    string startPath;
    string destPath;
    TreeNode *findLCA(TreeNode *root) {
        if (!root) return NULL;
        if (root->val == start || root->val == end) return root;
        TreeNode *left = findLCA(root->left);
        TreeNode *right = findLCA(root->right);
        if (left != NULL && right != NULL)
            return root;
        else if (left)
            return left;
        return right;
    }

    void findPath(TreeNode *root, string &path) {
        if (!root) return;
        if (root->val == start) {
            for (int i = 0; i < path.length(); i++) {
                startPath += "U";
            }
        } 
        else if (root->val == end) {
            destPath = path;
        }
        path.push_back('L');
        findPath(root->left, path);
        path.pop_back();
        path.push_back('R');
        findPath(root->right, path);
        path.pop_back();
    }

public:
    int getDirections(TreeNode *root, int startValue, int destValue) {
        start = startValue;
        end = destValue;
        TreeNode *lca = findLCA(root);
        string path = "";
        findPath(lca, path);
       // return (startPath + destPath);
      path.size();
    }
};
