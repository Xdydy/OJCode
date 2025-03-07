#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int dp[205][205][205];
class Solution {
public:
    int longestPalindromicSubsequence(string s, int k) {
        int n = s.length();
        s = ' ' + s;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][i][j] = 1;
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                int minch = min(s[i], s[i+1]) - 'a';
                int maxch = max(s[i], s[i+1]) - 'a';
                int diff = maxch-minch;
                diff = min(diff, 26-diff);
                if (j >= diff) {
                    dp[i][i+1][j] = 2;
                } else {
                    dp[i][i+1][j] = 1;
                }
            }
        }
        for (int len = 2; len <= n; len++) {
            for (int st = 1; st+len-1 <= n; st++) {
                int ed = st + len-1;
                int minch = min(s[st], s[ed]) - 'a';
                int maxch = max(s[st], s[ed]) - 'a';
                int diff = maxch - minch;
                diff = min(diff, 26-diff);
                for (int j = 0; j <= k; j++) {
                    dp[st][ed][j] = max(dp[st][ed-1][j], dp[st+1][ed][j]);
                    if (j >= diff) {
                        dp[st][ed][j] = max(dp[st][ed][j], dp[st+1][ed-1][j-diff] + 2);
                    }
                    if (j > 0) {
                        dp[st][ed][j] = max(dp[st][ed][j], dp[st][ed][j-1]);
                    }
                }
            }
        }
        return dp[1][n][k];
    }
};