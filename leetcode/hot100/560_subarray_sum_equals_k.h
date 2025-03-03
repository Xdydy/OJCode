#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(2e4 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);


class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        int sum = 0 ;
        map<int,int> mp;
        mp[0]++;
        int ans = 0;
        for (auto x : nums) {
            sum += x;
            int d = sum - k;
            if (mp.find(d) != mp.end()) {
                ans += mp[d];
            }
            mp[sum]++;
        }
        return ans;
    }
};