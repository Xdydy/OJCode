#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int left = 0;
        int right = height.size() - 1;
        int ans = 0;
        while (left < right) {
            int lh = height[left];
            int rh = height[right];
            if (lh < rh) {
                ans = max(ans, lh * (right - left));
                left++;
            } else {
                ans = max(ans, rh * (right - left));
                right--;
            }
        }
        return ans;
    }
};