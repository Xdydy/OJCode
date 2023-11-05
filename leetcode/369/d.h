#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e5+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
private:
    vector<int> G[maxn];
    int dp[maxn][25];
    int a[maxn];
    void dfs(int u,int fa, int k) {
        if (G[u].size() == 1 && fa != -1 ) {
            for ( int i = 0 ; i <= 20 ; i++ ) {
                int x = a[u] >> i;
                dp[u][i] = max(x-k,x/2);
            }
            return;
        }

        int dp2[25][2];
        memset(dp2,0,sizeof(dp2));
        for ( auto v : G[u] ) {
            if ( v == fa ) continue;
            dfs(v,u,k);
            for ( int i = 0 ; i <= 20 ; i++ ) {
                int x = a[u] >> i;
                dp2[i][0] += dp[v][i];
                dp2[i][1] += dp[v][i+1];
            }
        }
        for ( int i = 0 ; i <= 20 ; i++ ) {
            int x = a[u] >> i ;
            dp[u][i] = max(dp2[i][0] + x-k, dp2[i][1] + x/2);
        }
    }
public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        for ( auto edge : edges ) {
            int u = edge[0];
            int v = edge[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for ( int i = 0 ; i < coins.size() ; i++ ) {
            a[i] = coins[i];
        }
        dfs(0,-1,k);
        return max(dp[0][0], dp[0][1]);
    }
};