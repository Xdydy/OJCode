#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n ;
ll a[maxn];
ll x,y;
void solve() {
    cin >> n ;
    for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
    a[n+1] = 1ll<<60;
    sort(a+1,a+1+n);
    int q ; cin >> q;
    vector<ll> ans;
    for ( int i = 1 ; i <= q ; i++ ) {
        cin >> x >> y;
        ll s = x*x-y*4;
        if ( s < 0 ) {
            ans.push_back(0);
            continue;
        }
        ll s1 = sqrt(s);
        if ( s1*s1 != s ) {
            ans.push_back(0);
            continue;
        }
        ll s2 = x+s1;
        if ( s2 % 2 ) {
            ans.push_back(0);
            continue;
        }
        ll a1 = s2 / 2;
        ll a2 = x - a1;
        if ( a1 != a2) {
            int pos1 = lower_bound(a+1,a+1+n,a1) - a;
            int pos2 = upper_bound(a+1,a+1+n,a1) - a;
            int cnt1 = pos2-pos1;
            pos1 = lower_bound(a+1,a+1+n,a2) - a;
            pos2 = upper_bound(a+1,a+1+n,a2) - a;
            int cnt2 = pos2 - pos1;
            ans.push_back(1ll*cnt1*cnt2);
        } else {
            int pos1 = lower_bound(a+1,a+1+n,a1) - a;
            int pos2 = upper_bound(a+1,a+1+n,a1) - a;
            int cnt = pos2-pos1;
            ans.push_back(1ll*cnt*(cnt-1)/2);
        }
    }
    for ( ll x : ans ) {
        cout << x << " ";
    }
    cout << endl;
}

int main () {
    IOS;
    // FFF;
    int T ; cin >> T;
    while(T--) {
        solve();
    }
}