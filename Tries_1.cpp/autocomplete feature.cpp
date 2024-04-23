#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    struct Node* children[26];
    bool isEnd;
};

struct Node* getNode(void){
    struct Node* pNode=new Node;
    pNode->isEnd=false;
    for (int i=0;i<26;i++)
        pNode->children[i]=NULL;
    return pNode;
}

void insert(struct Node* root, const string key){
    struct Node* temp=root;
    for (int lev=0;lev<key.length();lev++) {
        int ind=key[lev]-'a';
        if (!temp->children[ind])
            temp->children[ind]=getNode();
        temp=temp->children[ind];
    }
    temp->isEnd=true;
}

bool isLast(struct Node* root){
    for (int i=0;i<26;i++)
        if (root->children[i])
            return 0;
    return 1;
}
 
void suggest(struct Node* root, string currPrefix){
    if (root->isEnd)
        cout<<currPrefix<<endl;
    for (int i=0;i<26;i++)
        if (root->children[i]) {
            char child='a'+i;
            suggest(root->children[i],currPrefix+child);
        }
}
 
int print(Node* root, const string query){
    struct Node* p=root;
    for (char c:query) {
        int ind=c-'a';
        if (!p->children[ind])
            return 0;
        p=p->children[ind];
    }
    if (isLast(p)) {
        cout<<query<<endl;
        return -1;
    }
    suggest(p,query);
    return 1;
}
 
int main(){
    struct Node* root=getNode();
    insert(root,"arms");
    insert(root,"arc");
    insert(root,"army");
    insert(root,"cat");
    insert(root,"a");
    insert(root,"arm");
    insert(root,"he");
    insert(root,"hell");
    int comp=print(root,"ar");
    if (comp==-1)
        cout<<"No more strings found with this prefix\n";
    else if (comp==0)
        cout<<"No string found with this prefix\n";
    return 0;
}
