#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

string s;
int a[10];
bool vis[10];
const ll mod = 1e9 + 7;

ll quick_pow(ll x, int k) {
    ll res = 1;
    while (k) {
        if (x & 1)
            res = res * x % mod;
        k >>= 1;
        x = x * x % mod;
    }
    return res;
}
ll getInv(ll x) { return quick_pow(x, mod - 2); }

ll ans = 0;
void dfs(int step) {
    if (step == 10) {
        ll res = 0;
        for (int i = 1; i <= 9; i++) {
            res = res * 10 + a[i];
        }
        res = res * 1000000000 + res;
        ans += res % 7;
        ans %= mod;
        return;
    }
    if (a[step] == -1) {
        for (int i = 1; i <= 9; i++) {
            if (!vis[i]) {
                a[step] = i;
                vis[i] = 1;
                dfs(step+1);
                vis[i] = 0 ;
                a[step] = -1;
            }
        }
    } else {
        dfs(step+1);
    }
}
int main() {
    cin >> s;
    s = ' ' + s;
    int cnt = 0;
    for (int i = 1; i <= 9; i++) {
        if (s[i] == '?') {
            a[i] = -1;
            cnt++;
        } else {
            a[i] = s[i] - '0';
            vis[a[i]] = 1;
        }
    }
    ll sum = 1;
    for (int i = 1; i <= cnt; i++) {
        sum *= i;
        sum %= mod;
    }
    dfs(1);
    // cout << ans << endl;
    // cout << sum << endl;
    cout << ans * getInv(sum) % mod << endl;
}