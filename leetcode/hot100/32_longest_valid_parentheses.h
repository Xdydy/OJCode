#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(3e4 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Solution {
private:
    int dp[maxn];
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        s = ' ' + s;
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '(') {
                dp[i] = 0;
            } else {
                if (i==1) {
                    dp[i] = 0;
                } else {
                    if (s[i-1] == '(') {
                        dp[i] = dp[i-2] + 2;
                    } else {
                        if (i-dp[i-1]-1 >= 1 && s[i-dp[i-1]-1] == '(') {
                            dp[i] = dp[i-1] + dp[i-dp[i-1]-2] + 2;
                        }
                    }
                }
            }
        }
        int ans = 0 ;
        for (int i = 1;i <= n; i++) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};