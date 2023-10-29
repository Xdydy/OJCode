#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 


class Solution {
public:
    int a[maxn];
    int pre[maxn];
    int suf[maxn];
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        for ( int i = 1 ; i <= n ; i++ ) {
            a[i] = nums[i-1];
        }
        pre[0] = 1 << 30;
        for ( int i = 1 ; i <= n ; i++ ) {
            pre[i] = min(pre[i-1],a[i]);
        }
        suf[n+1] = 1<<30;
        for ( int i = n ; i >= 1 ; i-- ) {
            suf[i] = min(suf[i+1],a[i]);
        }

        int minx = 1 << 30;
        for ( int i = 1; i <= n ; i++ ) {
            if (pre[i-1] >= a[i] || suf[i+1] >= a[i] ) continue;
            minx = min(minx, pre[i-1] + a[i] + suf[i+1]);
        }
        if (minx == 1<<30) {
            minx = -1;
        }
        return minx;
    }
};