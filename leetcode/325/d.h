#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        ll tmp = 0;
        for ( auto x : nums ) {
            tmp += x;
        }
        for ( auto x : nums ) {
            if ( x >= k ) continue;
            for ( int i = k-1 ; i >=0  ; i-- ) {
                if ( i + x >= k ) continue;
                dp[i+x] = ( dp[i+x] + dp[i] ) % mod;
            }
        }
        int n = nums.size();
        ll sum = 1;
        for ( int i = 1 ; i <= n ; i++ ) {
            sum = sum * 2 % mod;
        }
        ll sum2 =  0;
        for ( int i = 0 ; i < k ; i++ ) {
            if ( tmp - i >= k ) {
                dp[i] *= 2;
                dp[i] %= mod;
            }
            sum2 += dp[i];
            sum2 %= mod;
        }
        ll ans = (sum-sum2+mod) % mod;
        return ans;
    }
private:
    const ll mod = 1e9+7;
    ll dp[1005];
};