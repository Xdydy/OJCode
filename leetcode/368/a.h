#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 



class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int minx = 1 << 30;
        int n = nums.size();
        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = i + 1 ; j < n ; j++ ) {
                for ( int k = j + 1 ; k < n ; k++ ) {
                    if (nums[i] < nums[j] && nums[k] < nums[j] ) {
                        minx = min(minx, nums[i] + nums[j] + nums[k]);
                    }
                }
            }
        }
        if (minx == 1<<30) {
            minx = -1;
        } 
        return minx;
    }
};