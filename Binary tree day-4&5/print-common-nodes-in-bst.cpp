include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data=val;
        left=right=NULL;
    }
};

class Solution
{
    public:
    void func(Node* root,vector<int>& v){
        if(!root)return;
        func(root->left,v);
        v.push_back(root->data);
        func(root->right,v);
    }
    
    vector <int> findCommon(Node *root1, Node *root2){
        unordered_map<int,int> m;
        vector<int> v1,v2;
        func(root1,v1);
        func(root2,v2);
        vector<int> ans;
        if(v1.size()<v2.size())swap(v1,v2);
        int i=0,j=0;
        while(i<v1.size() && j<v2.size()){
            if(v1[i]==v2[j]){
                ans.push_back(v1[i]);
                i++,j++;
            }
            else if(v2[j] > v1[i]){
                while(v2[j]>v1[i] && i<v1.size()){
                    i++;
                }
            }
            else{
                j++;
            }
        }
        return ans;
    }
};
