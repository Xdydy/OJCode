#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(3e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n, m;
int c[maxn];
int a[45];
set<int> G[45];

int dp[maxn];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= m; i++)
        cin >> a[i];

    memset(dp, 0x3f, sizeof(dp));

    for (int i = 1; i <= n; i++) {
        int pre = i - 1;
        int nxt = i + 1;
        if (pre > 0) {
            G[c[i]].insert(c[pre]);
        }
        if (nxt <= n) {
            G[c[i]].insert(c[nxt]);
        }
    }

    int ans = 1 << 30;
    int mid = m / 2;

    for (int i = 0; i < (1 << mid); i++) {
        if ( c[1] <= mid && ((1 << (c[1]-1)) & i) == 0 ) {
            continue;
        }
        if ( c[n] <= mid && ((1 << (c[n]-1)) & i) == 0 ) {
            continue;
        }
        bool flag = 1;
        set<int> st;
        int sum = 0;
        for (int j = 0; j < mid; j++) {
            if ((1 << j) & i) {
                sum += a[j + 1];
            } else {
                int u = j + 1;
                for (auto v : G[u]) {
                    if (v <= mid && ((1 << (v - 1)) & i) == 0) {
                        flag = 0;
                        break;
                    } else if (v > mid) {
                        st.insert(v);
                    }
                }
                if (!flag) break;
            }
        }
        if (flag) {
            // if (st.empty()) {
            //     ans = min(ans, sum);
            // }

            int con = 0;
            for (auto x : st) {
                con |= (1 << (x - mid - 1));
            }
            dp[con] = min(dp[con], sum);
        }
    }
    int mid2 = m-mid;
    for (int i = 0; i < mid2; i++) {
        for (int con = 0; con < (1 << mid2); con++) {
            if (!((1 << i) & con)) {
                dp[con | (1 << i)] = min(dp[con | (1 << i)], dp[con]);
            }
        }
    }

    for (int i = 0; i < (1 << mid2); i++) {
        if ( c[1] > mid && ((1 << (c[1]-1-mid)) & i) == 0 ) {
            continue;
        }
        if ( c[n] > mid && ((1 << (c[n]-1-mid)) & i) == 0 ) {
            continue;
        }
        bool flag = 1;
        int sum = 0;
        for (int j = 0; j < mid2 ; j++) {
            if ((1 << j) & i) {
                int u = mid + 1 + j;
                sum += a[u];
            } else {
                int u = mid + 1 + j;
                for (int v : G[u]) {
                    if (v > mid && (((1 << (v - mid - 1)) & i )== 0)) {
                        flag = 0;
                        break;
                    }
                }
                if (!flag) break;
            }
        }
        if (flag) {
            ans = min(ans, dp[i] + sum);
        }
    }
    cout << ans << endl;
}