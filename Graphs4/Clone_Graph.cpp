#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
    map<Node*, Node*>m;
    Node* dfs(Node* u) {
        Node* u1=new Node(u->val);
        m[u]=u1;
        for(Node* v:u->neighbors) {
            if(m.find(v)==m.end()) {
                u1->neighbors.push_back(dfs(v));
            } else {
                u1->neighbors.push_back(m[v]);
            }
        }
        return u1;
    }

public:
    Node* cloneGraph(Node* node) {
        return node?dfs(node):NULL;        
    }
};
