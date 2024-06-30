#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        for (auto &x : nums) {
            x %= 2;
        }
        int cnt1 = 0 , cnt0 = 0 ;
        for (auto x : nums ) {
            if (x) {
                cnt1++;
            } else {
                cnt0++;
            }
        }
        int cnt = 1 ;
        int cur = nums.front();
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] != cur) {
                cur ^= 1;
                cnt++;
            }
        }
        return max(max(cnt1,cnt0), cnt);
    }
};