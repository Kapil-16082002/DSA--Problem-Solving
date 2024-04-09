#include<bits/stdc++.h>
#include<vector>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
    public:
    void inorder(Node* root, vector<int> &ino){
        if(root!=NULL){
            inorder(root->left,ino);
            ino.push_back(root->data);
            inorder(root->right,ino);
        }
    }
    
    vector<int> msort(vector<int> in1, vector<int> in2, vector<int> &res){
        int i=0,j=0;
        while(i<in1.size()&&j<in2.size()){
            if(in1[i]<in2[j]){
                res.push_back(in1[i]);
                i++;
            }
            else{
                res.push_back(in2[j]);
                j++;
            }
        }
        while(i<in1.size()){
            res.push_back(in1[i]);
            i++;
        }
        while(j<in2.size()){
            res.push_back(in2[j]);
            j++;
        }
        return res;
    }
    
    vector<int> merge(Node *root1, Node *root2){
       vector<int>in1;
         vector<int>in2;
         vector<int>ans;
         inorder(root1,in1);
         inorder(root2,in2);
         msort(in1,in2,ans);
         return ans;
    }
};
