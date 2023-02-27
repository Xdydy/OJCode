#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Solution {
private:
    int n, m;
    struct node {
        int x, y, t;
    };

public:
    int minimumTime(vector<vector<int>> &grid) {
        n = grid.size();
        m = grid[0].size();
        int dp[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = 1e6;
            }
        }
        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;
        dp[0][0] = 0;
        
        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < m ; j++ ) {
                int tmp = grid[i][j];
                if ( j > 0 ) {
                    if ( dp[i][j-1] + 1 >= tmp ) {
                        dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
                    } else {
                        if( (tmp - (dp[i][j-1]+1)) % 2 == 0 ) {
                            dp[i][j] = min(dp[i][j], tmp);
                        } else {
                            dp[i][j] = min(dp[i][j], tmp+1);
                        }
                    }
                }
                if (i > 0) {
                    if ( dp[i-1][j] + 1 >= tmp ) {
                        dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
                    } else {
                        if( (tmp - (dp[i-1][j]+1)) % 2 == 0 ) {
                            dp[i][j] = min(dp[i][j], tmp);
                        } else {
                            dp[i][j] = min(dp[i][j], tmp+1);
                        }
                    }
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};