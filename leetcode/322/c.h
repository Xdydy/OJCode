#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        for ( auto x : roads ) {
            int u = x[0];
            int v = x[1];
            int d = x[2];
            G[u].push_back({v,d});
            G[v].push_back({u,d});
        } 
        dfs(1,-1);
        return ans;
    }
private:
    bool vis[maxn];
    vector<pair<int,int>> G[maxn];
    int ans = 1 << 30;
    void dfs(int u, int fa) {
        if (vis[u]) return ;
        vis[u] = 1;
        for ( auto ss : G[u] ) {
            int v = ss.first;
            int d = ss.second;
            if (v == fa)  continue;
            ans = min(ans, d);
            dfs(v,u);
        }
    }
};