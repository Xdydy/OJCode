#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

vector<ll> ans;
int n , q;
int h[maxn],w[maxn];
ll sum[1005][1005];

int main () {
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T; cas++ ) {
        cin >> n >> q;
        for ( int i = 1 ; i <= n ; i++ ) {
            cin >> h[i] >> w[i];
        }
        memset(sum,0,sizeof(sum));
        for ( int i = 1 ; i <= n ; i++ ) {
            sum[h[i]][w[i]] += 1ll*h[i]*w[i];
        }
        for ( int i = 1 ; i <= 1000 ; i++ ) {
            for ( int j = 1 ; j <= 1000 ; j++ ) {
                sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            }
        }

        for ( int i = 1 ; i <= q ; i++ ) {
            int hs,ws,hb,wb;
            cin >> hs >> ws >> hb >> wb;
            hb--,wb--;
            ll res = sum[hb][wb] + sum[hs][ws] - sum[hs][wb] -  sum[hb][ws];
            ans.push_back(res);
        }
    }
    for ( auto x : ans ) {
        cout << x << "\n";
    }
}