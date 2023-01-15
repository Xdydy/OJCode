#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n,m;
vector<int> G[105];
int vis[105];
int res = 0;
void dfs(int u, int fa) {
    if (vis[u]) return;
    vis[u] = res;
    for ( auto v : G[u] ) {
        if (v==fa) continue;
        dfs(v,u);
    }
}

int main () {
    cin >> n >> m;
    for ( int i = 1 ; i <= m ; i++ ) {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for ( int i = 1 ; i <= n ; i++ ) {
        if (!vis[i]) {
            ++res;
            dfs(i,-1);
        }
    }
    cout << res << endl;

}