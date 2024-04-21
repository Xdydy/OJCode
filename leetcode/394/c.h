#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n,m;
int a[1005][15];
int dp[1005][15];
class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        for (int i = 0; i <= 9; i++) {
            dp[0][i] = 0;
        }
        for (int i = 1; i <= m; i++) {
            int vis[15] ;
            memset(vis,0,sizeof(vis));
            for (int j = 1; j <= n; j++) {
                int val = grid[j-1][i-1];
                vis[val]++;
            }
            for (int j = 0; j <= 9; j++) {
                a[i][j] = n - vis[j];
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 0; j <= 9; j++) {
                dp[i][j] = 1 << 30;
                for (int k = 0; k <= 9; k++) {
                    if (j == k) continue;
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + a[i][j]);
                }
            }
        }
        int ans = 1 << 30;
        for (int i = 0; i <= 9; i++) {
            ans = min(ans, dp[m][i]);
        }
        return ans;
    }
};