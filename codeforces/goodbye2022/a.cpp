#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n, m;
ll a[maxn], b[maxn];
ll ans[maxn];

int main() {
    IOS;
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= m; i++)
            cin >> b[i];
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for (int i = 1; i <= n; i++) {
            pq.push(a[i]);
        }
        for (int i = 1; i <= m; i++) {
            pq.pop();
            pq.push(b[i]);
        }
        ll sum = 0;
        while (pq.size()) {
            ll top = pq.top();
            sum += top;
            pq.pop();
        }
        ans[cas] = sum;
    }
    for (int i = 1; i <= T; i++)
        cout << ans[i] << endl;
}