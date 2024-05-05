#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution{
	public:
	void dfs(int node,vector<bool> &visited,vector<vector<int>>& adj,stack<int> &st){
        visited[node]=true;
        for(auto ne:adj[node]){
            if(visited[ne]==false){
                dfs(ne,visited,adj,st);
            }
        }
        st.push(node);
    }
    
    void revDFS(int node,vector<bool> &visited,vector<vector<int>> &transpose){
        visited[node]=true;
        for(auto ne:transpose[node]){
            if(!visited[ne])
                revDFS(ne,visited,transpose);
        }
    }
    
    int kosaraju(int V, vector<vector<int>>& adj){
        vector<bool> visited(V,false);
        stack<int> st;
        for(int i=0;i<V;i++){
           if(!visited[i]){
               dfs(i,visited,adj,st);
           }
        }
        vector<vector<int>> transpose(V);
        for(int i=0;i<V;i++){
            visited[i]=false;
            for(auto ne:adj[i]){
                transpose[ne].push_back(i);
            }
        }
        int c=0;
        while(!st.empty()){
            int top=st.top();
            st.pop();
           if(visited[top]==false){
                    c++;
                    revDFS(top,visited,transpose);
                }
        }
        
        return c;
    }
};
