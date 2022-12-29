#include <bits/stdc++.h>
using namespace std;
#define max_size (int)(1e6+10)

vector <int> G[max_size];
bool vis[max_size];
int n , m;
int dp[max_size][2];

void dfs ( int u )
{
    vis[u] = 1;
    for ( int i = 0 ; i < G[u].size() ; i++ )
    {
        int v = G[u][i];
        if ( vis[v] ) continue;
        dfs(v);
        dp[u][1] += dp[v][0];
        dp[u][0] += max ( dp[v][0] , dp[v][1] );
    }
    return ;
}

int main ()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for ( int i = 1 ; i <= m ; i++ )
    {
        int u , v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for ( int i = 1 ; i <= n ; i++ )
    {
        if ( !vis[i] )
        {
            dfs(i);
            cout << max ( dp[i][0] , dp[i][1] ) << endl; 
        }
    }
}