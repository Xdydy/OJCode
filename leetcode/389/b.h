#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int pre[maxn];
class Solution {
public:
    long long countSubstrings(string s, char c) {
        ll ans = 0;
        int n = s.length();
        s = ' ' + s;

        pre[0] = 0;
        for (int i = 1 ; i <= n ; i++) {
            if (s[i] == c) {
                pre[i] = pre[i-1] + 1;
            } else {
                pre[i] = pre[i-1];
            }
        }
        for (int i = 1; i <= n ; i++ ) {
            if (s[i] == c) {
                ans += 1ll*(pre[n]-pre[i]+1);
            }
        }
        return ans;
    }
};