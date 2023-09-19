#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Solution {
public:
    int dp[25][10005];
    int tallestBillboard(vector<int> &a) {
        int n = a.size();
        int sum = 0 ;
        for ( auto x : a ) {
            sum += x;
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++)
                dp[i][j] = dp[i - 1][j];
            for (int j = 0; j <= sum; j++) {
                if (dp[i-1][j] < j)
                    continue;
                int k = j + a[i - 1];
                dp[i][k] = max(dp[i][k], dp[i - 1][j] + a[i - 1]);
                k = abs(j - a[i - 1]);
                dp[i][k] = max(dp[i][k], dp[i - 1][j] + a[i - 1]);
            }
        }
        return dp[n][0] / 2;
    }
};

