#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
    bool dfs(vector<int>adj[], int node, vector<int> &vis){
        for(auto it:adj[node]){
            if(vis[it]==-1){
                vis[it]=!vis[node];
                if(!dfs(adj,it,vis)) return false;
            }
            else if(vis[it]==vis[node]) return false; 
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                adj[i].push_back(it);
            }
        }
        vector<int>vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                vis[i]=0;
                bool ans=dfs(adj,i,vis);
                if(!ans) return false;
            }
        }
        return true;
    }
};
