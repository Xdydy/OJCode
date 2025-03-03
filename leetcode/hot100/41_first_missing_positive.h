#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            while (x > 0 && x <= n && nums[x-1] != x) {
                swap(nums[i], nums[x-1]);
                x = nums[i];
            }
        }
        int ans = n+1;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i+1) {
                ans = i+1;
                break;
            }
        }
        return ans;
    }
};