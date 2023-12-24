#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


class Solution {
private:
    ll pre[maxn];
    ll a[maxn];
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        ll ans = -1;
        int n  = nums.size();
        for ( int i = 0 ; i < n ; i++ ) {
            a[i+1] = nums[i];
        }
        pre[0] = 0 ;
        for (int i = 1; i <= n ; i++ ) {
            pre[i] = pre[i-1] + a[i];
        }

        for (int i = 3; i <= n; i++ ) {
            if (pre[i-1] > a[i]) {
                ans = pre[i];
            } 
        }
        return ans;
    }
};