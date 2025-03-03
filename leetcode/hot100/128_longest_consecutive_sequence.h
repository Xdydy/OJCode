#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        map<ll,int> mp;
        for (auto x: nums) {
            mp[x]++;
        }
        int ans = 0;
        bool flag = 0;
        int last = 0;
        int cur = 0;
        for (auto [k,v]: mp) {
            if (!flag) {
                last = k;
                flag = 1;
                cur = 1;
                ans = max(ans, cur);
            } else {
                if (k == last+1) {
                    cur++;
                    ans = max(cur, ans);
                    last = k;
                } else {
                    cur = 1;
                    ans = max(ans, cur);
                    last = k;
                }
            }
        }
        return ans;
    }
};