#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
private:
    const ll mod = 1e9 + 7;
    ll pow2[205], pow3[205];
    int cnt[205];
    void init() {
        pow2[0] = pow3[0] = 1;
        for (int i = 1; i <= 200; i++) {
            pow2[i] = (pow2[i-1] * 2) % mod;
            pow3[i] = (pow3[i-1] * 3) % mod;
        }
    }
    ll dp[205];
    ll dp2[205];
public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        init();
        for (int i = 1; i <= 200; i++) {
            int tmp = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] % i == 0) {
                    tmp++;
                }
            }
            cnt[i] = tmp;
        }

        memset(dp,0,sizeof(dp));
        for (int i = 200; i >= 1; i--) {
            if (cnt[i] == 0) {
                continue;
            }
            ll sum = (pow3[cnt[i]] - pow2[cnt[i]] * 2 + 1) % mod;
            ll multi = i*2;
            while(multi <= 200) {
                sum = (sum + mod - dp[multi]) % mod;
                multi += i;
            }
            dp[i] = sum;
        }
        ll res = 0 ;
        for (int i = 1; i <= 200; i++) {
            res += dp[i];
            res %= mod;
        }
        return res;
    }
};