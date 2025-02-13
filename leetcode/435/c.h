#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(5e4+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

ll dp[maxn][1<<4];
class Solution {
private:
    ll lcm(vector<int> v) {
        ll lcm = 1;
        for (int i = 0; i < v.size(); i++) {
            ll gcd = __gcd(1ll*v[i], lcm);
            lcm = 1ll*v[i]*lcm/gcd;
        }
        return lcm;
    }
    bool allContains(int s, int t, int m) {
        for (int i = 0; i < m; i++) {
            if ((t>>i) & 1) {
                if (!((s >> i) & 1)) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    int minimumIncrements(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < (1<<4); j++) {
                dp[i][j] = 1ll << 60;
            }
        }
        dp[0][0] = 0;
        int m = target.size();
        for (int i = 1; i <= n; i++) {
            int x = nums[i-1];
            vector<ll> a(1<<m);
            for (int j = 0; j < (1<<m); j++) {
                vector<int> tmp;
                for (int k = 0; k < m; k++) {
                    if ((j>>k) & 1) {
                        tmp.push_back(target[k]);
                    }
                }
                ll _lcm = lcm(tmp);
                ll cnt = x / _lcm;
                if (x % _lcm) {
                    cnt++;
                }
                ll dis = cnt * _lcm - x;
                a[j] = dis;
            }
            for (int j = 0; j < (1<<m); j++) {
                dp[i][j] = dp[i-1][j];
                for (int k = 0; k < (1<<m); k++) {
                    if (allContains(j,k,m)) {
                        dp[i][j] = min(dp[i][j], dp[i-1][k] + a[j^k]);
                    }
                }
            }   
        }
        return dp[n][(1<<m)-1];
    }
};