#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int v[maxn];
int c[maxn];

class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int n = s.length();
        memset(v,0,sizeof(v));
        memset(c,0,sizeof(c));
        s = ' ' + s;
        for ( int i = 1 ; i <= n ; i++ ) {
            c[i] = c[i-1];
            v[i] = v[i-1];
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                v[i]++;
            } else {
                c[i]++;
            }
        }

        int ans = 0;
        for ( int i = 1 ; i <= n ; i++ ) {
            for ( int j = i ; j <= n ; j++ ) {
                ll cntv = v[j] - v[i-1];
                ll cntc = c[j] - c[i-1];
                if (cntv == cntc && cntv * cntc % k == 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
};