class Solution 
{
    public:
	vector<vector<int>>nearest(vector<vector<int>>grid){
	    int n=grid.size();
	    int m=grid[0].size();
	    queue<pair<int,int>> q;
	    vector<vector<int>> ans(n,vector<int>(m,-1));
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1) {
	                q.push({i,j});
	                ans[i][j]=0;
	            }
	        }
	    }
	    int dx[]={0,0,1,-1};
	    int dy[]={1,-1,0,0};
	    while(!q.empty()){
	        int size=q.size();
	        for(int i=0;i<size;i++) {
	            int a=q.front().first;
	            int b=q.front().second;
	            q.pop();
	            for(int k=0;k<4;k++){
	                int na=a+dx[k];
	                int nb=b+dy[k];
	                if(na<0 || nb<0 || na>=n || nb>=m || ans[na][nb]!=-1) 
	                    continue;
	                q.push({na,nb});
	                ans[na][nb]=ans[a][b]+1;
	            }
	        }
	    }
	    return ans;
	}
};
