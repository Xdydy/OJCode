#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        bool flag = true;
        for ( int i = 0 ; i < n ; i+=3 ) {
            int a1 = nums[i];
            int a2 = nums[i+1];
            int a3 = nums[i+2];
            if (a3-a1 <= k) {
                vector<int> tmp = {a1,a2,a3};
                ans.push_back(tmp);
            } else {
                flag = false;
                break;
            }
        }
        if (!flag) {
            ans.clear();
        }
        return ans;
    }
};