class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> check (n,false);
        for(int i=0;i<edges.size();i++){
            check[edges[i][1]]=true;
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            if(check[i]==false){
                res.push_back(i);
            }
        }
        return res;        
    }
};
