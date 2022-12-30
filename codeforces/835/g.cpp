#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n,a,b;
vector<pair<int,int>> G[maxn];
bool ans[maxn];

int vala[maxn],valb[maxn];
set<int> st;
bool dfs(int u, int fa) {
    if ( u == b ) {
        return !vala[u];
    }
    st.insert(vala[u]);
    for ( auto ss : G[u] ) {
        int v = ss.first;
        int w = ss.second;
        if ( v == fa ) continue;
        vala[v] = vala[u] ^ w;
        if ( dfs(v,u) ) return true;
    }
    return false;
}
bool dfs2(int u, int fa) {
    if ( u != b ) {
        if ( st.find(valb[u]) != st.end() ) {
            return true;
        }
    }
    for ( auto ss : G[u] ) {
        int v = ss.first;
        int w = ss.second;
        if ( v == fa ) continue;
        valb[v] = valb[u] ^ w;
        if (dfs2(v,u)) return true;
    }
    return false;
}



int main ()
{
    IOS;
    int T ; cin >> T;
    for ( int cas = 1 ; cas <= T ; cas++ ) { 
        cin >> n >> a >> b;
        for ( int i = 1;  i <= n ; i++ ) G[i].clear();
        for ( int i = 1 ; i < n ; i++ ) {
            int u,v,w;
            cin >> u >> v >> w;
            G[u].push_back({v,w});
            G[v].push_back({u,w});
        }
        vala[a] = 0;
        valb[b] = 0;
        st.clear();
        if (dfs(a,-1)) {
            ans[cas] = 1;
        } else {
            ans[cas] = dfs2(b,-1);
        }
    }
    for ( int i = 1 ; i <= T ; i++ )
        if ( ans[i] ) cout << "YES" << endl;
        else cout << "NO" << endl;
}