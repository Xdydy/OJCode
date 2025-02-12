#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    long long maxScore(vector<int>& points, int m) {
        int n = points.size();
        auto judge = [=](ll x) -> bool {
            vector<ll> cnt(n);
            for (int i = 0; i < n; i++) {
                cnt[i] = x / points[i];
                if (x % points[i]) {
                    cnt[i]++;
                }
            }

            int rest = m;
            int last = -1;
            for (int i = 0; i < n; i++) {
                if (cnt[i] > 0) {
                    rest -= (i-last);
                    if (rest < 0) {
                        return false;
                    }
                    last = i;
                    cnt[i]--;
                    if (rest < 2 * cnt[i]) {
                        return false;
                    }
                    rest -= 2*cnt[i];
                    if (i+1 < n) {
                        cnt[i+1] -= cnt[i];
                    }
                    cnt[i] = 0;
                }
                
            }
            return true;
        };
        ll l = 0, r = 1e18;
        while(l < r) {
            ll mid = l + r + 1 >> 1;
            if (judge(mid)) {
                l = mid;
            } else {
                r = mid-1;
            }
        }
        return l;
    }
};