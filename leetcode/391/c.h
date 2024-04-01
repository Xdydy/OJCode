#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n = nums.size();
        ll ans = 1ll*n*(n+1)/2;
        vector<pair<int,int>> v;
        for (int i = 0; i < n; i++) {
            int l = i;
            int val = nums[i];
            while(i < n && nums[i] ==val) {
                i++;
            }
            i--;
            int r = i;
            if (l != r) {
                v.push_back({l+1,r+1});
            }
        }
        for (int i = 0; i < v.size(); i++) {
            int l = v[i].first;
            int r = v[i].second;
            int nxl;
            if (i == v.size()-1) {
                nxl = n;
            } else {
                nxl = v[i+1].first;
            }
            ll res1 = 1ll*(l+r-1)*(r-l)/2;
            ll res2 = 1ll*(r-1)*(nxl-r);
            ans -= (res1+res2);
        }
        return ans;

    }
};