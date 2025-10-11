#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Solution {
public:
    vector<int> solveQueries(vector<int> &nums, vector<int> &queries) {
        vector<int> ans;
        map<int, vector<int>> pos;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            pos[x].push_back(i);
        }
        for (auto q : queries) {
            int x = nums[q];
            if (pos[x].size() == 1) {
                ans.push_back(-1);
            } else {
                int p = lower_bound(pos[x].begin(), pos[x].end(), q) - pos[x].begin();
                int tmp1 = 1 << 29;
                int tmp2 = 1 << 29;
                if (p+1 < pos[x].size()) {
                    tmp1 = pos[x][p+1]-q;
                } else {
                    tmp1 = n-(q-pos[x][0]);
                }

                if (p > 0) {
                    tmp2 = q-pos[x][p-1];
                } else {
                    tmp2 = n-(pos[x][pos[x].size()-1]-q);
                }
                ans.push_back(min(tmp1, tmp2));
            }
        }
        return ans;
    }
};