#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Solution {
private:
    int pre[maxn];
    int suf[maxn];
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        pre[0] = 1;
        int n = nums.size();
        for (int i = 1; i <= n; i++) {
            int x = nums[i-1];
            pre[i] = pre[i-1] * x;
        }
        suf[n+1] = 1;
        for (int i = n; i >= 1; i--) {
            int x = nums[i-1];
            suf[i] = suf[i+1] * x;
        }
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            ans.push_back(pre[i-1]*suf[i+1]);
        }
        return ans;
    }
};