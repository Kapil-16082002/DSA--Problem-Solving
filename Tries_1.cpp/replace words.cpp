#include <bits/stdc++.h>
using namespace std;

//lc648

class Trie {
private:
    Trie* next[26] = {};
    bool isEnd = false;

public:
    Trie() {}
    void insert(string word) {
        Trie* current = this;
        for (int i = 0; i < word.size(); i++) {
            if (current->next[word[i] - 'a'] == nullptr)
                current->next[word[i] - 'a'] = new Trie();
            current = current->next[word[i] - 'a'];
        }
        current->isEnd = true;
    }

    string search(string word) {
        string ans = "";
        Trie* current = this;
        for (int i = 0; i < word.size(); i++) {
            if (current->isEnd)
                return ans;
            if (current->next[word[i] - 'a'] == nullptr)
                return word;
            ans.push_back(word[i]);
            current = current->next[word[i] - 'a'];
        }
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        Trie* trie = new Trie;
        for (string i : dict)
            trie->insert(i);
        string ans = "";
        stringstream s(sentence);
        string tmp;
        int i = 0;
        while (s >> tmp) {
            if (i != 0)
                ans.append(" ");
            string t = trie->search(tmp);
            i++;
            ans.append(t);
        }
        // ans.trim();
        return ans;
    }
};
