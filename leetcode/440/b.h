#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

map<int,ll> dp;
class Solution {
public:
    vector<long long> findMaxSum(vector<int> &nums1, vector<int> &nums2,int k) {
        int n = nums1.size();
        map<int,vector<int>> mp;
        int maxx = 0;
        for (int i = 0; i < n; i++)  {
            int x = nums1[i];
            mp[x].push_back(i);
            maxx = max(maxx, x);
        }
        multiset<ll> st;
        ll sum = 0;
        for (auto [key,v]: mp) {
            dp[key] = sum;
            for (auto j: v) {
                ll val = nums2[j];
                if (st.size() < k) {
                    sum += val;
                    st.insert(val);
                } else {
                    if (val > *st.begin()) {
                        ll minx = *st.begin();
                        sum -= minx;
                        sum += val;
                        st.erase(st.begin());
                        st.insert(val);
                    }
                }
            }
        }
        vector<ll> ans;
        for (auto x : nums1) {
            ans.push_back(dp[x]);
        }
        return ans;
    }
};