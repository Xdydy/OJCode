#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Solution {
public:
    int maxSum(vector<int> &nums) {
        int maxx = -(1<<29);
        for (auto x: nums) {
            maxx = max(maxx, x);
        }
        if (maxx < 0) {
            return maxx;
        }
        int ans =0 ;
        set<int> st;
        for (auto x: nums) {
            if (x > 0 && st.find(x) == st.end()) {
                ans += x;
                st.insert(x);
            }
        }
        return ans;
    }
};