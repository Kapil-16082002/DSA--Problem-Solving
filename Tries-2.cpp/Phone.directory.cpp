#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        vector<vector<string>> ans;
        vector<string> temp;
        string check = "";

        for (int i = 0; i < s.length(); i++)
        {
            unordered_map<string, int> mp;
            check = check + (s[i]);
            for (int j = 0; j < n; j++)
            {
                if (contact[j].find(check) == 0 && mp.find(contact[j]) == mp.end())
                {
                    temp.push_back(contact[j]);
                    mp[contact[j]] = i;
                }
            }
            if (temp.size() == 0)
            {
                temp.push_back("0");
            }
            sort(temp.begin(), temp.end());
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};
