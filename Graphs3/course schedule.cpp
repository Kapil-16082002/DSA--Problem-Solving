class Solution {
public:
    bool iscycle(vector<int> adj[],vector<int> &vis,int id){
        if(vis[id]==1)
            return true;
        if(vis[id]==0){
            vis[id]=1;
            for(auto edge:adj[id]){
                if(iscycle(adj,vis,edge))
                    return true;
            }
        }
        vis[id]=2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto edge : prerequisites)
            adj[edge[1]].push_back(edge[0]);
        vector<int> vis(numCourses,0);
        
        for(int i=0;i<numCourses;i++){
            if(iscycle(adj,vis,i))
                return false;
        }
        return true;
    }
};
