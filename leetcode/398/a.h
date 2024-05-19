#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if (nums.size() == 1) {
            return true;
        }
        bool ans = true;
        for (int i = 1; i < nums.size(); i++) {
            int x = nums[i];
            int y = nums[i-1];
            if ((x & 1) == (y&1) ) {
                ans = false;
                break;
            }
        }
        return ans;
    }
};