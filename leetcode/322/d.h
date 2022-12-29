#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e3+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        this->n = n;
        for ( auto x : edges) {
            int u = x[0];
            int v = x[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }

        vector<vector<int>> ga;
        for ( int i = 1 ; i <= n ; i++ ) {
            if (!vis[i]) {
                g.clear();
                dfs(i);
                ga.push_back(g);
            }
        }

        bool flag = 1;
        int ans = 0;
        for ( auto ss : ga ) {
            maxx = 0;
            for ( auto x : ss ) {
                for ( auto y : ss ) {
                    d[y] = 0;
                }
                if (!bfs(x)) {
                    flag = 0 ;
                    break;
                }
            }
            ans += maxx;
            if (!flag) {
                break;
            }
        }
        if(!flag) return -1;
        else return ans;
    }
private:
    int n;
    int d[505];
    vector<int> G[maxn];
    bool vis[maxn];

    vector<int> g;
    void dfs(int u) {
        if (vis[u]) return ;
        vis[u] = 1;
        g.push_back(u);
        for ( auto v : G[u] ) {
            dfs(v);
        } 
    }

    int maxx = 0;
    bool bfs(int u) {
        queue<int> q;
        q.push(u);
        d[u] = 1;
        while(q.size()) {
            int u = q.front();
            q.pop();
            maxx = max(maxx, d[u]);
            for ( auto v : G[u] ) {
                if (d[v]) {
                    if ( abs(d[v]-d[u]) ==1 ) {
                        continue;
                    }
                    else {
                        return false;
                    }
                }
                else {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
        return true;
    }
};