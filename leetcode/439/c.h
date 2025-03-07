#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int dp[2005][2005];
int pre[2005];
class Solution {
public:
    int maxSum(vector<int> &nums, int k, int m) {
        int n = nums.size();
        pre[0] = 0 ;
        for (int i = 1; i <= n; i++) {
            int x = nums[i-1];
            pre[i] = pre[i-1] + x;
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = -(1<<29);
            }
        }
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int j = 1; j <= k; j++) {
            int maxx = -(1<<29);
            for (int i = j*m; i <= n - (k-j)*m; i++) {
                dp[i][j] = dp[i-1][j];
                maxx = max(maxx, dp[i-m][j-1] - pre[i-m]);
                dp[i][j] = max(dp[i][j], maxx+pre[i]);
            }
        }
        return dp[n][k];
    }
};