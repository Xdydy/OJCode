#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n ,q;
ll a[maxn];
ll ans[maxn];

int main () {
    IOS;
    cin >> n >> q;
    for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
    ll base = 0 ;
    ll sum = 0;
    map<int,ll> mp;
    for ( int i = 1 ; i <= n ; i++ ) {
        sum += a[i];
        mp[i] = a[i];
    }

    for ( int i = 1 ; i <= q ; i++ ) {
        int t ; cin >> t;
        if ( t == 1 ) {
            int i ;
            ll x ;
            cin >> i >> x;
            
            if ( mp.find(i) == mp.end() ) {
                sum += x-base;
                mp[i] = x;
            }
            else {
                sum += x-mp[i];
                mp[i] = x;
            }
        }
        else if ( t == 2 ) {
            ll x ; 
            cin >> x;
            base = x;
            sum = base * n;
            mp.clear();
        }
        ans[i] = sum;
    }
    for (int i = 1 ; i <= q ; i++ ) {
        cout << ans[i] << endl;
    }
}