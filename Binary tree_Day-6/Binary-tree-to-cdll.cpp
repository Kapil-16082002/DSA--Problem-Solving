#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;   
    Node(int x){
        data=x;
        left=right=NULL;
    }
};

class Solution
{
  public:
    void inord(Node* root, queue<Node*> &q){
        if(root){
            inord(root->left,q);
            q.push(root);
            inord(root->right,q);
        }
    };
    
    Node* bTreeToCList(Node *root){
        queue<Node*> q;
        inord(root,q);
        Node *head=q.front();
        Node *prev=NULL;
        Node *tail=NULL;
        while(!q.empty()){
            struct Node*j=q.front();
            q.pop();
            j->left=prev;
            if(!q.empty()){
                j->right=q.front();
            }
            else{
                tail=j;
                j->right=head;
            }
            prev=j;
        }
        head->left=tail;
        return head;
    }
};
