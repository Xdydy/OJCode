#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int> mp;
        for ( auto ss : nums1)   {
            int id=ss[0];
            int val = ss[1];
            mp[id] += val;
        }
        for ( auto ss : nums2)   {
            int id=ss[0];
            int val = ss[1];
            mp[id] += val;
        }
        vector<vector<int>> ans;
        for ( auto x : mp ) {
            int id = x.first;
            int val = x.second;
            ans.push_back({id,val});
        }
        return ans;
    }
};