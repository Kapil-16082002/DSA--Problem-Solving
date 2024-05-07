#include<bits/stdc++.h>
#include<vector>
using namespace std;

class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    int comp;

    DSU(int n) {
        parent.resize(n+1);
        for(int i=1;i<=n;i++) {
            parent[i]=i;
        }
        rank.resize(n+1);
        comp=n;
    }

    int findParent(int node) {
        if(node==parent[node]) {
            return node;
        }
        return findParent(parent[node]);
    }

    void unionByRank(int node1, int node2) {
        int p1=findParent(node1);
        int p2=findParent(node2);
        if(p1==p2) {
            return;
        }
        if(rank[p1]>rank[p2]) {
            parent[p2]=p1;
        } else if(rank[p2]>rank[p1]) {
            parent[p1]=p2;
        } else {
            parent[p1]=p2;
            rank[p2]++;
        }
        comp--;
    }

    bool isSingle() {
        return comp==1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU Alice(n);
        DSU Bob(n);
        auto lambda=[](vector<int> &a, vector<int> &b) {
            return a[0]>b[0]; 
        };
        sort(edges.begin(),edges.end(),lambda);
        int edge=0;
        for(auto &ed:edges) {
            int type=ed[0];
            int u=ed[1];
            int v=ed[2];
            if(type==3) {
                bool edgeAdded=false;
                if(Alice.findParent(u)!=Alice.findParent(v)) {
                    Alice.unionByRank(u,v);
                    edgeAdded=true;
                }
                if(Bob.findParent(u)!=Bob.findParent(v)) {
                    Bob.unionByRank(u,v);
                    edgeAdded=true;
                } 
                if(edgeAdded==true) {
                    edge++;
                }  
            } else if (type==2) {
                if(Bob.findParent(u)!=Bob.findParent(v)) {
                    Bob.unionByRank(u,v);
                    edge++;
                }                
            } else {
                if(Alice.findParent(u)!=Alice.findParent(v)) {
                    Alice.unionByRank(u,v);
                    edge++;
                }
            }
        }
        if(Alice.isSingle()==true and Bob.isSingle()==true) {
            return edges.size()-edge;
        }
        return -1;
    }
};
