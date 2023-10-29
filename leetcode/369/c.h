#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

ll dp[maxn];
class Solution {
public: 
    long long minIncrementOperations(vector<int>& nums, int k) {
        int n = nums.size();
        for ( int i = 1 ; i <= 3 ; i++ ) {
            int x = nums[i-1];
            dp[i] = max(0,k-x);
        }
        for ( int i = 4 ; i <= n ; i++ ) {
            dp[i] = 1ll<<60;
            int x = nums[i-1];
            for ( int j = i-1 ; j >= i-3 ; j-- ) {
                dp[i] = min(dp[i], dp[j] + max(0,k-x));
            }
        }
        return min(dp[n],min(dp[n-1],dp[n-2]));
    }
};