#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e5+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


class Solution {
private:
    int n ;
    vector<int> G[maxn];
    int siz[maxn];
    int ans = 0;
    void dfs(int u, int fa) {
        siz[u] = 1;
        if (G[u].size() == 1 && fa != -1) {
            ans++;
            return;
        }
        bool flag = 1;
        int cur = -1;
        for (auto v : G[u]) {
            if (v == fa) {
                continue;
            }
            dfs(v,u);
            siz[u] += siz[v];
            if (cur == -1) {
                cur = siz[v];
            } else {
                if (cur != siz[v]) {
                    flag = 0;
                }
            }
        }
        if (flag) {
            ans++;
        }
    }
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        for (auto edge: edges) {
            int u = edge[0];
            int v = edge[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(0,-1);
        return ans;
    }
};