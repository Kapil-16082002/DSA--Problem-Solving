class Solution {
public:
    void dfs(unordered_map<int,bool>& vis,int src,vector<vector<int>>& isConnected){
        vis[src]=true;
        int size=isConnected[src].size();
        for(int col=0;col<size;col++){
            if(src!=col && isConnected[src][col]==1 && !vis[col]){
                dfs(vis,col,isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,bool> vis;
        int n=isConnected.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(vis,i,isConnected);
                cnt++;
            }
        }
        return cnt;
    }
};
