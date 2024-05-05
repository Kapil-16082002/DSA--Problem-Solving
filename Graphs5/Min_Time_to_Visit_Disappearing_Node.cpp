class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;      
        vector<int>dist(n,1e9),ans(n,-1);
        pq.push({0,0});
        dist[0]=0;   
        while(!pq.empty()){
            int distance=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(ans[node]!=-1) continue;
            ans[node]=distance;           
            for(auto it:adj[node]){
                int currentdist=it.second;
                int newNode=it.first;              
                if(disappear[newNode]>distance+currentdist && ans[newNode]==-1){
                        pq.push({distance+currentdist,newNode});
                }
            }
        }
        ans[0]=0;        
        return ans;
    }
};
