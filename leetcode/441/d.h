#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Solution {
private:
    int dp[15];
    int p[15];
    int dfs(int u, int x, bool f0, bool lim) {
        if (!u) {
            if (f0) {
                f0 = false;
            }
            return 0;
        }
        if (!lim && !f0 && !dp[u]) {
            return dp[u];
        }
        int cnt = 0 ;
        int lst = lim ? p[u]: 9;
        for (int i = 0; i <= lst; i++) {
            if (f0 && i == 0) {
                cnt += dfs(u-1, x, 1, lim && i==lst);
            } 
        }
    }
    int solve(ll x) {
    }
public:
    int beautifulNumbers(int l, int r) {
        return solve(r) - solve(l-1);
    }
};