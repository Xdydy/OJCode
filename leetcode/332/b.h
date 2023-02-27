#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        ll res = 0 ;
        int n = nums.size();
        for ( int i = 0 ; i < nums.size() ; i++ ) {
            int st = lower-nums[i];
            int ed = upper-nums[i];
            int pos1 = lower_bound(nums.begin(), nums.end(), st) - nums.begin();
            int pos2 = upper_bound(nums.begin(), nums.end(), ed) - nums.begin()-1;
            pos1 = max(pos1,i+1);
            pos2 = min(pos2,n-1);
            res += max(0,pos2-pos1+1);
        }
        return res;
    }
};