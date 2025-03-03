#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        bool flag = 0;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i == j)
                    continue;
                if (nums[i] + nums[j] == target) {
                    res.push_back(i);
                    res.push_back(j);
                    flag = 1;
                    break;
                }
            }
            if (flag)
                break;
        }
        return res;
    }
};