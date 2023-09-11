#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
ll x[maxn],y[maxn];
ll ans[maxn];


int main () {
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        cin >> n;
        for ( int i = 1 ; i <= n ; i++ ) {
            cin >> x[i] >> y[i];
        }
        map<int,ll> h;
        map<int,ll> v;
        map<ll,ll> m1,m2;
        ll sum = 0 ;
        for ( int i = 1 ; i <= n ; i++ ) {
            if (v.find(x[i]) == v.end() ) {
                v[x[i]] = 1;
            } else {
                sum += v[x[i]];
                v[x[i]]++;
            }

            if (h.find(y[i]) == h.end() ) {
                h[y[i]] = 1;
            } else {
                sum += h[y[i]];
                h[y[i]]++;
            }

            if ( m1.find(y[i]+x[i]) == m1.end() ) {
                m1[x[i]+y[i]] = 1;
            } else {
                sum += m1[x[i]+y[i]];
                m1[x[i]+y[i]]++;
            }

            if ( m2.find(y[i]-x[i]) == m2.end() ) {
                m2[y[i]-x[i]] = 1;
            } else {
                sum += m2[y[i]-x[i]];
                m2[y[i]-x[i]]++;
            }
        }
        ans[cas] = sum*2;
    }
    for ( int i = 1 ; i <= T ; i++ )
        cout << ans[i] << endl;
}