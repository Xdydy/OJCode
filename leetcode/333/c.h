#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Solution {
private:
    const ll mod = 1e9 + 7;
    int a[1005];
    int pri[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    ll dp[105][1<<12];
    bool vis[1005];

public:
    int squareFreeSubsets(vector<int> &nums) {
        int n = nums.size();
        memset(a, 0, sizeof(a));
        memset(dp,0,sizeof(dp));
        memset(vis,0,sizeof(vis));
        
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            for (int j = 0; j < 10; j++) {
                int cnt = 0;
                while (x % pri[j] == 0) {
                    cnt++;
                    x /= pri[j];
                }
                if (cnt==1) {
                    a[i + 1] |= (1<<j);
                } else if ( cnt >= 2 ){
                    vis[i+1] = 1;
                }
            }
        }
        ll res = 0;
        dp[0][0] = 1;
        for ( int i = 1 ; i <= n ; i++ ) {
            for ( int j = 0 ; j <= (1<<10) ; j++ ) 
                dp[i][j] = dp[i-1][j];

            if (vis[i]) continue;
            for ( int j = 0 ; j <= (1<<10) ; j++ ) {
                if ( (a[i]|j) == (a[i]^j) ) {
                    dp[i][a[i]|j] += dp[i][j];
                    dp[i][a[i]|j] %= mod;
                }
            }
        }
        for ( int i = 0 ; i <= (1<<10) ; i++ ) {
            res += dp[n][i];
            if ( i == 0 ) res--;
            res %= mod;
        }
         
        return res;
    }
};