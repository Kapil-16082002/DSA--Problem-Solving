#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        while(!pq.empty()){
            int diff=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            if(x==n-1 && y==m-1) return diff;
            for(int i=0;i<4;i++){
                int nr=x+dr[i];
                int nc=y+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int newEf=max(abs(heights[x][y]-heights[nr][nc]),diff);
                    if(newEf<dist[nr][nc]){
                        dist[nr][nc]=newEf;
                        pq.push({newEf,{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};
