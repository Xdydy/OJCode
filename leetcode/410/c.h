#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
private:
    const ll mod = 1e9+7;
    int n ;
    int a[2005];
    ll dp[2005][55];
public:
    int countOfPairs(vector<int>& nums) {
        n = nums.size();
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            a[i] = nums[i-1];
        }
        a[0] = mod;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= a[i]; j++) {
                int pj = a[i] - j;
                for (int k = 0; k <= min(a[i-1], j); k++) {
                    int pk = a[i-1]-k;
                    if (pj > pk) break;
                    dp[i][j] += dp[i-1][k];
                    dp[i][j] %= mod;
                }
                // cout << i << " " << j << " " << dp[i][j] << endl;
            }
        }
        ll ans = 0 ;
        for (int i = 0; i <= 50; i++) {
            ans += dp[n][i];
            ans %= mod;
        }
        return ans;
    }
};