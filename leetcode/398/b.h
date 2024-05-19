#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


class Solution {
private:
    int a[maxn];
    int pre1[maxn];
    int pre2[maxn];
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            a[i+1] = nums[i];
            a[i+1] &= 1;
        }
        pre1[0] = pre2[0] = 0;
        for (int i = 1; i <= n; i++) {
            pre1[i] = pre1[i-1];
            pre2[i] = pre2[i-1];
            if (i & 1) {
                pre1[i] += a[i];
            } else {
                pre2[i] += a[i];
            }
        }

        vector<bool> ans;
        for (auto query: queries) {
            int l = query[0];
            int r = query[1];
            l++,r++;
            int odd = pre1[r] - pre1[l-1];
            int even = pre2[r] - pre2[l-1];
            int len = r-l+1;
            int num1 = len/2;
            int num2 = len/2;
            if ((l&1) && (r&1)) {
                num1++;
            }
            if (l % 2 == 0 && r % 2 == 0 ) {
                num2++;
            }
            bool flag = false;
            if (odd == 0 && even == num2) {
                flag = true;
            }
            if (odd == num1 && even == 0 ) {
                flag = true;
            }
            ans.push_back(flag);
        }
        return ans;
    }
};