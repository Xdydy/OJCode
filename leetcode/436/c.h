#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e5+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


ll dp[maxn][10][10];
class Solution {
public:
    long long countSubstrings(string s) {
        int n = s.length();
        s = ' ' + s;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 9; j++) {
                for (int k = 0; k <= 9; k++) {
                    dp[i][j][k] = 0;
                }
            }
        }
        // for(int i = 1; i <= 9; i++) {
        //     dp[0][0][i] = 1;
        // }
        for(int i = 1; i <= n; i++) {
            int x = s[i] - '0';
            for (int j = 1; j <= 9; j++) {
                dp[i][x%j][j] += 1;
            }
            for (int j = 0; j < 9; j++) {
                for (int k = j+1; k <= 9; k++) {
                    int rest = (j * 10 + x) % k;
                    dp[i][rest][k] += dp[i-1][j][k];
                }
            }
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            int x = s[i] - '0';
            ans += dp[i][0][x];
        }
        return ans;
    }
};