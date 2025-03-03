#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int sum = 0 ;
        int minx = 0;
        int ans = -(1<<29);
        for (auto num: nums) {
            sum += num;
            ans = max(ans, sum-minx);
            minx = min(sum, minx);
        }
        return ans;
    }
};