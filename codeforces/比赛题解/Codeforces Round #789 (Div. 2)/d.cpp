#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n, m;
string s;
int ans1[maxn], ans2[maxn];
bool vis[maxn];
int dp[maxn];
int pre[maxn];

int main() {
    IOS;
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cin >> n >> m;
        cin >> s;
        s = ' ' + s;
        memset(vis, 0, sizeof(bool) * (m + 5));
        memset(dp, 0, sizeof(int) * (n * m + 5));
        memset(pre, 0, sizeof(int) * (n * m + 5));

        int res = 0;
        for (int i = 1; i <= n * m; i++) {
            pre[i] = pre[i - 1];
            if (s[i] == '1') {
                pre[i]++;
                int col = i % m;
                if (!vis[col]) {
                    res++;
                    vis[col] = 1;
                }
            }
            ans1[i] = res;
        }

        res = 0;
        for (int i = 1; i <= n * m; i++) {
            if (i > m) {
                dp[i] = dp[i - m] + (pre[i] - pre[i - m] != 0);
                ans2[i] = dp[i];
            } else {
                dp[i] = (pre[i] != 0);
                ans2[i] = (pre[i] != 0);
            }
        }

        for (int i = 1; i <= n * m; i++) {
            cout << ans1[i] + ans2[i] << " ";
        }
        cout << endl;
    }
}