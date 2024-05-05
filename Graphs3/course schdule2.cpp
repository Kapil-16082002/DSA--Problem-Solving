#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> G(numCourses);
        vector<int> ans, indeg(numCourses);
        for(auto& pre:prerequisites)
            G[pre[1]].push_back(pre[0]),
            indeg[pre[0]]++;
        function<void(int)> dfs=[&](int cur) {
            ans.push_back(cur);                     
            indeg[cur]=-1;                     
            for(auto nextCourse:G[cur])          
                if(--indeg[nextCourse]==0)     
                    dfs(nextCourse);                
        };
        for(int i=0;i<numCourses;i++)
            if(indeg[i]==0)                    
                dfs(i);
        if(ans.size()==numCourses) return ans;
        return {};
    }
};
