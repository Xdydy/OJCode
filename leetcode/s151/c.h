#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);


int dp[1005][1005];
class Solution {
public:
    int minCost(vector<int> &nums) {
        int n = nums.size();
        if (n <= 2) {
            int maxx = 0;
            for (int i = 0; i < n; i++) {
                maxx = max(maxx, nums[i]);
            }
            return maxx;
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = 1 << 29;
            }
        }
        dp[0][0] = 0;
        dp[1][1] = max(nums[1], nums[2]);
        dp[1][2] = max(nums[0], nums[2]);
        dp[1][3] = max(nums[0], nums[1]);
        for (int i = 2; (i-1)*2+3 <= n; i++) {
            int block = (i-1)*2 + 3;
            int lasted = (i-2)*2 + 3;
            int mx = max(nums[lasted], nums[lasted+1]);
            for (int j = 1; j <= lasted; j++) {
                // 延续上一个
                dp[i][j] = min(dp[i][j], dp[i-1][j] + mx);
            }
            for (int j = 1; j <= lasted; j++) {
                int x = nums[j-1];
                dp[i][lasted+1] = min(dp[i][lasted+1], dp[i-1][j] + max(nums[lasted+1], x));
                dp[i][lasted+2] = min(dp[i][lasted+2], dp[i-1][j] + max(nums[lasted], x));
            }
        }
        int lastdp = (n-3) / 2 + 1;
        int ans = 1 << 30;
        if ((lastdp-1)*2 + 3 == n) {
            for (int i = 1; i <= n; i++) {
                ans = min(ans, dp[lastdp][i] + nums[i-1]);
            }
        } else {
            int x = nums[n-1];
            for (int i = 1; i <= (lastdp-1)*2+3; i++) {
                ans = min(ans, dp[lastdp][i] + max(nums[i-1], x));
            }
        }
        return ans;
    }
};