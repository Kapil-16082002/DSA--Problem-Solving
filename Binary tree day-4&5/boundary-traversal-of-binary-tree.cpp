// revised it again
class Solution{
public:
bool leafornot(node * root){
   return !root -> left && !root -> right;
}
void leftpart(node * root, vector < int > & res) {
  node * cur = root -> left;
  while (cur) {
    if (!isLeaf(cur)) res.push_back(cur -> data);
    if (cur -> left) cur = cur -> left;
    else cur = cur -> right;
  }
}
void rightpart(node * root, vector < int > & res) {
  node * cur = root -> right;
  vector < int > tmp;
  while (cur) {
    if (!isLeaf(cur)) tmp.push_back(cur -> data);
    if (cur -> right) cur = cur -> right;
    else cur = cur -> left;
  }
  for (int i = tmp.size() - 1; i >= 0; --i) {
    res.push_back(tmp[i]);
  }
}

void leafpart(node * root, vector < int > & res) {
  if (isLeaf(root)) {
    res.push_back(root -> data);
    return ;
  }
  if (root -> left) leafpart(root -> left, res);
  if (root -> right) leafpart(root -> right, res);
}

vector < int > printBoundary(node * root) {
  vector < int > res;
  if (!root) return res;
  if (!isLeaf(root)) res.push_back(root -> data);
  leftpart(root, res);
  leafpart(root, res);
  rightpart(root, res);
  return res;
}
};
