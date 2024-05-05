#include<bits/stdc++.h>
#include<vector>
using namespace std;

int maxi;
vector<bool> vis;
vector<vector<int>> adj;

int dfs(int v){
    int currmax=0;
    vis[v]=true;
    for(auto u: adj[v]){
        if(!vis[u]){
            int val=dfs(u);
            maxi=max(maxi,currmax+val+1);
            if(val>currmax){
                currmax=val;
            }
        }
    }
    maxi=max(maxi,currmax+1);
    return currmax+1;
}


int solve(vector<int> &A) {
    maxi=0;
    adj.assign(A.size(),vector<int>());
    vis.assign(A.size(),false);
    int root=-1;
    for(int i=0;i<A.size();i++){
        if(A[i]==-1){
            root=i;
            continue;
        }
        adj[A[i]].push_back(i);
        adj[i].push_back(A[i]);
    }
    dfs(root);
    return maxi-1;
}
