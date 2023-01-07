#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n;
int a[maxn];
int p[maxn];
int ans[maxn];
int vis[maxn];

void dfs(int u, int col) {
    if (vis[u]) {
        return;
    }
    vis[u] = col;
    dfs(p[u],col);
}

int main() {
    IOS;
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++) {
            p[a[i]] = i;
        }
        memset(vis,0,sizeof(int)*(n+5));
        int cur = 0 ;
        for ( int i = 1 ; i <= n ; i++ ) {
            if (!vis[i]) {
                dfs(i,++cur);
            }
        }
        int cnt = n-cur;
        int res = 1<<29;
        for ( int i = 1;  i < n ; i++ ) {
            if (vis[i] != vis[i+1]) {
                res = min(res,cnt+1);
            } else {
                res = min(res,cnt-1);
            }
        }
        ans[cas] = res;
    }
    for (int i = 1; i <= T; i++)
        cout << ans[i] << endl;
}