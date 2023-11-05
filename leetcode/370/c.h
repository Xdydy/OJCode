#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e5+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


class Solution {
private:
    int n;
    ll a[maxn];
    vector<int> G[maxn];
    ll dp[maxn][2];
    ll sum[maxn];
    void dfs(int u, int fa) {
        sum[u] = a[u];
        if (G[u].size() == 1 && fa != -1) {
            return;
        }

        for ( auto v : G[u]) {
            if (v == fa) continue;
            dfs(v,u);
            sum[u] += sum[v];
        }
    }


    void dfs2(int u, int fa) {
        if (G[u].size() == 1 && fa != -1) {
            dp[u][1] = a[u];
            dp[u][0] = 0;
            return;
        }

        dp[u][1] = sum[u];
        dp[u][0] = sum[u] - a[u];

        ll res = a[u];
        for ( auto v : G[u] ) {
            if (v == fa) continue;
            dfs2(v,u);
            res += dp[v][0];
        }

        dp[u][0] = max(dp[u][0], res);
    }
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        n = values.size();
        for (int i = 0 ; i < n ; i++) {
            a[i] = values[i];
        }
        memset(dp,0,sizeof(dp));
        memset(sum,0,sizeof(sum));

        for (auto edge: edges) {
            int u = edge[0];
            int v = edge[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }

        dfs(0,-1);
        dfs2(0,-1);
        return dp[0][0];
    }
};