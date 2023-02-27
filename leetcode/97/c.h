#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e5+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


class Solution {
public:
    int maximizeWin(vector<int>& p, int k) {
        int n = p.size();
        if ( n  == 1) {
            return 1;
        }
        for ( int i = 1 ; i <= n ; i++ ) {
            ll x = p[i-1];
            int pos1 = lower_bound(p.begin(), p.end(), x-k) - p.begin();
            int pos2 = upper_bound(p.begin(), p.end(), x+k) - p.begin();
            a[i] = i-1-pos1+1;
            b[i] = pos2-(i-1);
        }
        for ( int i = 1 ; i <= n ; i++ ) {
            pre[i] = max(a[i], pre[i-1]);
        }
        for ( int i = n ; i >= 1 ; i-- ) {
            suf[i] = max(b[i], suf[i+1]);
        }
        ll ans = 0 ;
        for ( int i = 1 ; i < n ; i++ ){
            ans = max(ans, pre[i]+suf[i+1]);
        }
        return ans;
    }
private:
    ll a[maxn], b[maxn];
    ll pre[maxn], suf[maxn];
};