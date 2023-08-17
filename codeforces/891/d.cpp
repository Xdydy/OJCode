#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
ll a[maxn];
ll b[maxn];
ll c[maxn];

void solve() {
    int n;
    cin >> n;
    for ( int i = 1 ; i <= n ; i++ ) cin >> a[i];
    for ( int i = 1 ; i <= n ; i++ ) cin >> b[i];
    vector<int> ans;
    for ( int i = 1 ; i <= n ; i++ ) {
        c[i] = a[i] - b[i];
    }
    ll maxx = -(1ll<<60);
    for ( int i = 1 ; i <= n ; i++ ) {
        maxx = max(maxx , c[i]);
    }
    for ( int i = 1 ; i <= n ; i++ ) {
        if ( c[i] == maxx ) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for ( int x : ans ) {
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