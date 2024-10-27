#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


class Solution {
private:
    const ll mod = (int)(1e9+7);
    ll dp[30][100005];
    ll getDP(int ch, int t) {
        if (dp[ch][t] != -1) return dp[ch][t];
        if (ch + t < 26) {
            dp[ch][t] = 1;
            return dp[ch][t];
        } else {
            int rest = 26 - ch;
            dp[ch][t] = (getDP(0,t-rest) + getDP(1,t-rest)) % mod;
            return dp[ch][t];
        }
    }
public:
    int lengthAfterTransformations(string s, int t) {
        int n = s.length();
        ll res = 0;
        for (int ch = 0; ch < 26; ch++) {
            for (int i = 0; i <= t; i++) {
                dp[ch][i] = -1;
            }
        }
        for (int i = 0; i < s.length(); i++) {
            int ch = s[i]-'a';
            res += getDP(ch,t);
            res %= mod;
        }
        return res;
    }
};