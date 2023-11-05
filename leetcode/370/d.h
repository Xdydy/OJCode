#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e5 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

ll c[maxn];
ll a[maxn];
int stk[maxn];
int lowbit(int x) {
    return x & (-x);
}
ll qry(int x) {
    ll res = 0 ;
    while(x) {
        res = max(res, c[x]);
        x -= lowbit(x);
    }
    return res;
}

void upd(int x, ll val) {
    while(x < maxn) {
        c[x] = max(c[x], val);
        x += lowbit(x);
    }
}

class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int> &nums) {
        int n = nums.size();
        for (int i = 1 ; i <= n; i++ ) {
            a[i] = nums[i-1];
            stk[i] = nums[i-1] - i;
        }
        for (int i = 1; i <= n; i++ ) {
            c[i] = -(1ll<<60);
        }

        sort(stk+1,stk+1+n);
        ll ans = -(1ll<<60);
        int m = unique(stk+1, stk+1+n) - stk;
        for ( int i = 1 ; i <= n ; i++ ) {
            int pos = lower_bound(stk+1,stk+1+n, a[i]-i) - stk;
            ll val = qry(pos) + a[i];
            upd(pos,val);
            ans = max(ans, val);
        }
        return ans;
    }
};