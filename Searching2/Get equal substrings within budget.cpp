#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

bool func(vector<int>&v, int c,int m){
        int l=0;
        int r=m;
        int f=false;
        int s;
        while(r<v.size()){
            s=v[r]-v[l];
            if(c>=s){
                f=true;
                break;
            }
            l++;
            r++;
        }
        return f;
    }

int equalSubstring(string s, string t, int maxCost) {
        int i,n=s.size();
        vector<int>prev(n+1,0);
        for(i=1;i<=n;i++){
            prev[i]=prev[i-1]+abs((s[i-1]-'a')-(t[i-1]-'a'));
        }
        int low=0;
        int high=s.size()+1;
        int res=0;
        while(low<=high){
            int m=(low+high)/2;
            if(func(prev,maxCost,m)==true){
                low=m+1;
                res=m;
            }
            else{
                high=m-1;
            }
        }
        return res;
    }
