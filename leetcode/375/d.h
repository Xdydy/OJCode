#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


class Solution {
private:
    const ll mod = 1e9+7;
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        map<int,pair<int,int>> mp;
        int n = nums.size();
        for (int i = 0; i < n ; i++) {
            int x = nums[i];
            if (mp.find(x) == mp.end()) {
                mp[x] = {i,-1};
            } else {
                int right = mp[x].second;
                mp[x].second = max(right,i);
            }
        }

        vector<pair<int,int>> v;
        for (auto x : mp) {
            if (x.second.second == -1) {
                continue;
            }
            int left = x.second.first;
            int right = x.second.second;
            v.push_back({left,right});
        }

        sort(v.begin(),v.end());


        vector<pair<int,int>> v2;
        for(auto e : v) {
            if (v2.empty()) {
                v2.push_back(e);
            } else {
                auto lst = v2.back();
                if (lst.second < e.first) {
                    v2.push_back(e);
                } else {
                    v2.back().second = max(lst.second,e.second);
                }
            }
        }
        

        int cur = 0;
        ll ans = 1;
        v2.push_back({n-1,n-1});
        for (auto e : v2) {
            int len = e.first - cur;
            ll res = 1;
            for (int i = 1; i <= len ; i++) {
                res <<= 1;
                res %= mod;
            }
            ans *= res;
            ans %= mod;
            cur = e.second;
        }
        return ans;   
    }
};