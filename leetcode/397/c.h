#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
private:
    int minx[1005][1005];
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i <= n; i++) {
            minx[i][0] = 1e6;
        }
        for (int i = 0; i <= m; i++) {
            minx[0][i] = 1e6;
        }
        for (int i = 1; i <= n ; i++) {
            for (int j = 1; j <= m; j++) {
                int x = grid[i-1][j-1];
                minx[i][j] = x;
                minx[i][j] = min(minx[i][j], minx[i-1][j]);
                minx[i][j] = min(minx[i][j], minx[i][j-1]);
            }
        }
        int maxx = -1e6;
        for (int i = 1; i <= n ; i++) {
            for (int j = 1; j <= m; j++) {
                int x = grid[i-1][j-1];
                int minv = min(minx[i][j-1], minx[i-1][j]);
                maxx = max(maxx, x - minv);
            }
        }
        return maxx;
    }
};