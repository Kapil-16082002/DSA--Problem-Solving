#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> pre(n, 0);
        int ans = 0;
        vector<int>& xor_arr = arr;
        for (int i = 1; i < n; i++) {
            xor_arr[i] ^= xor_arr[i - 1];
        }
        for (int i = 0; i < n - 1; i++) {
            pre.back() = (xor_arr.back()) ? 0 : 1;
            ans += pre.back();
            for (int j = n - 2; j > i; j--) {
                pre[j] = 0;
                if (xor_arr[j] == 0) {
                    pre[j] = 1;
                }
                pre[j] += pre[j + 1];
                ans += pre[j];
            }
            for (int k = i + 1; k < n; k++) {
                xor_arr[k] ^= xor_arr[i];
            }
        }
        return ans;
    }
};
