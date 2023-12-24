#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
private:
    bool judge(vector<int> v) {
        if (v.size() <= 1) return true;
        for (int i = 1 ; i < v.size() ; i++ ) {
            if (v[i] <= v[i-1]) {
                return false;
            }
        }
        return true;
    }
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int ans = 0 ;
        for (int i = 0; i < n ; i++ ) {
            for ( int j = i; j < n ; j++ ) {
                vector<int> tmp;
                for (int k = 0; k < i; k++ ) {
                    tmp.push_back(nums[k]);
                }
                for (int k = j+1; k < n; k++ ) {
                    tmp.push_back(nums[k]);
                }
                if (judge(tmp)) {
                    
                    ans++;
                }
            }
        }
        return ans;
    }
};