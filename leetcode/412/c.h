#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

class Solution {
private:
    const ll mod = 1e9+7;
    struct num {
        ll val;
        int no;
        bool operator < (const num& o) const {
            if (val > o.val) {
                return true;
            } else if (val == o.val) {
                return no > o.no;
            } else {
                return false;
            }
        }
    };
    ll quick_pow(ll x, ll k) {
        ll res = 1;
        while(k) {
            if (k&1) res = res * x % mod;
            x = x * x % mod;
            k >>= 1;
        }
        return res;
    }
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if (multiplier == 1) {
            return nums;
        }
        vector<num> a;
        int n = nums.size();
        ll maxx = 0;
        for (int i = 0; i < nums.size(); i++) {
            a.push_back({nums[i], i});
            maxx = max(maxx, 1ll*nums[i]);
        }
        int cnt = 0;
        for (auto& x : a) {
            while (x.val * multiplier <= maxx) {
                x.val *= multiplier;
                cnt++;
            }
        }
        if (cnt >= k) {
            priority_queue<num> pq;
            for (int i = 0; i < nums.size(); i++) {
                pq.push({nums[i], i});
            }
            while(k--) {
                auto top = pq.top();
                pq.pop();
                top.val *= multiplier;
                pq.push(top);
            }
            vector<int> ans(n);
            while(pq.size()) {
                auto top = pq.top();
                pq.pop();
                ans[top.no] = top.val;
            }
            return ans;
        } else {
            k -= cnt;
            sort(a.begin(), a.end(), [](num u, num v){
                if (u.val < v.val) {
                    return true;
                } else if (u.val == v.val) {
                    return u.no < v.no;
                } else {
                    return false;
                }
            });
            cnt = k / n;
            int rest = k % n;
            for (int i = 0 ; i < n; i++) {
                if (i < rest) {
                    a[i].val *= quick_pow(multiplier, cnt+1);
                    a[i].val %= mod;
                } else {
                    a[i].val *= quick_pow(multiplier, cnt);
                    a[i].val %= mod;
                }
            }
            vector<int> ans(n);
            for (auto x : a) {
                ans[x.no] = x.val;
            }
            return ans;
        }
    }
};