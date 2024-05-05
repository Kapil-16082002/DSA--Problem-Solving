#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> l;

    void addEdge(int x, int y, bool dir=true) {
        l[x].push_back(y);
        if (!dir) l[y].push_back(x); 
    }

    bool helper(int node, vector<bool> &vis, vector<bool> &st) {
        vis[node]=true;
        st[node]=true;
        for (int nbr:l[node]) {
            if (st[nbr]) {
                return true;  
            } else if (!vis[nbr]) {
                if (helper(nbr,vis,st)) {
                    return true;  
                }
            }
        }
        st[node]=false;
        return false;
    }
     
    bool isCyclic(int V, vector<int> adj[]) {
        l.resize(V);
        for (int i=0;i<V;i++) {
            for (int j:adj[i]) {
                addEdge(i,j);
            }
        }
        vector<bool> vis(V,false);
        vector<bool> st(V,false);
        for (int i=0;i<V;i++) {
            if (!vis[i] && helper(i,vis,st)) {
                return true;
            }
        }
        return false;
    }
};
