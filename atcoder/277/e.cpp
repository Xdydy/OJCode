#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n, m, k;
bool vis[maxn];
struct edge {
    int to, a;
};
vector<edge> G[maxn];
int d[maxn][2];

int main() {
    IOS;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, a;
        cin >> u >> v >> a;
        G[u].push_back({v, a});
        G[v].push_back({u, a});
    }
    for (int i = 1; i <= k; i++) {
        int s;
        cin >> s;
        vis[s] = 1;
    }
    queue<pair<int, int>> q;
    q.push({1, 0});
    for (int i = 1; i <= n; i++) {
        d[i][0] = d[i][1] = 1 << 29;
    }
    d[1][0] = 0;
    while (q.size()) {
        auto top = q.front();
        q.pop();
        int u = top.first;
        int s = top.second;
        for (auto ss : G[u]) {
            int to = ss.to;
            int a = ss.a;
            if (a ^ s) {
                if (d[u][s] + 1 < d[to][s]) {
                    d[to][s] = d[u][s] + 1;
                    q.push({to, s});
                }
            }
        }
        if (vis[u]) {
            if (d[u][s] < d[u][s ^ 1]) {
                d[u][s ^ 1] = d[u][s] ;
                q.push({u, s ^ 1});
            }
        }
    }
    if (d[n][0] == 1 << 29 && d[n][1] == 1 << 29) {
        cout << -1 << endl;
    } else {
        cout << min(d[n][0], d[n][1]) << endl;
    }
}