#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums.begin(), nums.end());
        for (int st=0, ed=k-1; st <= ed; st++, ed--) {
            swap(nums[st], nums[ed]);
        }
        for (int st=k, ed=n-1; st <= ed; st++, ed--) {
            swap(nums[st], nums[ed]);
        }
    }
};