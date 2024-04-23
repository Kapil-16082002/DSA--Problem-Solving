#include<bits/stdc++.h>
#include<vector>
using namespace std;

struct Node{
    Node* children[26];
    int countEnd=0;
    int countPrefix=0;
};

class Trie{
private:
	Node *root;
public:
	Trie(){
		root=new Node();
	}

	void insert(string &s) {
		int n=s.size();
		Node* node=root; 
		for (int i=0;i<n;i++) {
			if (node->children[s[i]-'a']==NULL) {
				node->children[s[i]-'a']=new Node();
			}
			node=node->children[s[i]-'a'];
			node->countPrefix++;
		}
		node->countEnd++;
	}

	int StrStartWith(string &s) {
		int n=s.size();
		Node* node=root;
		int c=0;
		for (int i=0;i<n;i++) {
			if (node->children[s[i]-'a']==NULL) {
				return 0;
			}
			node=node->children[s[i]-'a'];
			c+=(node->countPrefix);
		}
		return c;
	}
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) { 
        Trie tr;
		for (auto x:words) {
			tr.insert(x);
		}
		vector<int>ans(words.size(),0);
		for (int i=0;i<words.size();i++) {
			ans[i]=tr.StrStartWith(words[i]);
		}
		return ans;
    }
};
