#include<bits/stdc++.h>
#include<vector>
using namespace std;

vector<pair<int, int>> moves={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
int a,b,e,f;

bool safe(int i, int j){
    return i>0 && j>0 && i<=a && j<=b;
}

int check(int s1, int s2){
    queue<pair<int,int>> q;
    q.push({s1,s2});
    vector<vector<bool>> visited(a+1,vector<bool> (b+1,false));
    visited[s1][s2]=true;
    int c=0;
    while(!q.empty()){
        int size=q.size();
        c++;
        for(int k=0;k<size;k++){
            auto temp=q.front();
            q.pop();
            if(temp.first==e && temp.second==f){
                return c-1;
            }
            for(auto d:moves){
                int x=temp.first+d.first,y=temp.second+d.second;
                if(safe(x,y) && visited[x][y]==false){
                    q.push({x,y});
                    visited[x][y]=true;
                }
            }
        }
    }
    return -1;
}

int knight(int A, int B, int C, int D, int E, int F) {
    a=A; 
    b=B; 
    e=E; 
    f=F;
    return check(C,D);
}
