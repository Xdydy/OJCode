#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> ans;
        for ( int i = 0 ; i < nums.size() ; i++ ) {
            if ( nums[i] == 0 ) continue;
            if ( i + 1 < nums.size() && nums[i] == nums[i+1] ) {
                ans.push_back(2*nums[i]);
                nums[i+1] = 0 ;
            } else {
                ans.push_back(nums[i]);
            }
        }
        while(ans.size() < nums.size() ) {
            ans.push_back(0);
        }
        return ans;
    }
};