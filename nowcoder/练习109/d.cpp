#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

const ll mod = 1e9+7;
int n,k;
ll m;
ll a[maxn];

int main () {
    IOS;
    cin >> n >> m >> k;
    for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
    multiset<ll> st;
    for ( int i = 1 ; i <= n ; i++ ) {
        st.insert(a[i]);
    }
    while(k--) {
        ll minx = *st.begin();
        ll maxx = *st.rbegin();
        ll res1 = minx*maxx;
        ll res2 = (minx+m)*(maxx-m);
        if ( res1 >= res2 ) {
            break;
        } else {
            st.erase(st.begin());
            st.erase(prev(st.end()));
            st.insert(minx+m);
            st.insert(maxx-m);
        }
    }
    ll ans = 1;
    for ( auto x : st ) {
        ans *= x;
        ans %= mod;
    }
    cout << ans << endl;
}