#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n;
vector<pair<int,int> > G[maxn];
ll dp[maxn][2];

int kids[maxn];
vector<int> ord;
int nodeNum = 0;
int tin[maxn], tout[maxn];
int pw[maxn];

void dfs(int u, int pa) {
    tin[u] = ++nodeNum;
    ord.push_back(u);
    kids[u] = 1;
    for ( auto ss : G[u] ) {
        int v = ss.first;
        int w = ss.second;
        if ( v == pa ) continue;
        dfs(v,u);
        pw[v] = w;
        kids[u] += kids[v];
    }

    tout[u] = nodeNum;
}
bool isp(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

vector<int> sv[maxn];
vector<int> ng[maxn];

ll dfs2(int u, int x) {
    ll res = 0 ;
    for ( int v : ng[u] ) {
        res += dfs2(v,x);
    }

    dp[u][0] = kids[u];
    dp[u][1] = 0;
    for ( int v : ng[u] ) dp[u][0] -= kids[v];
    for ( int v : ng[u] ) {
        if ( pw[v] == x ) {
            res += dp[u][0] * dp[v][0];
            dp[u][1] += dp[v][0];
        }
        else {
            res += dp[u][0] * dp[v][1];
            res += dp[u][1] * dp[v][0];
            dp[u][0] += dp[v][0];
            dp[u][1] += dp[v][1];
        }
    }


    return res;
}

int main () {
    IOS;
    cin >> n ;
    for ( int i = 1 ; i < n ; i++ ) {
        int u , v  ,w ;
        cin >> u >> v >> w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    dfs(1,-1);

    for ( int u : ord ) {
        for ( auto ss : G[u] ) {
            if ( sv[ss.second].empty() ) 
                sv[ss.second].push_back(1);
            sv[ss.second].push_back(u);
        }
    }

    ll ans =0 ;
    for ( int i = 1;  i <= n ; i++ ) {
        if ( sv[i].empty() ) continue;
        sv[i].resize(unique(sv[i].begin(), sv[i].end()) - sv[i].begin());
        stack<int> st;
        for ( int v : sv[i] ) {
            while( st.size() && !isp(st.top(), v) ) {
                st.pop();
            }
            if ( st.size() ) {
                ng[st.top()].push_back(v);
            }
            st.push(v);
        }
        ans += dfs2(1,i);
        for ( int v : sv[i] ) ng[v].clear();
    }
    cout << ans << endl;

}