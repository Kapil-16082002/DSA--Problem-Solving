#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<bool> &vis, vector<vector<int>> &adj, vector<bool> &track, vector<vector<int>> &colorMax, string &colors, int &ans, bool &isCycle) {
        vis[node]=true;      
        for(int k:adj[node]) {
            if (!vis[k]) {
                dfs(k,vis,adj,track,colorMax,colors,ans,isCycle);
            } else if (!track[k]) isCycle=true;
            for(int it=0;it<26;it++) {
                colorMax[node][it]=max(colorMax[node][it],colorMax[k][it]);
            }
        }       
        colorMax[node][colors[node]-'a']+=1;
        ans=max(ans,colorMax[node][colors[node]-'a']);
        track[node]=true;
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.length();
        vector<bool> track(n,false);
        vector<bool> vis(n,false);
        bool isCycle=false;
        vector<vector<int>> adj(n);
        vector<vector<int>> colorMax(n,vector<int> (26,0));
        int ans=1;
        for(int i=0;i<edges.size();i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        for(int i=0;i<n;i++) {
            if (!vis[i]) {
                dfs(i,vis,adj,track,colorMax,colors,ans,isCycle);
            }
        }
        if (isCycle) return -1;
        return ans;
    }
};
