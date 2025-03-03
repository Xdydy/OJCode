#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deque<pair<int,int>> q;
        for (int i = 0; i < k; i++) {
            int x = nums[i];
            while(q.size() && q.back().first <= x) {
                q.pop_back();
            }
            q.push_back({x,i});
        }
        vector<int> ans;
        ans.push_back(q.front().first);
        int n = nums.size();
        for (int i = k; i < n; i++) {
            while(q.size() && q.front().second + k - 1 < i) {
                q.pop_front();
            }
            int x = nums[i];
            while(q.size() && q.back().first <= x) {
                q.pop_back();
            }
            q.push_back({x,i});
            ans.push_back(q.front().first);
        }
        return ans;
    }
};