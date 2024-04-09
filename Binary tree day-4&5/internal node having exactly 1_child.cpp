#include <bits/stdc++.h>
using namespace std;
 
int check(int preo[], int n){
    int mi,ma;
    if(preo[n-1]>=preo[n-2]){
        ma=preo[n-2];
        mi=preo[n-1];
    }
    else{
        ma=preo[n-1];
        mi=preo[n-2];
    }
    for(int i=n-3;i>=0;i--){
        if(preo[i]<mi)
            mi=preo[i];
        else if(preo[i]>ma)
            ma=preo[i];
        else
            return false;
    }
    return true;
}
 
int main(){
    int pre[]={10,2,5,9};
    int n=sizeof(pre)/sizeof(pre[0]);   
    if (check(pre,n))
        cout<<"Yes";
    else
        cout<<"No";        
    return 0;
}
