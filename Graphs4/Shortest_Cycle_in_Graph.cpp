#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> gr(1002);
        for(int i=0;i<edges.size();i++){
            gr[edges[i][0]].push_back(edges[i][1]);
	        gr[edges[i][1]].push_back(edges[i][0]);
        }
        int ans=INT_MAX;
        for (int i=0;i<n;i++) {
            vector<int> dist(n,(int)(100000));
            vector<int> par(n,-1);
            dist[i]=0;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int x=q.front();
                q.pop();
                for (int child:gr[x]) {
                    if (dist[child]==(int)(100000)) {
                        dist[child]=1+dist[x];
                        par[child]=x;
                        q.push(child);
                    }
                    else if (par[x]!=child and par[child]!=x)
                        ans=min(ans,dist[x]+dist[child]+1);
                }
            }
        }
        if (ans!=INT_MAX)
            return ans;
        return -1;       
    }
};
