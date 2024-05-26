#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        int ans = 0;
        for (auto x : nums1) {
            for (auto y : nums2) {
                if (x % (y*k) == 0) {
                    ans ++;
                }
            }
        }
        return ans;
    }
};