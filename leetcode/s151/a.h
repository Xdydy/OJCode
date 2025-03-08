#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Solution {
public:
    vector<int> transformArray(vector<int> &nums) {
        vector<int> ans;
        for (auto x: nums) {
            if (x&1) {
                ans.push_back(1);
            } else {
                ans.push_back(0);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};