#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    long long maxScore(vector<int>& nums) {
        int n = nums.size();
        ll res = 0;
        for (int i = -1; i < n; i++) {
            int gcd = -1;
            ll lcm = -1;
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                if (gcd == -1) {
                    gcd = nums[j];
                }
                gcd = __gcd(gcd, nums[j]);
            }
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                if (lcm == -1) {
                    lcm = nums[j];
                } else {
                    int tmp = __gcd(lcm, 1ll*nums[j]);
                    lcm = lcm * nums[j] / tmp;
                }
            }
            res = max(res, lcm*gcd);
        }
        return res;
    }
};
