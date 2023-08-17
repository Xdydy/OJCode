#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
ll a[maxn];
ll b[maxn];

ll pre[maxn],suf[maxn];

void solve() {
    cin >> n;
    memset(pre,0,sizeof(ll)*(n+5));
    memset(suf,0,sizeof(ll)*(n+5));
    for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
    for ( int i = 1 ; i <= n ; i++ ) {
        b[i] = a[i];
    }
    sort(b+1,b+1+n);
    map<int,ll> mp;
    ll sum = 0;
    for ( int i = 2 ; i <= n ; i++ ) {
        sum += 1ll*(i-1)*(b[i]-b[i-1]);
        pre[i] = sum;
    }
    sum = 0 ;
    for ( int i = n-1 ; i >= 1 ; i-- ) {
        sum += 1ll*(n-i)*(b[i+1]-b[i]);
        suf[i] = sum;
    }
    for ( int i = 1 ; i <= n ; i++ ) {
        int k = b[i];
        mp[k] = pre[i] + suf[i] + n;
    }
    vector<ll> ans;
    for ( int i = 1 ; i <= n ; i++ ) {
        int k = a[i];
        ans.push_back(mp[k]);
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