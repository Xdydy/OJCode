#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(3e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

ll n;
int a[maxn];
pair<ll, ll> ans[maxn];

int main() {
    IOS;
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cin >> n;
        if (n % 2 || n < 4) {
            ans[cas].first = -1;
            continue;
        }
        ll cnt = n / 6;
        ll rest = n % 6;
        while (rest % 4 != 0) {
            cnt--;
            rest += 6;
        }
        ll res1 = cnt + rest / 4;

        cnt = n / 4;
        rest = n % 4;
        while (rest % 6 != 0) {
            cnt--;
            rest += 4;
        }
        ll res2 = cnt + rest / 6;
        ans[cas] = {res1, res2};
    }
    for (int i = 1; i <= T; i++)
        if (ans[i].first == -1)
            cout << -1 << endl;
        else
            cout << ans[i].first << " " << ans[i].second << endl;
}