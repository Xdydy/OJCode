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
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        ll ans = -1;
        if (m==n) {
            return 1ll*(m-1)*(n-1);
        }
        vector<pair<ll,ll>> v1,v2;
        v1.push_back({1,1});
        v2.push_back({1,1});
        v1.push_back({1+(n-1), n});
        v2.push_back({1-(n-1), n});
        v1.push_back({m,1});
        v2.push_back({m,1});
        v1.push_back({m+(n-1), n});
        v2.push_back({m-(n-1), n});


        for (auto h : hFences ) {
            v1.push_back({h,1});
            v2.push_back({h,1});
            v1.push_back({h+(n-1),n});
            v2.push_back({h-(n-1),n});
        }
        for (auto v : vFences) {
            v1.push_back({1+(v-1), v});
            v2.push_back({1-(v-1), v});
            v1.push_back({m+(v-1), v});
            v2.push_back({m-(v-1), v});
        }
        for (auto h : hFences) {
            for (auto v : vFences) {
                v1.push_back({h+(v-1),v});
                v2.push_back({h-(v-1),v});
            }
        }

        unordered_map<ll,ll> m1Min, m1Max;
        for (int i = 0 ; i < v1.size() ; i++ ) {
            ll val = v1[i].first;
            if (m1Min.find(val) == m1Min.end()) {
                m1Min[val] = v1[i].second;
            } else {
                m1Min[val] = min(m1Min[val], v1[i].second);
            }

            if (m1Max.find(val) == m1Max.end()) {
                m1Max[val] = v1[i].second;
            } else {
                m1Max[val] = max(m1Max[val], v1[i].second);
            }
        }
        unordered_map<ll,ll> m2Min, m2Max;
        for (int i = 0 ; i < v2.size() ; i++ ) {
            ll val = v2[i].first;
            if (m2Min.find(val) == m2Min.end()) {
                m2Min[val] = v2[i].second;
            } else {
                m2Min[val] = min(m2Min[val], v2[i].second);
            }

            if (m2Max.find(val) == m2Max.end()) {
                m2Max[val] = v2[i].second;
            } else {
                m2Max[val] = max(m2Max[val], v2[i].second);
            }
        }

        for (auto item: m1Min) {
            auto key = item.first;
            auto val1 = item.second;
            auto val2 = m1Max[key];
            if (val1 != val2) {
                ans = max(ans, (val2-val1)*(val2-val1));
            }
        }
        for (auto item: m2Min) {
            auto key = item.first;
            auto val1 = item.second;
            auto val2 = m2Max[key];
            if (val1 != val2) {
                ans = max(ans, (val2-val1)*(val2-val1));
            }
        }



        
        if (ans == -1) {
            return -1;
        }
        return ans % mod;
    }
};