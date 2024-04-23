#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Node{
public:
    Node *children[2];
    Node(){
        children[0]=NULL;
        children[1]=NULL;
    }
};

class Trie{
public:
    Node *root;
    Trie(){
        root=new Node();
    }
    void insert(int n){
        Node *temp=root;
        for (int i=31;i>=0;i--){
            int ind=((n>>i)&(1));
            if (temp->children[ind]!=NULL){
                temp=temp->children[ind];
            }
            else{
                Node *child=new Node();
                temp->children[ind]=child;
                 temp=temp->children[ind];
            }
        }
    }

    int maxXor(int n){
        Node *temp=root;
        int ans=0;
        for (int i=31;i>=0;i--){
            int ind=((n>>i)&(1));
            if (temp->children[1-ind]!=NULL){
                temp=temp->children[1-ind];
                ans+=(1<<i);
            }
            else{
                temp=temp->children[ind];
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();
        if (n==1)
            return 0;
        Trie *Node = new Trie();
        int ans=0;
        for (int i=0;i<n;i++){
            Node->insert(nums[i]);
        }
        for (int i=0;i<n;i++){
            ans =max(ans,Node->maxXor(nums[i]));
        }
        return ans;       
    }
};
