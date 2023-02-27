#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Solution {
public:
    int maxCount(vector<int> &b, int n, int maxSum) {
        memset(vis, 0, sizeof(vis));
        for (auto x : b) {
            vis[x] = 1;
        }
        int ans = 0;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                if (sum + i <= maxSum) {
                    ans++;
                    sum += i;
                } else {
                    break;
                }
            }
        }
        return ans;
    }

private:
    bool vis[maxn];
};