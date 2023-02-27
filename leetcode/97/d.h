#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e5+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (n*m==1) return 0;
        
        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < m ; j++ ) {
                int val = grid[i][j];
                if (val) {
                    if ( j+1 < m && grid[i][j+1] ) {
                        G[m*i+j].push_back(m*i+j+1);
                        G[m*i+j+1].push_back(m*i+j);
                    }
                    if ( i+1 < n && grid[i+1][j] ){
                        G[m*i+j].push_back(m*(i+1)+j);
                        G[m*(i+1)+j].push_back(m*i+j);
                    }
                }
            }
        }
        dfs_clock = 0 ;
        memset(iscut,0,sizeof(iscut));
        memset(pre,0,sizeof(pre));
        memset(low,0,sizeof(low));

        dfs(0,-1);
        bool flag = 1;
        for ( int i = 1 ; i < m*n-1 ; i++ ) {
            if (iscut[i]) {
                flag = 0;
                break;
            }
        }
        return !flag;
    }
private:
    vector<int> G[maxn];
    int dfs_clock;
    int pre[maxn], low[maxn];
    bool iscut[maxn];
    int dfs(int u, int fa) {
        int lowu = pre[u] = ++dfs_clock;
        int child = 0 ;
        for ( auto v : G[u] ) {
            if (!pre[v]) {
                child++;
                int lowv = dfs(v,u);
                lowu = min(lowu,lowv);
                if (lowv >= pre[u]) {
                    iscut[u] = 1;
                }
            } else if ( pre[v] < pre[u] && v != fa ) {
                lowu = min(lowu, pre[v]);
            }
        }
        if (fa < 0 && child == 1) iscut[u] = 0 ;
        low[u] = lowu;
        return lowu;
    }
};