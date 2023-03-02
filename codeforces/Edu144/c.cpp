#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

const ll mod = 998244353;
int l, r;
pair<int, ll> ans[maxn];

pair<int, ll> solve() {
    int res1 = 0;
    int cur = l;
    while (cur <= r) {
        res1++;
        cur <<= 1;
    }
    ll res2 = (r / (1 << (res1 - 1))) - l + 1;
    if (res1 >= 2) {
        int f = (1 << (res1 - 2)) * 3;
        res2 += 1ll * max(0, (r / f) - l + 1) * (res1 - 1);
    }
    return {res1, res2};
}

int main() {
    IOS;
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cin >> l >> r;
        ans[cas] = solve();
    }
    for (int i = 1; i <= T; i++)
        cout << ans[i].first << " " << ans[i].second << endl;
}