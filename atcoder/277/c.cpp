#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
int u[maxn],v[maxn];
vector<int> G[maxn];
vector<int> s;

bool vis[maxn];
int maxx = 1;
void dfs(int u, int fa) {
    if (vis[u]) return ;
    vis[u] = 1;
    maxx = max(maxx, u);
    for ( auto v : G[u] )  {
        if (v != fa)
            dfs(v,u);
    }
}
int main () {
    cin >> n ;
    for ( int i = 1 ; i <= n ; i++ ) {
        cin >> u[i] >> v[i];
        s.push_back(u[i]);
        s.push_back(v[i]);
    }
    s.push_back(0);
    s.push_back(1);
    sort(s.begin(),s.end());
    int tot = unique(s.begin(),s.end()) - s.begin();
    s.resize(tot);

    for ( int i = 1 ; i <= n ; i++ ) {
        int l = lower_bound(s.begin(), s.end(), u[i]) - s.begin();
        int r = lower_bound(s.begin(), s.end(), v[i]) - s.begin();
        G[l].push_back(r);
        G[r].push_back(l);
    }
    if ( G[1].size() ) 
        dfs(1,-1);
    cout << s[maxx] << endl;
}
