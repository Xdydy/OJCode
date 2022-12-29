#include <bits/stdc++.h>
using namespace std;
#define max_size (int)(305)
int dp[max_size][max_size] , s[max_size];
int n , m;
vector <int> G[max_size];

int dfs ( int u )
{
    int p = 1;
    dp[u][1] = s[u];
    for ( int i = 0 ; i < G[u].size() ; i++ )
    {
        int v = G[u][i];
        int siz = dfs(v);
        for ( int i = min(p , m+1) ; i ; i-- )
            for ( int j = 1 ; j <= siz && i + j <= m+1 ; j++ )
                dp[u][i+j] = max ( dp[u][i+j] , dp[u][i] + dp[v][j] );
        p += siz;
    }
    return p;
}
int main ()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for ( int i = 1 ; i <= n ; i++ )
    {
        int k ;
        cin >> k >> s[i];
        G[k].push_back(i);
    }
    dfs(0);
    cout << dp[0][m+1] << endl;
}