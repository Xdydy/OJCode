#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while(k--) {
            int minx = 1 << 30;
            for (auto x : nums) {
                minx = min(minx, x);
            }
            for (auto& x : nums) {
                if (x == minx) {
                    x *= multiplier;
                    break;
                }
            }
        }
        return nums;
    }
};