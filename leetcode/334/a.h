#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        vector<int> ans;
        vector<int> l, r;
        int sum = 0 ;
        l.push_back(0);
        for ( int i = 1 ; i < nums.size() ; i++ ) {
            sum += nums[i-1];
            l.push_back(sum);
        }
        sum += nums.back();
        sum -= nums[0];
        r.push_back(sum);
        for ( int i = 1 ; i < nums.size() ; i++ ) {
            sum -= nums[i];
            r.push_back(sum);
        }
        for ( int i = 0 ; i < l.size() ; i++ ) {
            ans.push_back(abs(l[i]-r[i]));
        }
        return ans;
    }
};