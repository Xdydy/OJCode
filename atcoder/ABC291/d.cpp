#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

const ll mod = 998244353;
int n;
int a[maxn], b[maxn];
ll dp[maxn][2];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];

    dp[1][0] = dp[1][1] = 1;
    for (int i = 2 ; i <= n ; i++ ) {
        if ( a[i] != a[i-1] ) {
            dp[i][0] += dp[i-1][0];
            dp[i][0] %= mod;
        } 
        if ( a[i] != b[i-1] ) {
            dp[i][0] += dp[i-1][1];
            dp[i][0] %= mod;
        }
        if ( b[i] != a[i-1] )  {
            dp[i][1] += dp[i-1][0];
            dp[i][1] %= mod;
        }
        if ( b[i] != b[i-1] ) {
            dp[i][1] += dp[i-1][1];
            dp[i][1] %= mod;
        }
    }
    ll ans = dp[n][0] + dp[n][1] ;
    ans %= mod;
    cout << ans << endl;
}