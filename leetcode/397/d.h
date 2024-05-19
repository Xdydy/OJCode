#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Solution {
private:
    int n;
    int a[15];
    int minx = 1005;
    int res[15];
    int tmp[15];
    bool vis[15];

    void dfs(int index, int sum) {
        if (sum >= minx) {
            return;
        }
        if (index == n - 1) {
            sum += abs(tmp[index]-a[tmp[0]]);
            if (sum < minx) {
                minx = sum;
                for (int i = 0; i < n; i++) {
                    res[i] = tmp[i];
                }
            }
            return;
        }
        for (int i = 0; i < n; i++) {
            if (vis[i])
                continue;
            tmp[index + 1] = i;
            vis[i] = 1;
            dfs(index + 1, sum + abs(tmp[index] - a[tmp[index+1]]));
            vis[i] = 0;
        }
    }

public:
    vector<int> findPermutation(vector<int> &nums) {
        n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            a[i] = nums[i];
        }
        
        for (int i = 0; i < n; i++) {
            memset(vis, 0, sizeof(vis));
            vis[i] = 1;
            tmp[0] = i;
            dfs(0, 0);
            vis[i] = 0;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(res[i]);
        }
        return ans;
    }
};