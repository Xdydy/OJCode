#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(2e5+10)

int n;
ll x,y;
vector<int> G[maxn];
ll dp[maxn][2];

void dfs(int u, int p) {
    dp[u][0] = x;
    dp[u][1] = y;
    if (G[u].size() == 1 && p != -1) {
        return;
    }

    for (auto v : G[u]) {
        if (v == p) continue;
        dfs(v,u);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

void solve() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        G[i].clear();
    }
    for (int i = 1; i < n; i++) {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,-1);
    cout << max(dp[1][0], dp[1][1]) << endl;
}

int main () {
    int T ; cin >> T;
    while(T--) {
        solve();
    }
}