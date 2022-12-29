#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Solution {
public:
    long long maximumSubarraySum(vector<int> &nums, int k) {
        queue<pair<int, int>> q;
        memset(vis,0,sizeof(vis));
        ll maxx = 0;
        ll cur = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (q.empty()) {
                q.push({i, nums[i]});
                vis[nums[i]]++;
                if ( vis[nums[i]] == 1 ) cnt++;
                cur += nums[i];
            } else {
                auto top = q.front();
                if (top.first + k <= i) {
                    q.pop();
                    cur -= top.second;
                    // st.erase(top.second);
                    vis[top.second]--;
                    if (!vis[top.second] ) cnt--;
                }

                // st.insert(nums[i]);
                vis[nums[i]]++;
                if (vis[nums[i]] == 1) cnt++;
                cur += nums[i];
                q.push({i, nums[i]});
            }

            if (cnt == k) {
                maxx = max(maxx, cur);
            }
        }
        return maxx;
    }
private:
    int vis[maxn];
};