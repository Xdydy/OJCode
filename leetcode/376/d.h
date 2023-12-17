#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

int n;
ll limit;
int a[maxn];
ll s[maxn];
class Solution {
private:
    bool judge(int st, int ed) {
        int len = ed - st + 1;
        int mid = st + len/2 -1;
        ll suf = s[ed] - s[mid];
        ll pre = s[mid] - s[st-1];
        ll res = suf-pre;
        if (len&1) {
            res -= a[mid+1];
        }
        return limit >= res;
    }
    bool check(int mid) {
        for ( int st = 1 ; st + mid - 1 <= n ; st++ ) {
            int ed = st + mid - 1;
            if (judge(st,ed)) {
                return true;
            }
        }
        return false;
    }

public:
    int maxFrequencyScore(vector<int> &nums, long long k) {
        n = nums.size();
        limit = k;
        for (int i = 1; i <= n; i++) {
            a[i] = nums[i - 1];
        }
        sort(a + 1, a + 1 + n);
        s[0] = 0 ;
        for ( int i = 1 ; i <= n ; i++ ) {
            s[i] = s[i-1] + a[i];
        }
        int left = 0,  right = n;
        while (left < right) {
            int mid = left + right + 1 >> 1;
            if (check(mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};