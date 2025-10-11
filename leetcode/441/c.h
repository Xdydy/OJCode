#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);



class Solution {
private:
    struct Node {
        vector<pair<int,int>> a;
    }nodes[15];
    int dp[1005][1005];
public:
    int minZeroArray(vector<int> &nums, vector<vector<int>> &queries) {
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];
            for (int j = l; j <= r; j++) {
                nodes[j].a.push_back({i,val});
            }
        }
        int n = nums.size();
        int ans = 0;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            memset(dp, 0, sizeof(dp));
            int x = nums[i];
            if (x == 0) {
                continue;
            }
            dp[0][x] = 1;
            auto as = nodes[i].a;
            int asiz = as.size();
            int res = -1;
            for (int j = 1; j <= asiz; j++) {
                int pos = as[j-1].first;
                int val = as[j-1].second;
                for (int k = x; k >= 0; k--) {
                    dp[j][k] |= dp[j-1][k];
                    if (k - val >= 0) {
                        dp[j][k-val] |= dp[j-1][k];
                    }
                }
                if (dp[j][0] == 1) {
                    res = pos+1;
                    break;
                }
            }
            if (res == -1) {
                flag = false;
                break;
            } else {
                ans = max(ans, res);
            }
        }
        if (flag) {
            return ans;
        } else {
            return -1;
        }
    }
};