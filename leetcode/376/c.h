#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e5 + 10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout);

ll a[maxn];
ll pre[maxn], suf[maxn];
class Solution {
private:
    int nearestNum(int x) {
        vector<int> v;
        v.clear();
        while (x) {
            v.push_back(x % 10);
            x /= 10;
        }
        reverse(v.begin(), v.end());
        int n = v.size();
        int st = 0, ed = n - 1;
        while (st < ed) {
            if (v[ed] == 10) {
                v[ed] = 0;
                v[ed - 1]++;
            }
            if (v[st] >= v[ed]) {
                v[ed] = v[st];
            } else {
                v[ed - 1]++;
                v[ed] = v[st];
            }
            st++, ed--;
        }

        if (st == ed && v[st] == 10) {
            v[st] = 0;
            for (int i = st - 1; i >= 0; i--) {
                v[i]++;
                if (v[i] >= 10) {
                    v[i] = 0;
                } else {
                    v[i]++;
                    break;
                }
            }
            for (int i = 1; ed + i < n; i++) {
                v[ed + i] = v[st - i];
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            res = res * 10 + v[i];
        }
        return res;
    }

    int lowernear(int x) {
        vector<int> v;
        v.clear();
        while (x) {
            v.push_back(x % 10);
            x /= 10;
        }
        reverse(v.begin(), v.end());
        int n = v.size();
        int st = 0, ed = n - 1;
        while (st < ed) {
            if (v[ed] < 0) {
                v[ed] = 9;
                v[ed - 1]--;
            }
            if (v[st] <= v[ed]) {
                v[ed] = v[st];
            } else {
                v[ed - 1]--;
                v[ed] = v[st];
            }
            st++, ed--;
        }

        if (st == ed && v[st] < 0) {
            v[st] = 9;
            for (int i = st - 1; i >= 0; i--) {
                v[i]--;
                if (v[st] < 0) {
                    v[st] = 9;
                } else {
                    v[st]--;
                    break;
                }
            }
            for (int i = 1; ed + i < n; i++) {
                v[ed + i] = v[st - i];
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            res = res * 10 + v[i];
        }
        return res;
    }

public:
    long long minimumCost(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        memset(pre, 0, sizeof(pre));
        memset(suf, 0, sizeof(suf));
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++) {
            a[i + 1] = nums[i];
        }
        pre[1] = 0;
        for (int i = 2; i <= n; i++) {
            pre[i] = pre[i - 1] + (a[i] - a[i - 1]) * (i - 1);
        }
        suf[n] = 0;
        for (int i = n - 1; i >= 1; i--) {
            suf[i] = suf[i + 1] + (a[i + 1] - a[i]) * (n - i);
        }
        // for ( int i = 1 ; i <= n ; i++ ) {
        //     cout << pre[i] << " " ;
        // }
        // cout << endl;
        // for ( int i = 1 ; i <= n ; i++ ) {
        //     cout << suf[i] << " " ;
        // }
        // cout << endl;
        ll ans = (1ll << 60);
        for (int i = 1; i < n; i++) {
            int x = nearestNum(a[i]);
            // cout << "x: " << x << endl;
            if (x <= a[i+1]) {
                ll res = 0;
                res += pre[i] + (x - a[i]) * i;
                res += suf[i + 1] + (a[i + 1] - x) * (n - i);
                ans = min(ans, res);
            }
        } 
        for ( int i = n; i > 1 ; i--) {
            int x = lowernear(a[i]);
            if (x >= a[i-1]) {
                ll res = 0 ;
                res += suf[i] + (a[i]-x) * (n-i+1);
                res += pre[i-1] + (x-a[i-1]) * (i-1);
                ans = min(ans, res);
            }
        }
        int x = nearestNum(a[n]);
        ll res = pre[n] + (x - a[n]) * n;
        ans = min(ans, res);
        x = lowernear(a[1]);
        res = suf[1] + (a[1] - x) * n;
        ans = min(ans,res);
        return ans;
    }
};