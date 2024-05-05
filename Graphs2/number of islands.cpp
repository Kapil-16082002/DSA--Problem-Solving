class Solution {
public:
    void solve(int r, int c, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        int n=grid.size();
        int m=grid[0].size();
        vis[r][c]=1;
        int dp1[4]={1,-1,0,0};
        int dp2[4]={0,0,-1,1};
        for (int i=0;i<4;i++) {
            int nr=dp1[i]+r;
            int nc=dp2[i]+c;
            if (nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]=='1') {
                solve(nr,nc,grid,vis);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>> vis(n, vector<int>(m,0));
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (grid[i][j]=='1' && !vis[i][j]) {
                    solve(i,j,grid,vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};
