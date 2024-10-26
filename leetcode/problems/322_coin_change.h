#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
private:
    int dp[15][10005];
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
            for (int j = 1; j <= amount; j++) {
                dp[i][j] = 1 << 29;
            }
        }
        for (int i = 1; i <= n; i++) { 
            for (int j = 0; j <= amount; j++) {
                dp[i][j] = dp[i-1][j];
            }
            int x = coins[i-1];
            for (int j = x; j <= amount; j++) {
                dp[i][j] = min(dp[i][j], dp[i][j-x] + 1);
            }
        }
        if (dp[n][amount] == 1 << 29) {
            return -1;
        }
        return dp[n][amount];
    }
};