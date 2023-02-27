#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e5+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        for ( auto ss : edges ) {
            int u = ss[0];
            int v = ss[1];
            ++u;
            ++v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for ( int i = 0 ; i < price.size() ;i++ ) {
            val[i+1] = price[i];
        }


    }
private:
    vector<int> G[maxn];
    pair<ll,ll> val2[maxn];
    ll val[maxn];

    ll maxx1[maxn],maxx2[maxn];
    ll minx1[maxn],minx2[maxn];

    void dfs(int u, int fa) {
        if ( G[u].size() == 1 && u != 1 ) {
            val2[u].first = val[u];
            val2[u].second = val[u];
            return;
        }
        val2[u].first = val[u];
        for ( auto v : G[u] ) {
            if ( v ==fa ) continue;
            dfs(v,u);
        }
    }
};