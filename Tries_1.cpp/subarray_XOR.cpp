#include <iostream>
using namespace std;
 
struct node{
    node *child[2];
    long long num;
    int cnt;
    node(){
        child[0]=NULL;
        child[1]=NULL;
        num=-1;
        cnt=0;
    }
};
 
struct trie{
    node *root;
    trie(){
        root=new node;
    }
    void insert(long long n){
        node *curr=root;
        for(int i=31;i>=0;i--){
            curr->cnt++;
            long long x=(n&(1<<i))?1:0;
            if(curr->child[x]==NULL){
                curr->child[x]=new node;
            }
            curr=curr->child[x];
        }
        curr->cnt++;
        curr->num=n;
    }

    int func(node *curr, long long x, long long k, long long i){
        if(curr==NULL) return 0;
        if(i<0){
            if(curr) return curr->cnt;
            return 0;
        }
        long long ans=0;
        long long xbit =(x&(1<<i))?1:0;
        long long kbit =(k&(1<<i))?1:0;
        if(xbit==0 && kbit==0){
            ans+=func(curr->child[0],x,k,i-1);
        }else if(xbit==0 && kbit==1){
            if(curr->child[0]) ans+=curr->child[0]->cnt;
            ans+=func(curr->child[1],x,k,i-1);
        }else if(xbit==1 && kbit==0){
            ans+=func(curr->child[1],x,k,i-1);
        }else{
            if(curr->child[1]) ans+=curr->child[1]->cnt;
            ans+=func(curr->child[0],x,k,i-1);
        }
        return ans;
    }

    long long query(long long x, long long k){
        if(k==0) return 0;
        return func(root,x,k-1,31);
    }
};
 
void solve(){
    long long n,k;
    cin>>n>>k;
    long long arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    trie t;
    t.insert(0);
    long long pre=0;
    long long ans=0;
    for(int i=0;i<n;i++){
        pre=pre^arr[i];
        long long temp=t.query(pre, k);
        ans+=temp;
        t.insert(pre);
    }
    cout<<ans<<endl;
}
 
int main(){
    int t;
	cin>>t;
	while(t--)
        solve();
}
