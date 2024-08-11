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
    ll dp[2005][1005];
    ll pre[1005];
public:
    int countOfPairs(vector<int>& nums) {
        n = nums.size();
        memset(dp,0,sizeof(dp));
        memset(pre,0,sizeof(pre));
        dp[0][0] = 1;
        for (int i = 0; i <= 1000; i++) {
            pre[i] = 1;
        }
        for (int i = 1; i <= n; i++) {
            a[i] = nums[i-1];
        }
        a[0] = mod;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= a[i]; j++) {
                int pj = a[i] - j;
                int k = min(a[i-1],j);
                k = min(k, a[i-1]-pj);
                if (k >= 0) {
                    dp[i][j] = pre[k];
                } 
                // cout << i << " " << j << " " << dp[i][j] << endl;
            }
            pre[0] = dp[i][0];
            for (int j = 1; j <= 1000; j++) {
                pre[j] = pre[j-1] + dp[i][j];
                pre[j] %= mod;
            }
        }
        ll ans = 0 ;
        for (int i = 0; i <= 1000; i++) {
            ans += dp[n][i];
            ans %= mod;
        }
        return ans;
    }
};