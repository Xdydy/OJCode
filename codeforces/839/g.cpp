#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n;
ll x, y;
ll a[maxn];
ll u[maxn], v[maxn];
ll ans[maxn];

int main() {
    IOS;
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cin >> n >> x >> y;
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        sort(a + 1, a + 1 + n);
        u[1] = a[1];
        v[1] = a[1] + 1;
        for (int i = 2; i <= n; i++) {
            if (v[i - 1] >= a[i]) {
                u[i] = u[i - 1];
                v[i] = v[i - 1] + 1;
            } else {
                u[i] = a[i] - i + 1;
                v[i] = a[i] + 1;
            }
        }
        u[n + 1] = 1ll << 60;

        int p = upper_bound(u + 1, u + 1 + n, x) - u - 1;
        int m = n - p;
        ll res = 0;
        while (x + p < y) {
            if (p <= m) {
                res = -1;
                break;
            }
            ll k1 = (y - p - x) / (p - m);
            if ((y - p - x) % (p - m))
                k1++;
            ll k2 = (u[p + 1] - x) / (p - m);
            if ((u[p + 1] - x) % (p - m))
                k2++;
            ll minx = min(k1, k2);
            x += minx * (p - m);
            res += minx * n;
            p = upper_bound(u + 1, u + 1 + n, x) - u - 1;
            m = n - p;
        }
        if (res == -1) {
            ans[cas] = -1;
        } else {
            res += y - x;
            ans[cas] = res;
        }
    }
    for (int i = 1; i <= T; i++)
        cout << ans[i] << endl;
}