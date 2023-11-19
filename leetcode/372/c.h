#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
private:
    const ll mod = 1e9+7;
    int f[3][55];
public:
    int maximumXorProduct(long long a, long long b, int n) {
        ll x = a;
        int cnt = 1;
        memset(f,0,sizeof(f));
        while(x) {
            f[1][cnt] = x & 1;
            x >>= 1;
            cnt++;
        }
        int len1 = cnt-1;
        x = b;
        cnt = 1;
        while(x) {
            f[2][cnt] = x & 1;
            x >>= 1;
            cnt++;
        }
        int len2 = cnt-1;

        vector<int> v;
        ll res = 0;
        for ( int i = 1 ; i <= n ; i++ ) {
            if (f[1][i] != f[2][i]) {
                v.push_back(i);
            } else {
                res |= (1ll<<(i-1));
            }
        }

        ll xa = res;
        ll xb = res;
        for ( int i = n+1 ; i <= len1 ; i++ ) {
            if (f[1][i] == 1) {
                xa |= (1ll<<(i-1));
            }
        }
        for ( int i = n+1 ; i <= len2 ; i++ ) {
            if (f[2][i] == 1) {
                xb |= (1ll<<(i-1));
            }
        }

        for ( int i = v.size()-1 ; i >= 0 ; i-- ) {
            int val=v[i];
            if (xa < xb) {
                xa |= (1ll<<(val-1));
            } else {
                xb |= (1ll<<(val-1));
            }
        }

        ll ans = (xa % mod) * (xb % mod) % mod;
        return ans;

    }
};