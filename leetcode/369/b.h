#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        ll s1 = 0, s2 = 0;
        int cnt1 = 0, cnt2 = 0;
        for (auto x : nums1) {
            s1 += x;
            if (!x) {
                cnt1++;
            }
        }      
        for ( auto x : nums2) {
            s2 += x;
            if (!x) {
                cnt2++;
            }
        }
        s1 += cnt1;
        s2 += cnt2;
        if (s1 < s2) {
            if (cnt1) {
                return s2;
            } else {
                return -1;
            }
        } else if (s1 == s2) {
            return s1;
        } else {
            if (cnt2) {
                return s1;
            } else {
                return -1;
            }
        }
    }
};


