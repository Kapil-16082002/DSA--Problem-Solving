#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int ans=-1;
void solve(Node* root, int x) {
    if (root == NULL) return;
    if (root->data==x)
        ans=x;
    else if (root->data<x) 
        solve(root->right,x);
    else{
        ans=root->data;
        solve(root->left,x);
    }
}

int findingCeil(Node* root, int input) {
   solve(root,input);
    return ans;
}
