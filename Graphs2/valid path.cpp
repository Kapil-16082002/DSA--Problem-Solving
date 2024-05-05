#include<bits/stdc++.h>
#include<vector>
using namespace std;

int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,1,-1,1,-1,-1,1};

bool isValid(int x, int y, int n, int m){
    return x>=0 && y>=0 && x<=n && y<=m;
}

string solve(int a, int b, int n, int r, vector<int> &A, vector<int> &B) {
    vector<vector<int>> vis(a+2,vector<int>(b+2,0));
    vector<vector<int>> d(a+2,vector<int>(b+2,1e9));
    for(int i=0;i<=a;++i){
        for(int j=0;j<=b;++j){
            for(int k=0;k<n;++k){
                if((i-A[k])*(i-A[k])+(j-B[k])*(j-B[k])<=r*r){
                    vis[i][j]=1;
                }
            }
        }
    }   
    queue<pair<int,int>> q;
    q.push({0,0});
    vis[0][0]=1;   
    while(!q.empty()){
        auto [x,y]=q.front();
        q.pop();
        if(x==a && y==b) return "YES";
        for(int i=0;i<8;++i){
            int X=x+dx[i],Y=y+dy[i];
            if(isValid(X,Y,a,b) && !vis[X][Y]){
                q.push({X,Y});
                vis[X][Y]=1;
            }
        }
    }
    return "NO";
}
