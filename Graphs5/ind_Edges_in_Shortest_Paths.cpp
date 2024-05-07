class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<array<int,2>>> adj(n,vector<array<int,2>>(0)); 
        map<array<int,2>,int> mp;  
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
            mp[{edges[i][0],edges[i][1]}]=i;
            mp[{edges[i][1],edges[i][0]}]=i;
        }
        vector<vector<int>> par(n,vector<int>(0)); 
        vector<int> dist(n,1e9);
        dist[0]=0;
        priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>>pt;
        pt.push({0,0});
        while(!pt.empty()){
            auto it=pt.top();
            pt.pop();
            for(auto jt:adj[it[1]]){
                if(dist[jt[0]]>it[0]+jt[1]){
                    dist[jt[0]]=it[0]+jt[1];
                    pt.push({dist[jt[0]],jt[0]});
                    par[jt[0]].clear();               
                    par[jt[0]].push_back(it[1]);
                }
                else if(dist[jt[0]]==it[0]+jt[1]){
                    par[jt[0]].push_back(it[1]);  
                }
            }
        }
        queue<int> qu;  
        qu.push(n-1);
        vector<bool> ans(edges.size(),0);
        while(!qu.empty()){
            int op=qu.front();
            qu.pop();
            for(auto it:par[op]){
            ans[mp[{it,op}]]=true;   
                qu.push(it);
            }
        }
        return ans
