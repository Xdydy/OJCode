#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e5+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


class Solution {
private:
    int dp[maxn];
    int dp2[maxn];
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) -> bool {
            return a[0] < b[0];
        });
        int n = envelopes.size();
        for (int i = 1; i <= n+5; i++) {
            dp[i] = 1 << 30;
            dp2[i] = 1 << 30;
        }
        vector<vector<int>> v;
        for (int i = 0; i < n; i++) {
            int x = envelopes[i][0];
            vector<int> tmp;
            while(i < n && envelopes[i][0] == x) {
                tmp.push_back(envelopes[i][1]);
                i++;
            }
            i--;
            v.push_back(tmp);
        }

        int maxx = 0 ;
        for (int i = 0; i < v.size(); i++) {
            map<int,int> mp;
            auto e = v[i];
            for (int j = 0; j < e.size(); j++) {
                int v = e[j];
                int pos = lower_bound(dp+1, dp+1+n, v) - dp;
                maxx = max(maxx, pos);
                if (mp.find(pos) == mp.end()) {
                    if (dp[pos] > v) {
                        mp[pos] = v;
                    }
                } else {
                    mp[pos] = min(mp[pos], v);
                }
            }
            for (auto [k,v]: mp) {
                dp[k] = v;
            }
        }
        return maxx;
    }
};