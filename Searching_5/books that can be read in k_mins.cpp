#include <iostream>
#include <vector>
using namespace std;

int count(vector<long long>& pb, long long k) {
    int low=0;
    int high=pb.size()-1;
    int res=0;
    while (low<=high){
        int mid = (low+high)/2;
        if(pb[mid]<=k) {
            res=mid;
            low=mid+1;
        } 
        else {
            high=mid-1;
        }
    }
    return res;
}

int main() {
    int n, m;
    long long k;
    cin>>n>>m>>k;
    vector<long long int>a(n);
    vector<long long int>b(m);
    vector<long long int>pa(n+1,0);
    vector<long long int>pb(m+1,0);
    for(int i=0;i<n;i++){
            cin>>a[i];
	  }
    for(int i=0;i<m;i++){
            cin>>b[i];
  	}
    for(int i=1;i<=n;i++) {
        pa[i]+=pa[i-1]+a[i-1];
    }
    for(int i=1;i<=m;i++) {
        cin>>pb[i];
        pb[i]+=pb[i-1]+b[i-1];
    }
    int ma=0;
    for(int i=0;i<=n;i++) {
        long long cost=k-pa[i];
        if(cost<0){
            break;
        }
        int b=count(pb,cost);
        ma=max(ma,i+b);
    }
    cout<<ma<<endl;
}
