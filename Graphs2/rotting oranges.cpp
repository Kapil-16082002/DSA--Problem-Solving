class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int tot=0,cnt=0;
        queue<pair<int, int>> q;
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (grid[i][j]==2)
                    q.push({i,j});
                if (grid[i][j]!=0)
                    tot++;
            }
        }
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        int ans=0;
        while (!q.empty()) {
            int k=q.size();
            cnt+=k;
            while (k--) {
                int y=q.front().second,x=q.front().first;
                q.pop();
                for (int i=0;i<4;i++) {
                    int nx=x+dx[i],ny=y+dy[i];
                    if (nx<0 || ny<0 || nx>=n || ny>=m || grid[nx][ny]!=1)
                        continue;
                    grid[nx][ny]=2;
                    q.push({nx,ny});
                }
            }
            if (!q.empty())
                ans++;
        }
        if (tot==cnt)
            return ans;
        return -1;
    }
};
