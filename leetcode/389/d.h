#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (int)(1e6+10)
#define IOS ios::sync_with_stdio(0);
#define FFF freopen("out", "w", stdout); 

int n;
int a[maxn];
ll pre[maxn];
ll ppre[maxn];
class Solution {
private:
    bool judge(int pos, int mid, int tar) {
        int st = max(1,pos-mid);
        int ed = min(n,pos+mid);
        int sum = pre[ed] - pre[st-1];
        if (a[pos]) {
            sum --;
        }
        // if (a[pos-1]) {
        //     sum--;
        // }
        // if (a[pos+1]) {
        //     sum--;
        // }
        return sum >= tar;
    }
public:
    long long minimumMoves(vector<int>& nums, int k, int maxChanges) {
        ll minx = 1ll<<60;
        n = nums.size();
        for (int i = 0; i < n ; i++ ) {
            a[i+1] = nums[i];
        }
        a[0] = 0;
        a[n+1] = 0;
        pre[0] = 0;
        ppre[0] = 0;
        for (int i = 1; i <= n ; i++) {
            pre[i] = pre[i-1] + a[i];
            ppre[i] = ppre[i-1];
            if (a[i]) {
                ppre[i] += i;
            }
        }

        for (int i = 1; i <= n; i++) {
            ll res = 0;
            int tar = k;
            if (a[i]) {
                tar--;
            }
            if (tar <= 0) {
                minx = min(minx, res);
                continue;
            } 
            if (a[i-1]) {
                tar--;
                res++;
            }
            if (tar <= 0) {
                minx = min(minx, res);
                continue;
            }
            if (a[i+1]) {
                tar--;
                res++;
            }
            if (tar <= 0) {
                minx = min(minx, res);
                continue;
            }

            if (tar <= maxChanges) {
                res += 2*tar;
            } else {
                tar = k;
                if (a[i]) tar--;
                res = 0;
                res += 2*maxChanges;
                tar -= maxChanges;
                int left = 0, right = n;
                while(left < right) {
                    int mid = left + right >> 1;
                    if (judge(i,mid,tar)) {
                        right = mid;
                    } else {
                        left = mid+1;
                    }
                }
                int len = left;
                int ed = min(n,i+len);
                int st = max(1,i-len);
                int cnt1 = pre[ed] - pre[i];
                int cnt2 = pre[i] - pre[st-1];
                res += ppre[ed] - ppre[i] - 1ll*i*cnt1;
                res += 1ll*i*cnt2-(ppre[i] - ppre[st-1]);

            }
            minx = min(res,minx);
        }
        return minx;
    }
};