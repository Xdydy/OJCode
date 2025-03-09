#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>> &conflictingPairs) {
        for (auto &v : conflictingPairs) {
            if (v[0] > v[1]) {
                swap(v[0], v[1]);
            }
        }
        sort(conflictingPairs.begin(), conflictingPairs.end(), [&](vector<int> a1, vector<int> a2) {
            return a1[1] < a2[1] || (a1[1] == a2[1] && a1[0] < a2[0]);
        });

        ll ans = 0;
        int l = 1;
        int se = 1;
        ll cur = 0;
        ll mx = 0 ;
        int csiz = conflictingPairs.size();
        for (int i = 1, j = 0; i <= n; i++) {
            while(j < csiz && conflictingPairs[j][1] == i) {
                if (conflictingPairs[j][0] + 1 > l) {
                    mx = max(mx, cur);
                    cur = 0;
                    se = l;
                    l = conflictingPairs[j][0] + 1;
                } else {
                    se = max(se, conflictingPairs[j][0] + 1);
                }
                j++;
            }
            ans += i-l+1;
            cur += l-se;
        }
        return ans + max(mx, cur);
    }
};