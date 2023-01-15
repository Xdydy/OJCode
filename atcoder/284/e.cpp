#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n,m;
int deg[maxn];
vector<int> G[maxn];
bool vis[maxn];
int res=0;
void dfs(int u) {
    if (vis[u]) return;
    res++;
    if (res==1e6) {
        return;
    }
    vis[u] = 1;
    for (auto v : G[u]) {
        dfs(v);
        if (res==1e6) return;
    }
    vis[u] = 0;
}

int main () {
    cin >> n >> m ;
    for ( int i = 1 ; i <= m ; i++ ) {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        ++deg[u];
        ++deg[v];
    }
    dfs(1);
    cout << res << endl;
}