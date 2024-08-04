#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


class Solution {
private:
    int dp[505][505];
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                dp[i][j] = j-i;
            }
        }
        for (auto q : queries) {
            int u = q[0];
            int v = q[1];
            dp[u][v] = 1;
            for (int i = 0; i <= u; i++) {
                for (int j = v; j < n; j++) {
                    dp[i][j] = min(dp[i][j], dp[i][u] + dp[u][v] + dp[v][j]);
                }
            }
            ans.push_back(dp[0][n-1]);
        }
        return ans;
    }
};