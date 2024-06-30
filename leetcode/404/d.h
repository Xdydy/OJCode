#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e5+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


int n;
int dp1[maxn], dp2[maxn];
vector<int> G[maxn];

int max1, max2;

class Solution {
private:
    void dfs(int u ,int fa, int seq) {
        if (G[u].size() == 1 && fa != -1) {
            dp1[u] = dp2[u] = 1;
            return;
        }
        for (auto v : G[u]) {
            if (v == fa) continue;
            dfs(v,u,seq);
            if (dp1[v] > dp1[u]) {
                dp2[u] = dp1[u];
                dp1[u] = dp1[v];
            } else if ( dp1[v] > dp2[u] ) {
                dp2[u] = dp1[v];
            }
        }
        if (!seq) {
            max1 = max(max1, dp1[u]+dp2[u]+1);
        } else {
            max2 = max(max2, dp1[u]+dp2[u]+1);
        }
        dp1[u]++;
        dp2[u]++;
    }
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        n = edges1.size()+1;
        for (int i = 0 ; i < n; i++) {
            G[i].clear();
        }
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        for (auto edge: edges1) {
            int u = edge[0];
            int v = edge[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        max1 = 0;
        dfs(0,-1,0);

        n = edges2.size() +1;
        for (int i = 0; i < n; i++) {
            G[i].clear();
        }
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        
        for (auto edge: edges2) {
            int u = edge[0];
            int v = edge[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        max2 = 0;
        dfs(0,-1,1);

        int cnt1 = max1 / 2;
        int cnt2 = max2 / 2;
        int len = cnt1 + cnt2 + 1;
        return max(max(max1-1,max2-1), len);
    }
};