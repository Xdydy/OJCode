#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
ll a[maxn];
class Solution {
private:
    ll removeLeft() {
        int pos = 1;
        for (int i = n-1; i >= 1; i--) {
            if (a[i] >= a[i+1]) {
                pos = i;
                break;
            } 
        }
        int len = n-pos;
        return len;
    }

    ll removeRight() {
        int pos = n;
        for (int i = 2; i <= n; i++ ) {
            if (a[i] <= a[i-1]) {
                pos = i;
                break;
            } 
        }
        int len = pos-1;
        return len;
    }
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        n = nums.size();
        for (int i = 0 ; i < n; i++ ) {
            a[i+1] = nums[i];
        }
        a[n+1] = 1ll<<60;
        ll ans = 1;
        ans += removeLeft();
        ans += removeRight();
        int l = 1, r = n;
        for (int i = 2; i <= n ; i++ ) {
            if (a[i] > a[i-1]) {
                l = i;
            } else {
                break;
            }
        }
        for (int i = n-1; i >= 1; i--) {
            if (a[i] < a[i+1]) {
                r = i;
            } else {
                break;
            }
        }

        if (l > r) {
            int len = n-2;
            ans += 1ll*len*(len-1)/2;
            ans += len;
        } else{
            for (int i = l; i >= 1; i--) {
                int pos = upper_bound(a+r, a+1+n, a[i]) - a;
                if (pos == n+1) {
                    continue;
                }
                ans += (n-1)-(pos-1)+1;
            }
        }
        return ans;
    }
};