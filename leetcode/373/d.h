#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(5e4+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int v[maxn];
int c[maxn];
int b[maxn];
map<int,int> cnt[maxn];

class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int n = s.length();
        memset(v,0,sizeof(v));
        memset(c,0,sizeof(c));
        int len = 1;
        for (int i = 1; i <= k ; i++ ) {
            if (i*i%k==0) {
                len = i*2;
                break;
            }
        }
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
        b[0] = 0;
        for ( int i = 1 ; i <= n ; i++ ) {
            b[i] = v[i] - c[i];
        }
        for ( int i = 0; i <= len; i++ ) {
            cnt[i].clear();
        }

        for ( int i = 0 ; i <= n ; i++ ) {
            int val = b[i];
            cout << val << endl;
            if (cnt[i%len].find(val) == cnt[i%len].end()) {
                cnt[i%len][val] = 0;
            }
            ans += cnt[i%len][val]; 
            cnt[i % len][val]++;
        }

        
        return ans;
    }
};