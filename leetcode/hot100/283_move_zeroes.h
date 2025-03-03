#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int n = nums.size();
        vector<int> v;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                v.push_back(i);
            }
        }
        int cnt = 0;
        for (auto x: v) {
            if (x != cnt) {
                swap(nums[x], nums[cnt]);
            }
            cnt++;
        }
    }
};