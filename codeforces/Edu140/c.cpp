#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

const ll mod = 998244353;
int n;
ll dp[105][105];
int a[105][105];

int main() {
    IOS;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    ll ans = 0;
    dp[1][1] = 1;
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= n + 1; j++) {
            int r = max(i, j);
            if (r == n + 1) {
                ans += dp[i][j];
                ans %= mod;
                continue;
            }
            bool ok = 1;
            for (int l = 1; l <= r; l++) {
                if (a[l][r] == 1 && l < j)
                    ok = 0;
                if (a[l][r] == 2 && l >= j)
                    ok = 0;
            }
            if (ok)
                dp[r + 1][j] = (dp[r + 1][j] + dp[i][j]) % mod;
            ok = 1;
            for (int l = 1; l <= r; l++) {
                if (a[l][r] == 1 && l < i)
                    ok = 0;
                if (a[l][r] == 2 && l >= i)
                    ok = 0;
            }
            if (ok)
                dp[i][r + 1] = (dp[i][r + 1] + dp[i][j]) % mod;
        }
    }
    cout << ans << endl;
}