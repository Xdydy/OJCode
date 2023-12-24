#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n;
int a[maxn];
ll ans[maxn];
vector<int> G[maxn];
vector<int> zNum[maxn];
vector<int> fNum[maxn];
int kids[maxn];

class Solution {
private:
    void dfs(int u, int fa) {
        kids[u] = 1;
        if (G[u].size() == 1 && fa != -1) {
            ans[u] = 1;
            return;
        }
        for (auto v : G[u]) {
            if (v == fa)
                continue;
            dfs(v, u);
            kids[u] += kids[v];
        }
    }

    void dfs2(int u, int fa) {
        if (kids[u] - 1 < 3) {
            ans[u] = 1;
        }
        if (G[u].size() == 1 && fa != -1) {
            if (a[u] > 0) {
                zNum[u].push_back(a[u]);
            } else if (a[u] < 0) {
                fNum[u].push_back(a[u]);
            }
            return;
        }

        vector<int> tmpz;
        vector<int> tmpf;

        for (auto v : G[u]) {
            if (v == fa)
                continue;
            dfs2(v, u);
            for (auto x : zNum[v]) {
                tmpz.push_back(x);
            }
            for (auto x : fNum[v]) {
                tmpf.push_back(x);
            }
        }

        cout << "sort" << endl;
        for ( int i = 0 ; i < min(3, (int)tmpz.size()); i++ ) {
            zNum[u].push_back(tmpz[i]);
        }
        for ( int i = 0 ; i < min(2, (int)tmpf.size()); i++ ) {
            fNum[u].push_back(tmpf[i]);
        }

        if (a[u] > 0) {
            zNum[u].push_back(a[u]);
            sort(zNum[u].begin(), zNum[u].end(), greater<int>());
            while (zNum[u].size() > 3) {
                zNum[u].pop_back();
            }
        } else if (a[u] < 0) {
            fNum[u].push_back(a[u]);
            sort(fNum[u].begin(), fNum[u].end());
            while(fNum[u].size() > 2) {
                fNum[u].pop_back();
            }
        } 
        if (kids[u] - 1 >= 3) {
            ll res = 0 ;
            // 0 fushu
            if (zNum[u].size() >= 3) {
                ll tmp = 1;
                for (int i = 0 ; i < 3 ; i++) {
                    tmp *= zNum[u][i];
                }
                res = max(res, tmp);
            }

            // 2 fushu
            if (fNum[u].size() >= 2 && zNum[u].size() >= 1) {
                ll tmp = 1;
                for (int i = 0 ; i < 2 ; i++ ) {
                    tmp *= fNum[u][i];
                }
                for (int i = 0 ; i < 1 ; i++ ) {
                    tmp *= zNum[u][i];
                }
                res = max(res, tmp);
            }
            ans[u] = res;
        }

        
    }

public : 
    vector<long long> placedCoins(vector<vector<int>> &edges,
                                         vector<int> &cost) {
    int n = edges.size() + 1;
    for ( int i = 0 ; i <= n ; i++ ) {
        G[i].clear();
        fNum[i].clear();
        zNum[i].clear();
    }
    for (int i = 0; i < n; i++) {
        a[i] = cost[i];
    }
    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cout << "dfs1" << endl;
    dfs(0, -1);
    cout << "dfs2" << endl;
    dfs2(0, -1);
    vector<ll> ans2;
    for (int i = 0 ; i < n ; i++) {
        ans2.push_back(ans[i]);
    }
    cout << "-----" << endl;
    return ans2;
    }
}
;