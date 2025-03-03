#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        map<string,vector<string>> mp;
        for (auto str: strs) {
            string t = str;
            sort(t.begin(), t.end());
            mp[t].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto [k,v]: mp) {
            ans.push_back(v);
        }
        return ans;
    }
};