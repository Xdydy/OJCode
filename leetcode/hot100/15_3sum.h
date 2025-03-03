#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        int last1 = 1 << 29;
        int last2 = 1 << 29;
        for (int i = 0; i < n; i++) {
            if (nums[i] == last1) {
                continue;
            }
            last1 = nums[i];
            last2 = 1 << 29;
            for (int j = i+1; j < n; j++) {
                if (nums[j] == last2) {
                    continue;
                }
                last2 = nums[j];
                int target = 0 - last1 - last2;
                // cout << last1 << " " << last2 << " " << target << endl;
                if (target < last2) {
                    continue;
                }
                int pos = upper_bound(nums.begin(), nums.end(), target) - nums.begin()-1;
                if (pos < n && target == nums[pos] && pos != j) {
                    vector<int> v= {last1, last2, target};
                    ans.push_back(v);
                }
            }
        }
        return ans;
    }
};