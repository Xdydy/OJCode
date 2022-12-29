#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n, q;
int a[maxn];
ll sum[maxn];
ll xsum[maxn];
map<int,vector<int>> f[2];
int ans[maxn];

int qry(int l, int r) {
    if ( sum[l-1] == sum[r] ) {
        return 0;
    }
    if ( xsum[l-1] != xsum[r] ) {
        return -1;
    }
    int len = r-l+1;
    if ( len & 1 ) {
        return 1;
    }
    if ( !a[l] || !a[r] ) {
        return 1;
    }
    auto v = f[l%2][xsum[l-1]];
    auto it = lower_bound(v.begin(), v.end(), l+1);
    if ( it != v.end() && *it < r ) {
        return 2;
    }
    return -1;
}

int main() {
    IOS;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for ( int i = 1 ; i <= n ; i++ ) {
        sum[i] = sum[i-1] + a[i];
        xsum[i] = xsum[i-1] ^ a[i];
    }
    for ( int i = 0 ; i <= n ; i++ ) {
        f[i%2][xsum[i]].push_back(i);
    }

    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        ans[i] = qry(l,r);
    }
    for ( int i = 1 ; i <= q ; i++ ) {
        cout << ans[i] << endl;
    }
}